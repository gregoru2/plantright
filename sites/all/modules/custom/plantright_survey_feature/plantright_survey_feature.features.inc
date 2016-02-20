<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function plantright_survey_feature_imagecache_default_presets() {
  $items = array(
    'survey_submission' => array(
      'presetname' => 'survey_submission',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '780px',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache_autorotate',
          'action' => 'imagecache_autorotate',
          'data' => array(),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function plantright_survey_feature_node_info() {
  $items = array(
    'nursery' => array(
      'name' => t('Nursery'),
      'module' => 'features',
      'description' => t('This is a Nursery to be surveyed for the Spring Survey.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'survey_data' => array(
      'name' => t('Spring Survey Data'),
      'module' => 'features',
      'description' => t('Submissions of spring survey data.'),
      'has_title' => '1',
      'title_label' => t('Store Code'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'survey_photos' => array(
      'name' => t('Spring Survey Photos'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Store Code'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function plantright_survey_feature_views_api() {
  return array(
    'api' => '2',
  );
}
