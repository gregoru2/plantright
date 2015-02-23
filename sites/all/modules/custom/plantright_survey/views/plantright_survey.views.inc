<?php

function plantright_survey_views_data() {
  $data['views']['plantright_survey_result_calc1'] = array(
    'title' => t('PlantRight Plants found boolean'),
    'help' => t('Has invasive plants found'),
    'field' => array(
      'handler' => 'plantright_survey_handler_field_found_count',
      'label' => t('Invasive Present'),
      'click sortable' => TRUE,
    ),
  );

  $data['views']['plantright_survey_result_calc2'] = array(
    'title' => t('PlantRight Plants found count'),
    'help' => t('Number of invasive plants found.'),
    'field' => array(
      'handler' => 'plantright_survey_handler_field_number_count',
      'label' => t('Number Invasive Present'),
      'click sortable' => TRUE,
    ),
  );

  $data['views']['plantright_survey_result_calc3'] = array(
    'title' => t('Time in minutes'),
    'help' => t('PlantRight difference in time calc in minutes'),
    'field' => array(
      'handler' => 'plantright_survey_handler_field_time_min',
      'click sortable' => TRUE,
    ),
  );

  $data['views']['plantright_survey_result_calc4'] = array(
    'title' => t('Total Time'),
    'help' => t('PlantRight difference in time calc in hours'),
    'field' => array(
      'handler' => 'plantright_survey_handler_field_time_hours',
      'click sortable' => TRUE,
    ),
  );

  // County tracking.
  $data['plantright_survey_county_tracking']['table']['group'] = t('Survey County Tracking');

  $data['plantright_survey_county_tracking']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Survey County Tracking Table'),
    'help' => t('Table contains survey county tracking data.'),
  );

  $data['plantright_survey_county_tracking']['id'] = array(
    'title' => t('ID'),
    'help' => t('Primary identifier'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['region'] = array(
    'title' => t('Region'),
    'help' => t('Region name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['county'] = array(
    'title' => t('County'),
    'help' => t('County name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    )
  );

  $data['plantright_survey_county_tracking']['stores_number_claimed'] = array(
    'title' => t('Number of Stores Claimed'),
    'help' => t('Survey number of stores claimed'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['stores_number_total'] = array(
    'title' => t('Total Number of Stores for County'),
    'help' => t('Survey total number of stores'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['stores_delta_claimed'] = array(
    'title' => t('Surplus/Deficit Claimed'),
    'help' => t('Difference of stores total vs claimed.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['stores_number_w_data_photos'] = array(
    'title' => t('Number of Stores with Data & Pictures Submitted'),
    'help' => t('Survey stores with photos and data submitted'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );
  
  $data['plantright_survey_county_tracking']['stores_number_w_data'] = array(
    'title' => t('Number of Stores with Data Submitted'),
    'help' => t('Survey stores with data submitted'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );
  
  $data['plantright_survey_county_tracking']['stores_number_w_photos'] = array(
    'title' => t('Number of Stores with Pictures Submitted'),
    'help' => t('Survey stores with photos submitted'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['stores_percent_surveyed'] = array(
    'title' => t('Percent Stores Surveyed'),
    'help' => t('Percentage of stores surveyed (total/data submitted)'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_county_tracking']['stores_delta_data'] = array(
    'title' => t('Surplus/Deficit Data Submitted'),
    'help' => t('Difference between claimed stores and data submitted'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  // Volunteer tracking
  $data['plantright_survey_volunteer_tracking']['table']['group'] = t('Survey Volunteer Tracking');

  $data['plantright_survey_volunteer_tracking']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Survey Volunteer Tracking Table'),
    'help' => t('Table contains survey volunteer tracking data.'),
  );

  $data['plantright_survey_volunteer_tracking']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['plantright_survey_volunteer_tracking']['id'] = array(
    'title' => t('ID'),
    'help' => t('Primary identifier'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
  );

  $data['plantright_survey_volunteer_tracking']['uid'] = array(
    'title' => t('Survey Volunteer'),
    'help' => t('Survey volunteer associated to the tracking'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'label' => t('Survey Volunteer'),
    ),
  );

  $data['plantright_survey_volunteer_tracking']['passed_quiz'] = array(
    'title' => t('Passed quiz'),
    'help' => t('User has passed quiz'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Passed Quiz'),
      'type' => 'yes-no',
    ),
  );

  $data['plantright_survey_volunteer_tracking']['data_submitted'] = array(
    'title' => t('Data submitted'),
    'help' => t('User has submitted data'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Data Submitted'),
      'type' => 'yes-no',
    ),
  );

  $data['plantright_survey_volunteer_tracking']['photos_submitted'] = array(
    'title' => t('Photos submitted'),
    'help' => t('User has submitted photos'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Photos Submitted'),
      'type' => 'yes-no',
    ),
  );

  $data['plantright_survey_volunteer_tracking']['claimed_store'] = array(
    'title' => t('Claimed store'),
    'help' => t('User has claimed store'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Claimed Store'),
      'type' => 'yes-no',
    ),
  );

//  $data['plantright_survey_volunteer_tracking'][''] = array(
//    'title' => t(''),
//    'help' => t('User has '),
//    'field' => array(
//      'handler' => 'views_handler_field_boolean',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_boolean_operator',
//      'label' => t(''),
//      'type' => 'yes-no',
//    ),
//  );

  return $data;
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function plantright_survey_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'plantright_survey') . '/views',
    ),
    'handlers' => array(
      // field handlers
      'plantright_survey_handler_field_found_count' => array(
        'parent' => 'views_handler_field',
      ),
      'plantright_survey_handler_field_number_count' => array(
        'parent' => 'views_handler_field',
      ),
      'plantright_survey_handler_field_time_min' => array(
        'parent' => 'views_handler_field',
      ),
      'plantright_survey_handler_field_time_hours' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
