<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function plantright_survey_feature_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_additional
  $groups['survey_data-group_additional'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_additional',
    'label' => 'Additional Info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '67',
    'fields' => array(
      '0' => 'field_survey_start_time',
      '1' => 'field_survey_end_time',
      '2' => 'field_survey_store_response',
      '3' => 'field_survey_other',
      '4' => 'field_survey_photo_policy',
    ),
  );

  // Exported group: group_species1
  $groups['survey_data-group_species1'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species1',
    'label' => 'Carex divulsa (often sold as C. tumulicola Hort.) - Grassland sedge (European Grey Sedge, often sold as Berkeley Sedge)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '51',
    'fields' => array(
      '0' => 'field_species1_found',
      '1' => 'field_species1_grower',
      '2' => 'field_species1_price',
      '3' => 'field_species1_name_common',
      '4' => 'field_species1_name_scientific',
      '5' => 'field_species1_name_cultivar',
      '6' => 'field_species1_number',
    ),
  );

  // Exported group: group_species10
  $groups['survey_data-group_species10'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species10',
    'label' => 'Hedera helix - English ivy',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '60',
    'fields' => array(
      '0' => 'field_species10_found',
      '1' => 'field_species10_grower',
      '2' => 'field_species10_price',
      '3' => 'field_species10_name_common',
      '4' => 'field_species10_name_scientific',
      '5' => 'field_species10_name_cultivar',
      '6' => 'field_species10_number',
    ),
  );

  // Exported group: group_species11
  $groups['survey_data-group_species11'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species11',
    'label' => 'Iris pseudacorus - Yellow water iris (Yellow flag iris)',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '61',
    'fields' => array(
      '0' => 'field_species11_found',
      '1' => 'field_species11_grower',
      '2' => 'field_species11_price',
      '3' => 'field_species11_name_common',
      '4' => 'field_species11_name_scientific',
      '5' => 'field_species11_name_cultivar',
      '6' => 'field_species11_number',
    ),
  );

  // Exported group: group_species12
  $groups['survey_data-group_species12'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species12',
    'label' => 'Leucanthemum vulgare  - Ox-eye daisy',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '62',
    'fields' => array(
      '0' => 'field_species12_found',
      '1' => 'field_species12_grower',
      '2' => 'field_species12_price',
      '3' => 'field_species12_name_common',
      '4' => 'field_species12_name_scientific',
      '5' => 'field_species12_name_cultivar',
      '6' => 'field_species12_number',
    ),
  );

  // Exported group: group_species13
  $groups['survey_data-group_species13'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species13',
    'label' => 'Nassella (Stipa) tenuissima - Mexican feather grass',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '63',
    'fields' => array(
      '0' => 'field_species13_found',
      '1' => 'field_species13_grower',
      '2' => 'field_species13_price',
      '3' => 'field_species13_name_common',
      '4' => 'field_species13_name_scientific',
      '5' => 'field_species13_name_cultivar',
      '6' => 'field_species13_number',
    ),
  );

  // Exported group: group_species14
  $groups['survey_data-group_species14'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species14',
    'label' => 'Pennisetum setaceum - Green fountain grass',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '64',
    'fields' => array(
      '0' => 'field_species14_found',
      '1' => 'field_species14_grower',
      '2' => 'field_species14_price',
      '3' => 'field_species14_name_common',
      '4' => 'field_species14_name_scientific',
      '5' => 'field_species14_name_cultivar',
      '6' => 'field_species14_number',
    ),
  );

  // Exported group: group_species15
  $groups['survey_data-group_species15'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species15',
    'label' => ' Triadica (Sapium) sebifera - Chinese tallow tree',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '65',
    'fields' => array(
      '0' => 'field_species15_found',
      '1' => 'field_species15_grower',
      '2' => 'field_species15_price',
      '3' => 'field_species15_name_common',
      '4' => 'field_species15_name_scientific',
      '5' => 'field_species15_name_cultivar',
      '6' => 'field_species15_number',
    ),
  );

  // Exported group: group_species16
  $groups['survey_data-group_species16'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species16',
    'label' => 'Vinca major - Big leaf periwinkle',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '66',
    'fields' => array(
      '0' => 'field_species16_found',
      '1' => 'field_species16_grower',
      '2' => 'field_species16_price',
      '3' => 'field_species16_name_common',
      '4' => 'field_species16_name_scientific',
      '5' => 'field_species16_name_cultivar',
      '6' => 'field_species16_number',
    ),
  );

  // Exported group: group_species2
  $groups['survey_data-group_species2'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species2',
    'label' => 'Carpobrotus edulis - Highway iceplant',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '52',
    'fields' => array(
      '0' => 'field_species2_found',
      '1' => 'field_species2_grower',
      '2' => 'field_species2_price',
      '3' => 'field_species2_name_common',
      '4' => 'field_species2_name_scientific',
      '5' => 'field_species2_name_cultivar',
      '6' => 'field_species2_number',
    ),
  );

  // Exported group: group_species3
  $groups['survey_data-group_species3'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species3',
    'label' => 'Catalpa bignonioides - Southern catalpa',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '53',
    'fields' => array(
      '0' => 'field_species3_found',
      '1' => 'field_species3_grower',
      '2' => 'field_species3_price',
      '3' => 'field_species3_name_common',
      '4' => 'field_species3_name_scientific',
      '5' => 'field_species3_name_cultivar',
      '6' => 'field_species3_number',
    ),
  );

  // Exported group: group_species4
  $groups['survey_data-group_species4'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species4',
    'label' => 'Cortaderia selloana - Pampas grass',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '54',
    'fields' => array(
      '0' => 'field_species4_found',
      '1' => 'field_species4_grower',
      '2' => 'field_species4_price',
      '3' => 'field_species4_name_common',
      '4' => 'field_species4_name_scientific',
      '5' => 'field_species4_name_cultivar',
      '6' => 'field_species4_number',
    ),
  );

  // Exported group: group_species5
  $groups['survey_data-group_species5'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species5',
    'label' => 'Cytisus scoparius - Scotch broom',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '55',
    'fields' => array(
      '0' => 'field_species5_found',
      '1' => 'field_species5_grower',
      '2' => 'field_species5_price',
      '3' => 'field_species5_name_common',
      '4' => 'field_species5_name_scientific',
      '5' => 'field_species5_name_cultivar',
      '6' => 'field_species5_number',
    ),
  );

  // Exported group: group_species6
  $groups['survey_data-group_species6'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species6',
    'label' => 'Egeria densa - Brazilian waterweed',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '56',
    'fields' => array(
      '0' => 'field_species6_found',
      '1' => 'field_species6_grower',
      '2' => 'field_species6_price',
      '3' => 'field_species6_name_common',
      '4' => 'field_species6_name_scientific',
      '5' => 'field_species6_name_cultivar',
      '6' => 'field_species6_number',
    ),
  );

  // Exported group: group_species7
  $groups['survey_data-group_species7'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species7',
    'label' => 'Eichhornia crassipes - Water hyacinth',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '57',
    'fields' => array(
      '0' => 'field_species7_found',
      '1' => 'field_species7_grower',
      '2' => 'field_species7_price',
      '3' => 'field_species7_name_common',
      '4' => 'field_species7_name_scientific',
      '5' => 'field_species7_name_cultivar',
      '6' => 'field_species7_number',
    ),
  );

  // Exported group: group_species8
  $groups['survey_data-group_species8'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species8',
    'label' => 'Genista monspessulana - French broom',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '58',
    'fields' => array(
      '0' => 'field_species8_found',
      '1' => 'field_species8_grower',
      '2' => 'field_species8_price',
      '3' => 'field_species8_name_common',
      '4' => 'field_species8_name_scientific',
      '5' => 'field_species8_name_cultivar',
      '6' => 'field_species8_number',
    ),
  );

  // Exported group: group_species9
  $groups['survey_data-group_species9'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species9',
    'label' => 'Hedera canariensis - Algerian ivy',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '59',
    'fields' => array(
      '0' => 'field_species9_found',
      '1' => 'field_species9_grower',
      '2' => 'field_species9_price',
      '3' => 'field_species9_name_common',
      '4' => 'field_species9_name_scientific',
      '5' => 'field_species9_name_cultivar',
      '6' => 'field_species9_number',
    ),
  );

  // Exported group: group_survey_basic
  $groups['survey_data-group_survey_basic'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_survey_basic',
    'label' => 'Basic Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '50',
    'fields' => array(
      '0' => 'field_survey_date',
      '1' => 'field_store_name',
      '2' => 'field_survey_name',
      '3' => 'field_survey_email',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Triadica (Sapium) sebifera - Chinese tallow tree');
  t('Additional Info');
  t('Basic Information');
  t('Carex divulsa (often sold as C. tumulicola Hort.) - Grassland sedge (European Grey Sedge, often sold as Berkeley Sedge)');
  t('Carpobrotus edulis - Highway iceplant');
  t('Catalpa bignonioides - Southern catalpa');
  t('Cortaderia selloana - Pampas grass');
  t('Cytisus scoparius - Scotch broom');
  t('Egeria densa - Brazilian waterweed');
  t('Eichhornia crassipes - Water hyacinth');
  t('Genista monspessulana - French broom');
  t('Hedera canariensis - Algerian ivy');
  t('Hedera helix - English ivy');
  t('Iris pseudacorus - Yellow water iris (Yellow flag iris)');
  t('Leucanthemum vulgare  - Ox-eye daisy');
  t('Nassella (Stipa) tenuissima - Mexican feather grass');
  t('Pennisetum setaceum - Green fountain grass');
  t('Vinca major - Big leaf periwinkle');

  return $groups;
}
