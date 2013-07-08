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
    $inviter_user = $object->inviter;
    $name = $inviter_user->name;
    $nursery_name = 'our nursery';
    if ($profile = content_profile_load(PLANTRIGHT_RETAIL_PROFILE, $inviter_user->uid)) {
      // Profile exists. Replace the username with the profile name

      $fname = $profile->{PLANTRIGHT_RETAIL_PROFILE_FNAME};
      if ($fname) {
        $fname = $fname[0]['value'];
        $name = $fname;
      }
      $lname = $profile->{PLANTRIGHT_RETAIL_PROFILE_LNAME};
      if ($lname) {
        $lname = $lname[0]['value'];
        $name = $name . ($name ? ' ' : '') . $lname;
      }

      if ($profile->{PLANTRIGHT_RETAIL_PROFILE_NURSERY} && isset($profile->{PLANTRIGHT_RETAIL_PROFILE_NURSERY}[0]) && $nursery_nid = $profile->{PLANTRIGHT_RETAIL_PROFILE_NURSERY}[0]['nid']) {
          $nursery = node_load($nursery_nid);
          $nursery_name = check_plain($nursery->title);
      }
    }

    $values['pr-inviter-name'] = check_plain($name);
    $values['pr-inviter-nursery'] = check_plain($nursery_name);
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

