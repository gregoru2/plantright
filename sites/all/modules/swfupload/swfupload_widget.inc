<?php
// $Id: swfupload_widget.inc,v 1.6 2010/12/02 16:02:53 skilip Exp $

/**
 * @file
 * SWFUpload widget hooks and callbacks.
 */

/**
 * Implementation of hook_widget_info().
 */
function swfupload_widget_info() {
  return array(
    'swfupload_widget' => array(
      'label' => t('SWFUpload'),
      'field types' => array('filefield'),
      'multiple values' => CONTENT_HANDLE_MODULE,
      'callbacks' => array(
        'default value' => CONTENT_CALLBACK_CUSTOM,
      ),
    ),
  );
}

/**
 * Implementation of CCK's hook_widget_settings().
 *
 * Delegated to filefield.
 */
function swfupload_widget_settings($op, $widget) {
  module_load_include('inc', 'swfupload', 'swfupload_widget');
  switch ($op) {
    case 'form':
      return swfupload_widget_settings_form($widget);
    case 'validate':
      return swfupload_widget_settings_validate($widget);
    case 'save':
      return swfupload_widget_settings_save($widget);
  }
}

/**
 * An #element_validate callback for the filefield_widget field.
 */
function swfupload_widget_validate(&$element, &$form_state) {

  $element_value = $element['#value'];
  if (!empty($element_value)) {
    foreach (array_values($element_value) as $key => $file) {
      $form_state['values'][$element['#field_name']][$key] = array_merge(
        field_file_load($file['fid']), // Load all fields, such as 'filepath'.
        array(
          'list' => $file['list'],
          'data' => array(
            'description' => $file['description'],
            'alt' => $file['alt'],
            'title' => $file['title'],
          ),
        )
      );
      unset($form_state['values'][$element['#field_name']][$file['fid']]);
    }
    unset($form_state['values'][$element['#field_name']]['data']);
  }
}

/**
 * The #value_callback for the swfupload_widget type element.
 */
function swfupload_widget_value($element, $edit = FALSE) {
  if (is_string($edit)) {
    $edit = json_decode($edit, TRUE);
  }

  if ($edit === false) {
    $default_value = array();

    if (is_array($element['#default_value'])) {
      foreach ($element['#default_value'] as $tmp_file) {
        if ($tmp_file) {
          // Due to a bug in CCK or filefield, the fileobject store in the CCK cache (cache_content) is not stored fully
          // that means some fields are simply missing (filepath etc.). We need to properly restore it here 
          $file = field_file_load($tmp_file['fid']);
          $file += array(
            'description' => $tmp_file['data']['description'] ? $tmp_file['data']['description'] : '',
            'alt' => $tmp_file['data']['alt'],
            'title' => $tmp_file['data']['title'],
            'list' => $tmp_file['list'],
          );

          // If we're dealing with an image, create a thumbpath
          if (image_get_info($file['filepath'])) {
            $file['thumb'] = file_create_url(drupal_urlencode(swfupload_thumb_path($file)));
          }
          $default_value[$file['fid']] = $file;
        }
      }
    }
    return $default_value;
  }
  else {
    return $edit;
  }
}

/**
 * Process an individual element.
 *
 * Build the form element. When creating a form using FAPI #process,
 * note that $element['#value'] is already set.
 *
 * The $fields array is in $form['#field_info'][$element['#field_name']].
 */
function swfupload_widget_process($element, $edit, $form_state, $form) {
  if (module_exists('imagefield')) {
    $element += imagefield_widget_process($element, $edit, $form_state, $form);
    unset($element['#theme']);
  }
  
  // Make sure that the thumbnails exist. $element['#value'] is
  // structured differently in our widget, so this is not handled by
  // imagefield_widget_process().
  if (is_array($element['#value'])) {
    foreach (element_children($element['#value']) as $key) {
      if (isset($element['#value'][$key]['filepath'])) {
        $file = $element['#value'][$key];
        swfupload_thumb_path($file, TRUE);
      }
    }
  }

  $element['#default_value'] = '[]';
  return $element;
}

/**
 * Implementation of CCK's hook_widget_settings($op = 'form').
 */
function swfupload_widget_settings_form($widget) {
  if (module_exists('imagefield')) {
    module_load_include('inc', 'imagefield', 'imagefield_widget');
    $form = imagefield_widget_settings_form($widget);
  }
  else {
    $form = module_invoke('filefield', 'widget_settings', 'form', $widget);
  }


  // Allow the admin to choose how they'd like their upload thumbnails to appear:
  $form['upload_thumbnails'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upload thumbnails'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 8,
  );
  $generation_options = array(
    'basic' => t('Basic'),
  );
  if (module_exists('imagecache')) {
    $generation_options['imagecache'] = t('Imagecache preset');
  }
  $form['upload_thumbnails']['upload_thumbnail_type'] = array(
    '#type' => 'radios',
    '#title' => t('Thumbnail type'),
    '#default_value' =>  !empty($widget['upload_thumbnail_type']) ? $widget['upload_thumbnail_type'] : 'basic',
    '#description' => t('Choose how the upload thumbnail should be generated.'),
    '#options' => $generation_options,
  );
  $form['upload_thumbnails']['upload_thumbnail_basic_setting'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail size'),
    '#default_value' => !empty($widget['upload_thumbnail_basic_setting']) ? $widget['upload_thumbnail_basic_setting'] : '32x32',
    '#description' => t("Size of the thumbnails displayed if the type is 'Basic'. Format: WIDTHxHEIGHT."),
  );

  if (module_exists('imagecache')) {
    $presets = array();
    foreach (imagecache_presets() as $preset => $name) {
      $presets[$name['presetname']] = $name['presetname'];
    }
    $form['upload_thumbnails']['upload_thumbnail_imagecache_preset'] = array(
      '#type' => 'select',
      '#title' => t('Thumbnail Imagecache preset'),
      '#default_value' => !empty($widget['upload_thumbnail_imagecache_preset']) ? $widget['upload_thumbnail_imagecache_preset'] : '',
      '#description' => t("Imagecache preset to use to generate thumbnails if the type is 'Imagecache preset'"),
      '#options' => $presets,
    );
  }


  return $form;
}

/**
 * Implementation of CCK's hook_widget_settings($op = 'validate').
 */
function swfupload_widget_settings_validate($widget) {
  // Check that set resolutions are valid.
  foreach (array('min_resolution', 'max_resolution') as $resolution) {
    if (!empty($widget[$resolution]) && !preg_match('/^[0-9]+x[0-9]+$/', $widget[$resolution])) {
      form_set_error($resolution, t('Please specify a resolution in the format WIDTHxHEIGHT (e.g. 640x480).'));
    }
  }

  // Check the basic size setting:
  if (($widget['upload_thumbnail_type'] == 'basic') && empty($widget['upload_thumbnail_basic_setting'])) {
    form_set_error('upload_thumbnail_basic_setting', t('Please specify a resolution in the format WIDTHxHEIGHT (e.g. 100x100).'));
  }
  if (!empty($widget['upload_thumbnail_basic_setting']) && !preg_match('/^[0-9]+x[0-9]+$/', $widget['upload_thumbnail_basic_setting'])) {
    form_set_error('upload_thumbnail_basic_setting', t('Please specify a resolution in the format WIDTHxHEIGHT (e.g. 100x100).'));
  }
}

/**
 * Implementation of CCK's hook_widget_settings($op = 'save').
 */
function swfupload_widget_settings_save($widget) {
  $filefield_settings = module_invoke('filefield', 'widget_settings', 'save', $widget);
  return array_merge($filefield_settings, array('max_resolution', 'min_resolution', 'alt',  'custom_alt', 'title', 'custom_title', 'title_type', 'default_image', 'use_default_image', 'upload_thumbnail_type', 'upload_thumbnail_basic_setting', 'upload_thumbnail_imagecache_preset'));
}
