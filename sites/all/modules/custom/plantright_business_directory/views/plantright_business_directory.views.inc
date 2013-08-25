<?php

/**
 * Implementation of hook_views_data_alter().
 */
function plantright_business_directory_views_data_alter(&$data) {
  if (!isset($data['location_county']['county']['sort'])) {
    $data['location_county']['county']['sort'] = array(
      'handler' => 'views_handler_sort',
    );
  }
}