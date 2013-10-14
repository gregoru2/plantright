<?php

/**
 * Mimics sf_node module.
 */

/**
 * Implementation of hook_nodeapi.
 * See sf_node_nodeapi().
 */
function plantright_sf_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  switch ($op) {
    case 'load':
      $node->plantright_sf = plantright_sf_api_id_load('node', $node->nid);
      break;
    case 'delete':
      // TODO? Don't really want auto delete from salesforce.
      break;
    case '':
      break;
    case 'update':
    case 'insert':
      // When importing *from* Salesforce, don't export *back* to Salesforce.
      if (isset($node->plantright_sf_node_skip_export)) {
        break;
      }

      // If this is an update, and the node already has a salesforce mapping,
      // try to load it. If the load fails, we need to fetch the appropriate
      // fieldmap. Either way, we're upserting the salesforce record.
      if ($node->nid) {
        $maps = plantright_sf_api_id_load('node', $node->nid);
      }

      $salesforce_handled = salesforce_api_id_load('node', $node->nid);

      // No mappings to this node. Get the mappings that it should have.
      if (empty($maps)) {
        $maps = salesforce_api_salesforce_field_map_load_by(array('drupal' => 'node_' . $node->type));
        foreach($maps as $key => $map) {
          if ($map->name ==  $salesforce_handled->name) {
            unset($maps[$key]);
          }
        }

        if (empty($maps)) {
          // No maps. So stop.
          break;
        }
      }

      foreach ($maps as $map) {
        $auto_create = $map->automatic & SALESFORCE_AUTO_SYNC_CREATE;
        $auto_update = $map->automatic & SALESFORCE_AUTO_SYNC_UPDATE;
        if ((!$auto_create && $op == 'insert')
            || (!$auto_update && $op == 'update')) {
          unset($maps[$map->name]);
        }
      }

      // Remove the first map, because salesforce uses it.
      //array_shift($maps);

      if (empty($maps)) {
        break;
      }
//dpm($maps, 'maps');
      foreach ($maps as $map) {

        // Finally, export the node to Salesforce.
        try {
          plantright_sf_node_export($node, $map->name, $map->sfid);
        }
        catch (Exception $e) {
          salesforce_api_log(SALESFORCE_LOG_SOME, 'Exception while attempting to export node: ' . $e->getMessage(), array(), WATCHDOG_ERROR, l('node ' . $node->nid, 'node/' . $node->nid));
        }
      }

      break;
  }
}

/**
 * Exports a node to Salesforce using the specified fieldmap and stores the
 *   ID of the Salesforce object for the node.
 *
 * @param $node
 *   The node object to export (also accepts a numeric node id).
 * @param $fieldmap
 *   The index of the fieldmap to use to create the export object.
 * @param $sfid
 *   The Salesforce ID of the object you want to update.  If left NULL, a new
 *     object will be created at Salesforce.
 * @return
 *   TRUE or FALSE indicating the success of the operation.
 */
function plantright_sf_node_export($node, $name, $sfid = NULL) {
  // Attempt to connect to Salesforce.
  $sf = salesforce_api_connect();
  if (!$sf) {
    // Let modules react to a failure to export this node.
    module_invoke_all('salesforce_api_export_connect_fail', is_object($node) ? $node->nid : $node, $name, $sfid);
    if (user_access('administer salesforce')) {
      drupal_set_message(t('Unable to connect to Salesforce using <a href="!url">current credentials</a>.', array('!url' => url(SALESFORCE_PATH_ADMIN))));
    }
    return FALSE;
  }

  // Load the node if we didn't get a full object.
  if (is_numeric($node)) {
    $node = node_load($node);
  }

  // Load the fieldmap so we can get the object name.
  $map = salesforce_api_fieldmap_load($name);

  // Look for any matching records which we might want to update instead of creating duplicates.
  if (empty($sfid)) {
    $matches = salesforce_api_search_for_duplicates('export', 'node', $node, $name);
    if (!empty($matches)) {
      $sfid = reset($matches);
      $node->plantright_sf = array('sfid' => $sfid, 'name' => $name);
      plantright_sf_api_id_save('node', $node->nid, $sfid, $name, 'export');
      //salesforce_api_id_save('node', $node->nid, $sfid, $name, 'export');
      $node = node_load($node->nid, NULL, TRUE);
    }
    if (empty($node)) {
      $node = (object)array();
    }
  }
  // Create an object for export based on the specified fieldmap.
  $object = salesforce_api_fieldmap_export_create($name, $node);
  $object->Id = $sfid;

  foreach (module_implements('salesforce_api_pre_export') as $module) {
    $function = $module . '_salesforce_api_pre_export';
    $continue = $function($object, $map, $node->nid);
    if ($continue === FALSE) {
      return;
    }
  }

  // If any modules altered the fieldmap, ensure that the new fieldmap name
  // is used for the rest of the export.
  if ($map->name != $name) {
    $name = $map->name;
  }
//dpm($map, 'map');
//dpm($object, 'object');
  try {
    $response = $sf->client->upsert('Id', array($object), $map->salesforce);
  }
  catch (Exception $e) {
    salesforce_api_log(SALESFORCE_LOG_SOME, 'Exception while attempting to upsert node: %msg <pre>%e</pre>', array('%msg' => $e->getMessage(), '%e' => print_r($e, TRUE)), WATCHDOG_ERROR, l('node ' . $node->nid, 'node/' . $node->nid));
  }

  // Check to see if response is an array of objects
  if (is_array($response) && count($response) > 0) {
    $response = $response[0];
  }

  // If we got errors, handle them before proceeding
  if (is_object($response->errors)) {
    // If we got "Entity is deleted" and we're configured to unlink and upsert,
    // do it.
    if ($response->errors->statusCode == 'ENTITY_IS_DELETED'
    // ENTITIY_IS_DELETED error is also returned if any lookup-field values
    // reference deleted Salesforce Records. If the fields property references
    // "Id" or if fields is empty, then we know that the the primary record was
    // deleted. Otherwise we don't have a good way to react.
    && ($response->errors->fields == 'Id' || empty($response->errors->fields))
    && SALESFORCE_DELETED_POLICY_UPSERT == variable_get('salesforce_api_entity_deleted_policy', SALESFORCE_DELETED_POLICY_UPSERT)) {
      // If the entity is deleted, unlink ALL the linked drupal objects.
      plantright_sf_api_id_unlink(array('sfid' => $object->Id));
      //salesforce_api_id_unlink(array('sfid' => $object->Id));
      $node->plantright_sf->sfid = $object->Id = NULL;

      // Look for any matching records which we might want to update instead of
      // creating duplicates. Assume that salesforce_api_search_for_duplicates()
      // will never return a deleted record.
      $matches = salesforce_api_search_for_duplicates('export', 'node', $node, $name);
      if (!empty($matches)) {
        $sfid = reset($matches);
        $node->plantright_sf->sfid = $sfid;
      }

      salesforce_api_log(SALESFORCE_LOG_SOME, 'Salesforce entity deleted. Attempting to unlink and upsert. <pre>%response</pre>', array('%response' => print_r($response, 1)), WATCHDOG_ERROR, l('node ' . $node->nid, 'node/' . $node->nid));
      try {
        $response = $sf->client->upsert('Id', array($object), $map->salesforce);
      }
      catch (Exception $e) {
        salesforce_api_log(SALESFORCE_LOG_SOME, 'Exception while attempting to upsert node: %msg <pre>%e</pre>', array('%msg' => $e->getMessage(), '%e' => print_r($e, TRUE)), WATCHDOG_ERROR, l('node ' . $node->nid, 'node/' . $node->nid));
      }
    }
  }
//dpm($response, 'RESPONSE');
  // If the export was successful...
  if ($response->success) {
    // Store the Salesforce ID for the node and return TRUE.
    plantright_sf_api_id_save('node', $node->nid, $response->id, $name, 'export');
    //salesforce_api_id_save('node', $node->nid, $response->id, $name, 'export');
  }
  else {
    // Otherwise log the error and return FALSE.
    if (user_access('administer salesforce')) {
      if (function_exists('dpm')) {
      }
      else {
        drupal_set_message(t('Salesforce Suite export error: <pre>%response</pre>', array('%response' => print_r($response, 1))), 'error');
      }
    }
    salesforce_api_log(SALESFORCE_LOG_SOME, 'Salesforce returned an unsuccessful response: <pre>%response</pre>', array('%response' => print_r($response, 1)), WATCHDOG_ERROR, l('node ' . $node->nid, 'node/' . $node->nid));
  }
  module_invoke_all('salesforce_api_post_export', $object, $map, $node->nid, $response);
  return $response->success;
}

function plantright_sf_node_salesforce_form(&$form_state, $node) {
  
  ///TODO: FORM NOT WORKING
 
  
   
  // Fail out if the node didn't exist!
  if (!$node->nid) {
    drupal_not_found();
  }

  if (isset($form_state['storage']['confirm'])) {
    // ALSO do $form definition here. Your final submit handler (after user clicks Yes, I Confirm) will only see $form_state info defined here. Form you create here passed as param1 to confirm_form
    $form['node'] = array('#type' => 'value', '#value' => $node);
    return confirm_form($form, 'Are you sure you want to unlink this node from Salesforce?', 'node/' . $node->nid . '/salesforce', 'Unlinking this object will remove the connection between the Drupal object and the Salesforce record. This action will not delete the Drupal object or the Salesforce record. This cannot be undone.', 'Unlink', 'Cancel'); //Had better luck leaving off last param 'name'
  }

  // Set the node page title.
  drupal_set_title(check_plain($node->title));

  $form = array();

  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );

  // If we only map 2, this might be good enough. Think we might map more
  $node->plantright_sf = $node->plantright_sf[0];
  
  if ($node->plantright_sf->sfid) {
    // Retrieve the object from Salesforce.
    $sf_data = salesforce_api_retrieve(array($node->plantright_sf->sfid), $node->plantright_sf->name);
    // Check to see if sf_data is an array of objects
    if (is_array($sf_data) && count($sf_data) > 0) {
      $sf_data = $sf_data[0];
    }
    // If $sf_data is empty, we assume the record is deleted. retrieve() does
    // not return the ENTITY_IS_DELETED error that upsert() does.
    if (!$sf_data && SALESFORCE_DELETED_POLICY_UPSERT == variable_get('salesforce_api_entity_deleted_policy', SALESFORCE_DELETED_POLICY_UPSERT)) {
      drupal_set_message(t('Unable to retrieve Salesforce data for record !sfid. Drupal and Salesforce records have been unlinked.', array('!sfid' => $node->plantright_sf->sfid)), 'warning');
      // Unlink the object
      salesforce_api_id_unlink(array('oid' => $node->nid, 'name' => $node->plantright_sf->name));
      $node = node_load($node->nid, NULL, TRUE);
    }
    elseif (!$sf_data) {
      drupal_set_message(t('Unable to retrieve Salesforce data for record !sfid.', array('!sfid' => $node->plantright_sf->sfid)), 'warning');
    }
  }

  // Display an export button if the node hasn't been exported before.
  if (!$node->plantright_sf->sfid) {
    $form['export'] = array(
      '#type' => 'fieldset',
      '#title' => t('Export node to Salesforce'),
      '#description' => t('This node may be exported to Salesforce using any fieldmap listed below.'),
    );

    // Add the export form.
    $form['export']['fieldmap'] = array(
      '#type' => 'select',
      '#title' => t('Export fieldmap'),
      '#options' => salesforce_api_fieldmap_options('node_'. $node->type),
    );

    $form['export']['manual_linking'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Manual linking'),
    );

    $form['export']['manual_linking']['sfid'] = array(
      '#type' => 'textfield',
      '#title' => t('Salesforce ID'),
      '#description' => t('If this node already has a corresponding object
      in Salesforce, enter the Salesforce ID to manually link the entities.
      Salesforce record will be linked using the fieldmap selected above.
      <strong>Please ensure that the Salesforce object type matches that of
      fieldmap selected above.</strong>.<br /><br /><em>Create Link</em> will
      link two Drupal and Salesforce records, leaving field values unchanged.
      <br /><em>Export Node</em> will upsert the Drupal record, inserting or
      updating any Salesforce record as necessary.'),
      '#size' => 18,
      '#maxlength' => 18,
    );

    $form['export']['manual_linking']['link'] = array(
      '#type' => 'submit',
      '#value' => t('Create Link'),
    );

    $form['export']['export_node'] = array(
      '#type' => 'submit',
      '#value' => t('Export node'),
    );
  }
  else {
    // Otherwise add synchronization information.
    $form['sfid'] = array(
      '#type' => 'value',
      '#value' => $node->plantright_sf->sfid,
    );
    $form['fieldmap'] = array(
      '#type' => 'value',
      '#value' => $node->plantright_sf->name,
    );

    // Load the fieldmap data.
    $map = salesforce_api_fieldmap_load($node->plantright_sf->name);
    $sf_object_definition = salesforce_api_fieldmap_objects_load('salesforce', $map->salesforce);
    $export_data = salesforce_api_fieldmap_export_create($node->plantright_sf->name, $node);

    $header = array(t('Field name'), t('Drupal @type value', array('@type' => salesforce_api_fieldmap_object_label('drupal', $map->drupal))), t('Salesforce @type value', array('@type' => salesforce_api_fieldmap_object_label('salesforce', $map->salesforce))));
    $rows = array();

    foreach ($map->fields as $sf_fieldname => $drupal_fieldname) {
      $rows[] = array(
        $sf_object_definition['fields'][$sf_fieldname]['label'],
        $export_data->$sf_fieldname,
        $sf_data->$sf_fieldname,
      );
    }

    $form['mapped'] = array(
      '#type' => 'fieldset',
      '#title' => t('Mapped field values'),
      '#description' => t('<a href="!url">Edit this fieldmap</a>.', array('!url' => url(SALESFORCE_PATH_FIELDMAPS .'/'. $node->plantright_sf->name .'/edit'))),
    );
    $form['mapped']['fieldmap_values'] = array(
      '#value' => theme('table', $header, $rows),
    );

    $form['mapped']['export_values'] = array(
      '#type' => 'submit',
      '#value' => t('Export changes to Salesforce'),
      '#attributes' => array('class' => 'sf-confirm'),
    );
    $form['mapped']['import_values'] = array(
      '#type' => 'submit',
      '#value' => t('Import changes from Salesforce'),
      '#attributes' => array('class' => 'sf-confirm'),
    );
    $form['mapped']['unlink'] = array(
      '#type' => 'submit',
      '#value' => t('Unlink from Salesforce object...'),
      '#attributes' => array('class' => 'sf-confirm'),
    );

    // Create a table for the unmapped fields.
    $header = array(t('Field name'), t('Salesforce @type value', array('@type' => salesforce_api_fieldmap_object_label('salesforce', $map->salesforce))));
    $rows = array();

    foreach ((array) $sf_data as $key => $value) {
      if (!isset($map->fields[$key]) && isset($sf_object_definition['fields'][$key])) {
        $rows[] = array(
          $sf_object_definition['fields'][$key]['label'],
          $value,
        );
      }
    }

    if (count($rows) > 0) {
      $form['unmapped'] = array(
        '#type' => 'fieldset',
        '#title' => t('Unmapped fields'),
        '#description' => t('These fields are available on Salesforce but are not currently mapped through the fieldmap used for this user.'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['unmapped']['unmmaped_fields'] = array(
        '#value' => theme('table', $header, $rows),
      );
    }

    $rows = array();

    foreach (salesforce_api_fieldmap_system_fields() as $key => $value) {
      $rows[] = array(
        $value['label'],
        $sf_data->$key,
      );
    }

    $form['system'] = array(
      '#type' => 'fieldset',
      '#title' => t('System fields'),
      '#description' => t('These fields provide additional system information about the Salesforce object but cannot be exported to Salesforce.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['system']['system_fields'] = array(
      '#value' => theme('table', $header, $rows),
    );

    $form['raw'] = array(
      '#type' => 'fieldset',
      '#title' => t('Raw data'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['raw']['data'] = array(
      '#value' => '<pre>'. print_r($sf_data, TRUE) .'</pre>',
    );
  }

  return $form;
}

function plantright_sf_node_salesforce_form_submit($form, &$form_state) {
  switch ($form_state['values']['op']) {
    // Export the node to Salesforce.
    case t('Export node'):
    case t('Export changes to Salesforce'):
      if (sf_node_export($form_state['values']['nid'], $form_state['values']['fieldmap'], $form_state['values']['sfid'])) {
        drupal_set_message(t('Changes successfully exported to Salesforce.'));
      }
      else {
        drupal_set_message(t('An error occurred while exporting the changes to Salesforce. Check the watchdog for more information.'), 'error');
      }
      break;

    // Import changes from Salesforce.
    case t('Import changes from Salesforce'):
      if (sf_node_import($form_state['values']['sfid'], $form_state['values']['fieldmap'], $form_state['values']['nid'])) {
        drupal_set_message(t('The node has been updated with values from Salesforce.'));
      }
      else {
        drupal_set_message(t('An error occurred while importing the changes from Salesforce. Check the watchdog for more information.'), 'error');
      }
      break;
    case $form_state['values']['link']:
      if (!is_sfid($form_state['values']['sfid'])) {
        drupal_set_message(t('Invalid SFID provided.'), 'error');
        break;
      }
      salesforce_api_id_save('node', $form_state['values']['nid'], $form_state['values']['sfid'], $form_state['values']['fieldmap'], 'link');
      break;
    case $form_state['values']['unlink']:
    case t('Unlink'):
      if (!isset($form_state['storage']['confirm'])) {
        $form_state['storage']['confirm'] = TRUE;
        $form_state['rebuild'] = TRUE;
      }
      else {
        unset($form_state['storage']['confirm']);
        $node = $form_state['values']['node'];
        salesforce_api_id_unlink(array('oid' => $node->nid, 'name' => $node->plantright_sf->name));
        drupal_set_message(t('The node !nid has been unlinked from Salesforce !sfid.', array('!nid' => $node->nid, '!sfid' => $node->plantright_sf->sfid)));
      }
      break;
  }
}
