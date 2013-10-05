<?php

/**
 * @file
 *
 * Send email class
 */
class ScheduleEmail {

  private $sent_log = array();

  public function __construct($send = TRUE) {
    if ($send) {
      $types = self::get_types(TRUE);
      $setid = array_search('register', $types);
      $register_emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($register_emails as $scheduled_email) {
        $this->send_scheduled_email($scheduled_email, $this->get_registered_users_to_email($scheduled_email));
      }

      $setid = NULL;
      $setid = array_search('invite', $types);
      $invite_emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($invite_emails as $scheduled_email) {
        $this->send_scheduled_email($scheduled_email, $this->get_invited_users_to_email($scheduled_email));
      }
    }
  }

  /**
   * Helper function to get the email schedule types
   */
  public static function get_types($short = FALSE) {
    $types = array();
    $val = $short ? 'name_short' : 'name';
    $result = db_query("SELECT setid, %s FROM {schedule_email_type}", $val);
    while ($row = db_fetch_array($result)) {
      $types[$row['setid']] = $row[$val];
    }
    return $types;
  }

  /**
   * Helper function to get the emails that are schedule to be sent
   * @param type $type_id
   *   type ID of the type of email to send
   */
  public function get_schedule_emails_by_typeid($type_id = NULL) {
    if (!$type_id) {
      $result = db_query("SELECT MAX(n.vid) vid, n.nid, n.title, se.seid, se.setid, se.days, se.subject, r.body, r.format, sety.name, sety.name_short FROM {schedule_email} se JOIN {node} n ON n.vid = se.vid JOIN {node_revisions} r ON n.vid = r.vid JOIN {schedule_email_type} sety ON sety.setid = se.setid WHERE se.enabled = 1 GROUP BY n.nid");
    }
    else {
      $result = db_query("SELECT MAX(n.vid) vid, n.nid, n.title, se.seid, se.setid, se.days, se.subject, r.body, r.format, sety.name, sety.name_short FROM {schedule_email} se JOIN {node} n ON n.vid = se.vid JOIN {node_revisions} r ON n.vid = r.vid JOIN {schedule_email_type} sety ON sety.setid = se.setid WHERE se.enabled = 1 AND se.setid = %d GROUP BY n.nid", $type_id);
    }
    $rows = array();
    while ($row = db_fetch_object($result)) {
      $rows[$row->nid] = $row;
    }
    return $rows;
  }

  protected function get_registered_users_to_email($scheduled_email) {
    $accounts = array();
    $days_ago_timestamp = strtotime($scheduled_email->days . ' day ago');
    if (!$days_ago_timestamp) {
      return;
    }
    $result = db_query("SELECT u.uid from {users} u LEFT JOIN {schedule_email_sent} ses ON u.uid = ses.uid AND ses.seid = %d LEFT JOIN {node} n ON n.uid=u.uid WHERE n.type = 'retail_member' AND DATE(FROM_UNIXTIME(%d)) = DATE(FROM_UNIXTIME(u.created)) AND ses.uid IS NULL", $scheduled_email->seid, $days_ago_timestamp);

    while ($account = db_fetch_object($result)) {
      $accounts[] = user_load($account->uid);
    }
    return $accounts;
  }

  protected function get_invited_users_to_email($scheduled_email) {
    $accounts = array();
    $days_ago_timestamp = strtotime($scheduled_email->days . ' day ago');
    if (!$days_ago_timestamp) {
      return;
    }
    $result = db_query("SELECT i.* FROM {invite} i LEFT JOIN {schedule_email_sent} ses ON i.iid = ses.iid AND ses.seid = %d WHERE DATE(FROM_UNIXTIME(%d)) = DATE(FROM_UNIXTIME(i.created)) AND i.joined = 0 AND ses.iid IS NULL", $scheduled_email->seid, $days_ago_timestamp);
    while ($account = db_fetch_array($result)) {
      $account['mail'] = $account['email'];
      $account['inviter'] = $account['uid'];
      $inviter_user = user_load($account['uid']);
      $account['from-mail'] = $inviter_user->mail;
      $account['from-name'] = plantright_get_user_profile_name($inviter_user);
      $account['data'] = unserialize($account['data']);
      unset($account['uid']);
      $accounts[] = $account;
    }
    return $accounts;
  }

  /**
   *
   * @param type $email
   *   email parameters
   * @param type $accounts
   *   for mimemail, has to be user object or an array with name and email
   */
  public function send_scheduled_email($email, $accounts, $node = NULL) {
    //need: to, from, subject, body
    foreach ($accounts as $account) {
      $key = $email->name_short;
      $to = isset($account->mail) ? $account->mail : $account['mail'];
      $language = isset($account->language) && $account->language ? $account->language : language_default();

      $array = is_array($account);
      if ($array && isset($account['from-mail']) && isset($account['from-name'])) {
        $from = $account['from-name'] . '<' . $account['from-mail'] . '>';
      }
      else if ($array && isset($account['from-mail'])) {
        $from = $account['from-mail'];
      }
      else if ($array && isset($account['from-name'])) {
        $from = $account['from-name'] . '<' . variable_get('site_mail', '') . '>';
      }
      else {
        $from = variable_get('site_mail', '');
      }
      $send = TRUE;

      $params['subject'] = check_plain(decode_entities($email->subject));
      $params['message'] = check_markup(decode_entities($email->body), $email->format);
      $params = $this->handle_replacements($params, $account, $node);

      if (function_exists('mimemail')) {
        mimemail($from, $to, $params['subject'], $params['message']);
      }
      else {
        drupal_mail('schedule_email', $key, $to, $language, $params, $from, $send);
      }

      $this->log_email_sent($email, $account, $node->nid);
    }
  }

  private function handle_replacements($params, $account, $node = NULL) {
    if ($node) {
      foreach ($params as &$param) {
        $param = token_replace_multiple($param, array('node' => $node));
      }
    }

    if (isset($account->uid)) {
      // Account is a user account.
      foreach ($params as &$param) {
        $param = token_replace_multiple($param, array('global' => NULL, 'user' => $account, 'profile' => $account));
      }
      return $params;
    }
    else if (is_array($account) && isset($account['iid'])) {
      // An invitation.
      $substitutions = _invite_substitutions(array(
        'inviter' => user_load($account['inviter']),
        'email' => $account['email'],
        'code' => $account['reg_code'],
        'resent' => $account['resent'],
        'data' => array('subject' => $account['data']['subject'], 'message' => $account['data']['message']),
          ));
      foreach ($params as &$param) {
        $param = token_replace_multiple($param, _invite_token_types($substitutions));
      }
      return $params;
    }
  }

  private function log_email_sent_db($seid, $account, $nid) {
    if (isset($account->uid) && $account->uid) {
      $uid = $account->uid;
      $iid = 0;
    }
    else {
      $uid = 0;
      $iid = isset($account->iid) ? $account->iid : $account['iid'];
    }
    schedule_email_log_email($seid, $uid, $iid, $nid);
  }

  public function log_email_sent($email, $account, $nid) {
    $this->log_email_sent_db($email->seid, $account, $nid);
    $message = t("Sent @mail email %name", array('@mail' => (isset($account->mail) ? $account->mail : $account['mail']), '%name' => $email->title));
    watchdog('schedule_email', $message);
    $this->sent_log[] = $message;
  }

  public function get_email_log() {
    return $this->sent_log;
  }

}