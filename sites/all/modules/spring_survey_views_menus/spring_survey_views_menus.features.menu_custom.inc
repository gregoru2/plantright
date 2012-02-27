<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function spring_survey_views_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-pre-survey-menu
  $menus['menu-pre-survey-menu'] = array(
    'menu_name' => 'menu-pre-survey-menu',
    'title' => 'Spring Survey',
    'description' => 'this is the menu presented before the user passes the quiz.',
  );
  // Exported menu: menu-survey-admin
  $menus['menu-survey-admin'] = array(
    'menu_name' => 'menu-survey-admin',
    'title' => 'Survey Admin',
    'description' => '',
  );
  // Exported menu: menu-survey-menu
  $menus['menu-survey-menu'] = array(
    'menu_name' => 'menu-survey-menu',
    'title' => 'Survey Menu',
    'description' => 'This is for the Spring Survey portion of the site.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Spring Survey');
  t('Survey Admin');
  t('Survey Menu');
  t('This is for the Spring Survey portion of the site.');
  t('this is the menu presented before the user passes the quiz.');


  return $menus;
}
