<?php

/**
 * Implementation of hook_user_default_roles().
 */
function spring_survey_views_menus_user_default_roles() {
  $roles = array();

  // Exported role: Regional Coordinator
  $roles['Regional Coordinator'] = array(
    'name' => 'Regional Coordinator',
  );

  // Exported role: Survey Member
  $roles['Survey Member'] = array(
    'name' => 'Survey Member',
  );

  return $roles;
}
