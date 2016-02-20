<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function pr_feature_common_img_presets_imagecache_default_presets() {
  $items = array(
    'scaled_max_200' => array(
      'presetname' => 'scaled_max_200',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '200',
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
    'thumb_100' => array(
      'presetname' => 'thumb_100',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '100',
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
    'thumb_150' => array(
      'presetname' => 'thumb_150',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '120',
            'height' => '120',
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
    'thumb_60' => array(
      'presetname' => 'thumb_60',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '60',
            'height' => '60',
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
