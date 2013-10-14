<?php

/**
 * Mimics functionality salesforce_api module but allows for multiple mappings.
 */

/**
 * Implements hook_salesforce_api_id_save_alter().
 */
function plantright_sf_salesforce_api_id_save_alter($drupal_type, $oid, $sfid, $name, $op_type) {
  $existing_record = db_fetch_array(db_query("SELECT oid, drupal_type, name, sfid, last_import, last_export, created FROM {plantright_sf_object_map} WHERE drupal_type = '%s' AND oid = %d AND sfid = %d", $drupal_type, $oid, $sfid));
  if ($existing_record) {
    $record = new stdClass();
    $record->drupal_type = $drupal_type;
    $record->name = $name;
    $record->oid = (int)$oid;
    // Set the last_import/last_export field depending on what type of operation
    // is being performed
    ($op_type == 'export') ? $record->last_export = time() : $record->last_import = time();
    $record->sfid = $sfid;
    
    if (drupal_write_record('salesforce_object_map', $record, array('drupal_type', 'oid'))) {
        salesforce_api_log(SALESFORCE_LOG_ALL, 'PR On !op, successfully re-saved mapping between Drupal !type !oid and Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name));
      }
      else {
        // Log an error if we failed to re-save the mapping
        salesforce_api_log(SALESFORCE_LOG_ALL, 'PR On !op, failed to re-save mapping between Drupal !type !oid with Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name), WATCHDOG_ERROR);
      }
    // Return false so it doesn't continue.
    return FALSE;
  }
}

/**
 * Copy of salesforce_api_id_load() but retrieves more than one from custom
 * PR table.
 */
function plantright_sf_api_id_load($type, $id) {
  //$type = 'pr_' . $type; // add prefix to the type of sf doesn't select these.
  // Query the main ID table for the associated data.
  $result = db_query("SELECT sfid, name FROM {plantright_sf_object_map} WHERE drupal_type = '%s' AND oid = %d", $type, $id);
  $data = array();

  // Return an empty array if no data was found.
  if (count($result) == 0) {
    $data = NULL;
  }
  else {
    while ($row = db_fetch_object($result)) {
      // Otherwise return the Salesforce object type and ID.
      $data[] = $row;
    }
  }
  return $data;
}

/**
 * Saves the Salesforce ID and fieldmap index of a Drupal object.
 * This function will store the timestamp of creation of the object mapping
 * It will also store data about when the object was last exported to Salesforce
 * or imported to Drupal.
 * *
 * @param string$drupal_type
 *   The type of the Drupal object you are requesting data for; node or user.
 * @param int $oid
 *   The associated unique ID used to identify the object in Drupal.
 * @param string $sfid
 *   The Salesforce ID of the associated object in the Salesforce database.
 * @param string $name
 *   The name of the fieldmap used to generate the export.
 * @param string $op_type
 *   The type of operation being performed. Possible values are 'import',
 *   'export', and 'link'.
 * @return
 *   TRUE if was successfull in saving the link, FALSE otherwise.
 * @todo salesforce_api_id_save_multi()
 */
function plantright_sf_api_id_save($drupal_type = NULL, $oid = NULL, $sfid = NULl, $name = NULL, $op_type = NULL) {
  // Allow other modules to respond to salesforce_api_id_save being called
  foreach (module_implements('salesforce_api_id_save_alter') as $module) {
    $function = $module . '_salesforce_api_id_save_alter';
    $continue = $function($drupal_type, $oid, $sfid, $name, $op_type);
    if ($continue === FALSE) {
      return FALSE;
    }
  }

  if ($drupal_type && $oid && $sfid && $name && $op_type) {
    // Create our record for saving to the database
    $record = new stdClass();
    $record->drupal_type = $drupal_type;
    $record->name = $name;
    $record->oid = (int)$oid;
    // Set the last_import/last_export field depending on what type of operation
    // is being performed
    ($op_type == 'export') ? $record->last_export = time() : $record->last_import = time();
    $record->sfid = $sfid;
    $existing_record = db_fetch_array(db_query("SELECT oid, drupal_type, name, sfid, last_import, last_export, created FROM {plantright_sf_object_map} WHERE drupal_type = '%s' AND oid = %d", $drupal_type, $oid));

    if ($existing_record['sfid']) {
      // Update the record
      if (drupal_write_record('plantright_sf_object_map', $record, array('drupal_type', 'oid'))) {
        salesforce_api_log(SALESFORCE_LOG_ALL, 'On !op, successfully re-saved mapping between Drupal !type !oid and Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name));
        return TRUE;
      }
      else {
        // Log an error if we failed to re-save the mapping
        salesforce_api_log(SALESFORCE_LOG_ALL, 'On !op, failed to re-save mapping between Drupal !type !oid with Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name), WATCHDOG_ERROR);
        return FALSE;
      }
    }
    else {
      // We will insert a new mapping, so set the value of created
      $record->created = time();
      if (drupal_write_record('plantright_sf_object_map', $record)) {
        salesforce_api_log(SALESFORCE_LOG_ALL, 'On !op, successfully saved new mapping between Drupal !type !oid and Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name));
        return TRUE;
      }
      else {
        // Log an error if the new mapping was not saved
        salesforce_api_log(SALESFORCE_LOG_ALL, 'On !op, failed to save new mapping between Drupal !type !oid with Salesforce ID !sfid with fieldmap !name', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name), WATCHDOG_ERROR);
        return FALSE;
      }
    }
  }
  else {
    // salesforce_api_id_save was called with insufficient information
    salesforce_api_log(SALESFORCE_LOG_ALL, 'salesforce_api_id_save() called with insufficient data. Drupal type: !type, OID: !oid, SFID: !sfid, Fieldmap !name, Op !op', array('!op' => $op_type, '!type' => $drupal_type, '!oid' => $oid, '!sfid' => $sfid, '!name' => $name), WATCHDOG_ERROR);
  }
}


/**
 * Removes a link between a Salesforce record and a Drupal object. Arguments
 * correspond to the columns in the salesforce_object_map table
 *
 * @param array $args
 *   Associative array of criteria for deletion. These criteria will be AND'ed
 *   together to create a sql DELETE query. Keys are:
 *     - 'oid'
 *        drupal id of the object (nid, uid, etc).
 *
 *     - 'name'
 *        machine name of the fieldmap corresponding to this linkage.
 *        'name' or 'drupal_type' MUST be set.
 *
 *     - 'drupal_type'
 *        type of drupal object corresponding to this linkage.
 *        e.g. "node", "user", etc.
 *        'name' or 'drupal_type' MUST be set.
 *
 *     - 'sfid'
 *        the salesforce id of the object
 *
 *  Keys can be supplied in various combinations, but $args must not be empty.
 *  EITHER "oid" must be set along with "drupal_type" or "name"
 *  OR
 *  "sfid" must be set
 *
 *  In other words, minimal valid key combinations are:
 *    - 'sfid'
 *    - 'drupal_type', 'oid'
 *    - 'name', 'oid'
 */
function plantright_sf_api_id_unlink($args) {
  $valid_args =
    !empty($args['sfid'])
    || (!empty($args['oid'])
        && (!empty($args['drupal_type']) || !empty($args['name'])));
  if (!$valid_args) {
    return FALSE;
  }

  $sql = "DELETE FROM {plantright_sf_object_map} ";
  $sql_args = array();
  $where = array();
  if (!empty($args['oid'])) {
    $where[] = ' oid = %d ';
    $sql_args[] = $args['oid'];
  }
  if (!empty($args['sfid'])) {
    $where[] = ' sfid = "%s" ';
    $sql_args[] = $args['sfid'];
  }
  if (!empty($args['name'])) {
    $where[] = ' name = "%s" ';
    $sql_args[] = $args['name'];
  }
  if (!empty($args['drupal_type'])) {
    $where[] = ' drupal_type = "%s" ';
    $sql_args[] = $args['drupal_type'];
  }
  $sql .= ' WHERE ' . implode(' AND ', $where);
  db_query($sql, $sql_args);
  module_invoke_all('salesforce_api_post_unlink', $args);
}
