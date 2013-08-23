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
  if ($type == 'node' && !empty($object)) {
    $node = $object;
    //$node_owner = db_fetch_object(db_query("SELECT name, mail FROM {users} WHERE uid = %d", $node->uid));
    $fieldnames = array('field_retailer');
    $nodetypes = array('retail_member');
    //$referrers = _plantright_get_retailer_referrer_users($node->nid,  $fieldnames);
    $referrers = nodereferrer_referrers($node->nid,  $fieldnames, $nodetypes);
    $mails = array();
    foreach($referrers as $profile_nid => $val) {
      $profile = node_load($profile_nid);
      // Exclude the nursery owner.
      if ($node->uid != $profile->uid) {
        $user = user_load($profile->uid);
        $mails[$user->mail] = $user->mail;
      }
    }
    $mail = implode(',', $mails);

    $values['plantright-business-employees-mail']        = check_plain($mail);
    $values['plantright-business-employees-mail-raw']    = $mail;
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
  }
  if ($type == 'node' || $type == 'all') {
    $tokens['node']['plantright-business-employees-mail']     = t("Comma-seperated list of email addresses of employees of the given retailer nursery.");
    $tokens['node']['plantright-business-employees-mail-raw'] = t("Comma-seperated list of email addresses of employees of the given retailer nursery.");
  }
  return $tokens;
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

