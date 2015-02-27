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
    'weight' => '23',
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
    'weight' => '5',
    'fields' => array(
      '0' => 'field_species1_found',
      '1' => 'field_species1_grower',
      '2' => 'field_species1_price',
      '3' => 'field_species1_name_common',
      '4' => 'field_species1_name_scientific',
      '5' => 'field_species1_name_cultivar',
      '6' => 'field_species1_number',
      '7' => 'field_species1_related',
    ),
  );

  // Exported group: group_species10
  $groups['survey_data-group_species10'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species10',
    'label' => 'Sesbania punicea - Scarlet wisteria',
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
    'weight' => '17',
    'fields' => array(
      '0' => 'field_species10_found',
      '1' => 'field_species10_grower',
      '2' => 'field_species10_price',
      '3' => 'field_species10_name_common',
      '4' => 'field_species10_name_scientific',
      '5' => 'field_species10_name_cultivar',
      '6' => 'field_species10_number',
      '7' => 'field_species10_related',
    ),
  );

  // Exported group: group_species11
  $groups['survey_data-group_species11'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species11',
    'label' => 'Nassella tenuissima - Mexican feathergrass',
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
    'weight' => '7',
    'fields' => array(
      '0' => 'field_species11_found',
      '1' => 'field_species11_grower',
      '2' => 'field_species11_price',
      '3' => 'field_species11_name_common',
      '4' => 'field_species11_name_scientific',
      '5' => 'field_species11_name_cultivar',
      '6' => 'field_species11_number',
      '7' => 'field_species11_related',
    ),
  );

  // Exported group: group_species12
  $groups['survey_data-group_species12'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species12',
    'label' => 'Pennisetum setaceum - Green fountain grass',
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
    'weight' => '8',
    'fields' => array(
      '0' => 'field_species12_found',
      '1' => 'field_species12_grower',
      '2' => 'field_species12_price',
      '3' => 'field_species12_name_common',
      '4' => 'field_species12_name_scientific',
      '5' => 'field_species12_name_cultivar',
      '6' => 'field_species12_number',
      '7' => 'field_species12_related',
    ),
  );

  // Exported group: group_species13
  $groups['survey_data-group_species13'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species13',
    'label' => 'Triadica sebifera - Chinese tallow tree',
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
    'weight' => '20',
    'fields' => array(
      '0' => 'field_species13_found',
      '1' => 'field_species13_grower',
      '2' => 'field_species13_price',
      '3' => 'field_species13_name_common',
      '4' => 'field_species13_name_scientific',
      '5' => 'field_species13_name_cultivar',
      '6' => 'field_species13_number',
      '7' => 'field_species13_related',
    ),
  );

  // Exported group: group_species14
  $groups['survey_data-group_species14'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species14',
    'label' => 'Vinca major - Periwinkle',
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
    'weight' => '11',
    'fields' => array(
      '0' => 'field_species14_found',
      '1' => 'field_species14_grower',
      '2' => 'field_species14_price',
      '3' => 'field_species14_name_common',
      '4' => 'field_species14_name_scientific',
      '5' => 'field_species14_name_cultivar',
      '6' => 'field_species14_number',
      '7' => 'field_species14_related',
    ),
  );

  // Exported group: group_species15
  $groups['survey_data-group_species15'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species15',
    'label' => 'Ligustrum lucidum - Glossy privet',
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
    'weight' => '15',
    'fields' => array(
      '0' => 'field_species15_found',
      '1' => 'field_species15_grower',
      '2' => 'field_species15_price',
      '3' => 'field_species15_name_common',
      '4' => 'field_species15_name_scientific',
      '5' => 'field_species15_name_cultivar',
      '6' => 'field_species15_number',
      '7' => 'field_species15_related',
    ),
  );

  // Exported group: group_species16
  $groups['survey_data-group_species16'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species16',
    'label' => 'Schinus terebinthifolius - Brazillian pepper tree',
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
    'weight' => '19',
    'fields' => array(
      '0' => 'field_species16_found',
      '1' => 'field_species16_grower',
      '2' => 'field_species16_price',
      '3' => 'field_species16_name_common',
      '4' => 'field_species16_name_scientific',
      '5' => 'field_species16_name_cultivar',
      '6' => 'field_species16_number',
      '7' => 'field_species16_related',
    ),
  );

  // Exported group: group_species17
  $groups['survey_data-group_species17'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species17',
    'label' => 'Fraxinus uhdei - Shamel ash',
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
    'weight' => '18',
    'fields' => array(
      '0' => 'field_species17_found',
      '1' => 'field_species17_grower',
      '2' => 'field_species17_price',
      '3' => 'field_species17_name_common',
      '4' => 'field_species17_name_scientific',
      '5' => 'field_species17_name_cultivar',
      '6' => 'field_species17_number',
      '7' => 'field_species17_related',
    ),
  );

  // Exported group: group_species18
  $groups['survey_data-group_species18'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species18',
    'label' => 'Osteospermum fruticosum - African daisy',
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
    'weight' => '10',
    'fields' => array(
      '0' => 'field_species18_found',
      '1' => 'field_species18_grower',
      '2' => 'field_species18_price',
      '3' => 'field_species18_name_common',
      '4' => 'field_species18_name_scientific',
      '5' => 'field_species18_name_cultivar',
      '6' => 'field_species18_number',
      '7' => 'field_species18_related',
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
    'weight' => '9',
    'fields' => array(
      '0' => 'field_species2_found',
      '1' => 'field_species2_grower',
      '2' => 'field_species2_price',
      '3' => 'field_species2_name_common',
      '4' => 'field_species2_name_scientific',
      '5' => 'field_species2_name_cultivar',
      '6' => 'field_species2_number',
      '7' => 'field_species2_related',
    ),
  );

  // Exported group: group_species3
  $groups['survey_data-group_species3'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species3',
    'label' => 'Cytisus striatus - Portuguese broom',
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
    'weight' => '13',
    'fields' => array(
      '0' => 'field_species3_found',
      '1' => 'field_species3_grower',
      '2' => 'field_species3_price',
      '3' => 'field_species3_name_common',
      '4' => 'field_species3_name_scientific',
      '5' => 'field_species3_name_cultivar',
      '6' => 'field_species3_number',
      '7' => 'field_species3_related',
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
    'weight' => '6',
    'fields' => array(
      '0' => 'field_species4_found',
      '1' => 'field_species4_grower',
      '2' => 'field_species4_price',
      '3' => 'field_species4_name_common',
      '4' => 'field_species4_name_scientific',
      '5' => 'field_species4_name_cultivar',
      '6' => 'field_species4_number',
      '7' => 'field_species4_related',
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
    'weight' => '12',
    'fields' => array(
      '0' => 'field_species5_found',
      '1' => 'field_species5_grower',
      '2' => 'field_species5_price',
      '3' => 'field_species5_name_common',
      '4' => 'field_species5_name_scientific',
      '5' => 'field_species5_name_cultivar',
      '6' => 'field_species5_number',
      '7' => 'field_species5_related',
    ),
  );

  // Exported group: group_species6
  $groups['survey_data-group_species6'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species6',
    'label' => 'Myoporum laetum - Myoporum',
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
    'weight' => '16',
    'fields' => array(
      '0' => 'field_species6_found',
      '1' => 'field_species6_grower',
      '2' => 'field_species6_price',
      '3' => 'field_species6_name_common',
      '4' => 'field_species6_name_scientific',
      '5' => 'field_species6_name_cultivar',
      '6' => 'field_species6_number',
      '7' => 'field_species6_related',
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
    'weight' => '21',
    'fields' => array(
      '0' => 'field_species7_found',
      '1' => 'field_species7_grower',
      '2' => 'field_species7_price',
      '3' => 'field_species7_name_common',
      '4' => 'field_species7_name_scientific',
      '5' => 'field_species7_name_cultivar',
      '6' => 'field_species7_number',
      '7' => 'field_species7_related',
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
    'weight' => '14',
    'fields' => array(
      '0' => 'field_species8_found',
      '1' => 'field_species8_grower',
      '2' => 'field_species8_price',
      '3' => 'field_species8_name_common',
      '4' => 'field_species8_name_scientific',
      '5' => 'field_species8_name_cultivar',
      '6' => 'field_species8_number',
      '7' => 'field_species8_related',
    ),
  );

  // Exported group: group_species9
  $groups['survey_data-group_species9'] = array(
    'group_type' => 'standard',
    'type_name' => 'survey_data',
    'group_name' => 'group_species9',
    'label' => 'Iris pseudacorus - Yellow water iris',
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
    'weight' => '22',
    'fields' => array(
      '0' => 'field_species9_found',
      '1' => 'field_species9_grower',
      '2' => 'field_species9_price',
      '3' => 'field_species9_name_common',
      '4' => 'field_species9_name_scientific',
      '5' => 'field_species9_name_cultivar',
      '6' => 'field_species9_number',
      '7' => 'field_species9_related',
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
    'weight' => '4',
    'fields' => array(
      '0' => 'field_survey_date',
      '1' => 'field_store_name',
      '2' => 'field_survey_name',
      '3' => 'field_survey_email',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional Info');
  t('Basic Information');
  t('Carex divulsa (often sold as C. tumulicola Hort.) - Grassland sedge (European Grey Sedge, often sold as Berkeley Sedge)');
  t('Carpobrotus edulis - Highway iceplant');
  t('Cortaderia selloana - Pampas grass');
  t('Cytisus scoparius - Scotch broom');
  t('Cytisus striatus - Portuguese broom');
  t('Eichhornia crassipes - Water hyacinth');
  t('Fraxinus uhdei - Shamel ash');
  t('Genista monspessulana - French broom');
  t('Iris pseudacorus - Yellow water iris');
  t('Ligustrum lucidum - Glossy privet');
  t('Myoporum laetum - Myoporum');
  t('Nassella tenuissima - Mexican feathergrass');
  t('Osteospermum fruticosum - African daisy');
  t('Pennisetum setaceum - Green fountain grass');
  t('Schinus terebinthifolius - Brazillian pepper tree');
  t('Sesbania punicea - Scarlet wisteria');
  t('Triadica sebifera - Chinese tallow tree');
  t('Vinca major - Periwinkle');

  return $groups;
}
