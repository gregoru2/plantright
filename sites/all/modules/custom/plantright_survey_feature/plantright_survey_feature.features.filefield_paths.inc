<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function plantright_survey_feature_default_filefield_paths() {
  $settings = array();

  // Exported survey_photos-field_survey_image
  $settings['survey_photos-field_survey_image'] = array(
    'type' => 'survey_photos',
    'field' => 'field_survey_image',
    'filename' => array(
      'value' => '[author-name]_[title]_[filefield-description]_[filefield-fid].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 1,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'spring-survey-images/2014/user-[author-uid]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );

  return $settings;
}
