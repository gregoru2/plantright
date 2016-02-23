<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function plantright_survey_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access imagefield_zip widget
  $permissions['access imagefield_zip widget'] = array(
    'name' => 'access imagefield_zip widget',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
