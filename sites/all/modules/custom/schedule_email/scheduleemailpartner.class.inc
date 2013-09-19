<?php

/**
 * @file
 *
 * Send email class
 */
class ScheduleEmailPartner extends ScheduleEmail {
  public function __construct($send = TRUE) {
    if ($send) {
      $types = self::get_types(TRUE);

      $setid = array_search('partner_liason', $types);
      $emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($emails as $scheduled_email) {
        $matches = $this->get_partner_liasons_to_email($scheduled_email);
        foreach ($matches as $match) {
          if (!empty($match) && !empty($match['accounts'])) {
            $this->send_scheduled_email($scheduled_email, $match['accounts'], $match['node']);
          }
        }
      }

      $setid = array_search('partner_nonliason', $types);
      $emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($emails as $scheduled_email) {
        $matches = $this->get_partner_nonliasons_to_email($scheduled_email);
        foreach ($matches as $match) {
          if (!empty($match) && !empty($match['accounts'])) {
            $this->send_scheduled_email($scheduled_email, $match['accounts'], $match['node']);
          }
        }
      }
    }
  }

  private function get_partner_liasons_to_email($scheduled_email) {
    $days_ago_timestamp = strtotime($scheduled_email->days . ' day ago');
    if (!$days_ago_timestamp) {
      return;
    }

    $matches = array();
    $result =  db_query("SELECT n.nid FROM {node} n INNER JOIN {content_type_business} ctb ON n.nid=ctb.nid LEFT JOIN {schedule_email_sent} ses ON n.nid = ses.nid AND ses.seid = %d WHERE DATE(FROM_UNIXTIME(%d)) = DATE(ctb.field_is_certified_date_value) AND ses.nid IS NULL", $scheduled_email->seid, $days_ago_timestamp);

      while ($result = db_fetch_object($result)) {
        if ($result) {
          $nid = $result->nid;
          $node = node_load($nid);
          $accounts = array(user_load($node->uid));
          $matches[] = array(
            'accounts' => $accounts,
            'node' => $node
          );
        }
      }

    return $matches;
  }

  private function get_partner_nonliasons_to_email($scheduled_email) {
    $days_ago_timestamp = strtotime($scheduled_email->days . ' day ago');
    if (!$days_ago_timestamp) {
      return;
    }

    $matches = array();
    $result =  db_query("SELECT n.nid FROM {node} n INNER JOIN {content_type_business} ctb ON n.nid=ctb.nid LEFT JOIN {schedule_email_sent} ses ON n.nid = ses.nid AND ses.seid = %d WHERE DATE(FROM_UNIXTIME(%d)) = DATE(ctb.field_is_certified_date_value) AND ses.nid IS NULL", $scheduled_email->seid, $days_ago_timestamp);
     while ($result = db_fetch_object($result)) {
      if ($result) {
        $nid = $result->nid;
        $node = node_load($nid);
        // Get refferrer users that are not owner.
        $accounts = plantright_get_retailer_employees($node, FALSE);

        $matches[] = array(
          'accounts' => $accounts,
          'node' => $node
        );
      }
    }

    return $matches;
  }

}