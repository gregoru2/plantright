<?php

/**
 * @file
 * Token integration functions for invite module.
 */

/**
 * Implementation of hook_token_values().
 */
function plantright_token_values($type = 'all', $object = NULL) {
  $values = array();
  if ($type == 'invite' && is_object($object)) {
    $values['pr-inviter-name'] = check_plain(plantright_get_user_profile_name($object->inviter));
    $values['pr-inviter-nursery'] = check_plain(plantright_get_user_profile_nursery($object->inviter));
  }
  return $values;
}

/**
 * Implementation of hook_token_list().
 */
function plantright_token_list($type = 'all') {
  if ($type == 'invite' || $type == 'all') {
    $tokens['invite']['pr-inviter-name'] = t('The plantright profile name of the user.');
    $tokens['invite']['pr-inviter-nursery'] = t('The plantright nursery of the user.');
    return $tokens;
  }
}

/**
 * For a given context, builds a formatted list of tokens and descriptions
 * of their replacement values.
 *
 * @param type
 *   The token types to display documentation for. Defaults to 'all'.
 * @param prefix
 *   The prefix your module will use when parsing tokens. Defaults to '['
 * @param suffix
 *   The suffix your module will use when parsing tokens. Defaults to ']'
 * @return
 *   An HTML table containing the formatting docs.
 */
function theme_plantright_token_help($type = 'all', $prefix = '[', $suffix = ']') {
  token_include();

  // @see http://drupal.org/node/127072
  $full_list = array();
  foreach ((array) $type as $t) {
    $full_list = array_merge($full_list, token_get_list($t));
  }

  $headers = array(t('Token'), t('Replacement value'));
  $rows = array();
  foreach ($full_list as $key => $category) {
    $rows[] = array(array('data' => drupal_ucfirst($key) . ' ' . t('tokens'), 'class' => 'region', 'colspan' => 2));
    foreach ($category as $token => $description) {
      $row = array();
      $row[] = $prefix . $token . $suffix;
      $row[] = $description;
      $rows[] = $row;
    }
  }

  $output = theme('table', $headers, $rows, array('class' => 'description'));
  return $output;
}

