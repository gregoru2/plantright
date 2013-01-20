<?php
// $Id: 

/**
 * hook_views_plugins()
 */
function dompdf_views_plugins() {

  $path = drupal_get_path('module', 'dompdf');
  return array(
    'style' => array(
      'dompdf' => array(
        'title' => t('PDF'),
        'help' => t('Display the view as a PDF.'),
        'path' => $path,
        'handler' => 'dompdf_plugin_style_export_pdf',
        'parent' => 'views_bonus_export',
        'theme' => 'dompdf_pdf',
        'theme file' => 'dompdf.theme.inc',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'feed',
      ),
    ),
  );

}





