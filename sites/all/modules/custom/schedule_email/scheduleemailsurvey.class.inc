<?php

/**
 * @file
 *
 * Send email class for survey emails.
 */
class ScheduleEmailSurvey extends ScheduleEmail {

  public function __construct($send = TRUE) {
    $this->profile_node_type = 'survey_profile';
    if ($send) {
      if (!function_exists('plantright_survey_get_end_dates')) {
        // Can't run if function doesn't exist
        return;
      }

      $types = self::get_types(TRUE);
      $now = time();

      // Keep track of which area has the end emails already sent.
      $emails_sent_for_area_end = array();

      // Send X days before end of survey.
      $setid = array_search('survey_end', $types);
      $emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($emails as $scheduled_email) {
        // Get all area end dates and check the email days requested.
        foreach (plantright_survey_get_end_dates() as $area => $date) {
          // Compare end date with
          $date_to_send = strtotime('-' . $scheduled_email->days . ' days', $date);
          if (date('m/d/Y', $date_to_send) <= date('m/d/Y', $now)) {
            $emails_sent_for_area_end[$area] = $area;
          }

          if (date('m/d/Y', $date_to_send) == date('m/d/Y', $now)) {
            $matches = $this->get_survey_users_by_area_to_email($scheduled_email, $area);
            foreach ($matches as $match) {
              if (!empty($match) && !empty($match['accounts'])) {
                $this->send_scheduled_email($scheduled_email, $match['accounts'], $match['node']);
              }
            }
          }
        }
      }

      // Check if any survey area is still open. And hasn't had the survey end
      // email sent.
      // If not, return.
      $all_end_dates = plantright_survey_get_end_dates();
      $survey_areas_open = array();
      $today = strtotime('today midnight');
      foreach ($all_end_dates as $area => $end_date) {
        if ($today < $end_date && !isset($emails_sent_for_area_end[$area])) {
          $survey_areas_open[$area] = $area;
        }
      }

      if (empty($survey_areas_open)) {
        return;
      }

      // At least one survey area is open and hasn't had an end email sent.
      $setid = array_search('survey_register', $types);
      $emails = $this->get_schedule_emails_by_typeid($setid);
      foreach ($emails as $scheduled_email) {
        $matches = $this->get_registered_users_to_email($scheduled_email, $survey_areas_open);
        foreach ($matches as $match) {
          if (!empty($match) && !empty($match['accounts'])) {
            $this->send_scheduled_email($scheduled_email, $match['accounts'], $match['node']);
          }
        }
      }
    }
  }

  /**
   * Get the users belonging to a survey area who have chosen a nursery to survey
   * but not submitted data for it.
   * @param object $scheduled_email
   * @param string $area
   * @return array
   */
  protected function get_survey_users_by_area_to_email($scheduled_email, $area) {
    // User needs to have a survey profile and a store chosen.
    $counties = plantright_survey_get_counties_by_area($area);
    $counties_string = implode("', '", $counties);
    $counties_string = "'" . $counties_string . "'";

    $query = "SELECT n.nid, n.uid FROM {node} n JOIN {content_type_survey_profile} ctsp ON n.nid=ctsp.nid
      LEFT JOIN {schedule_email_sent} ses ON n.uid = ses.uid AND ses.seid = %d
      LEFT JOIN {content_field_county_1} cfc ON ctsp.vid = cfc.vid
      WHERE cfc.field_county_1_value IN(" . $counties_string . ") AND ses.nid IS NULL";
    $result = db_query($query, $scheduled_email->seid);

    $rows = array();
    while ($row = db_fetch_object($result)) {
      if ($row) {
        $rows[] = $row;
      }
    }
    return $this->filter_matches_to_users_with_nursery_and_no_data_submitted($rows);
  }

  /**
   * Get the users that registered X days ago in survey areas that are still open
   * and who have claimed a nursery but not submitted data for it.
   * @param object $scheduled_email
   * @return array
   */
  protected function get_registered_users_to_email($scheduled_email, $areas = null) {
    $days_ago_timestamp = strtotime($scheduled_email->days . ' day ago');
    if (!$days_ago_timestamp) {
      return;
    }

    $select = "SELECT u.uid from {users} u 
      LEFT JOIN {schedule_email_sent} ses ON u.uid = ses.uid AND ses.seid = %d 
      LEFT JOIN {node} n ON n.uid=u.uid 
      LEFT JOIN {content_type_survey_profile} ctsp ON n.nid=ctsp.nid
      LEFT JOIN {content_field_county_1} cfc ON ctsp.vid = cfc.vid
      WHERE n.type = '" . $this->profile_node_type . "' 
        AND DATE(FROM_UNIXTIME(%d)) = DATE(FROM_UNIXTIME(u.created)) 
        AND ses.uid IS NULL";

    if ($areas) {
      $counties = array();
      foreach ($areas as $area) {
        $temp = plantright_survey_get_counties_by_area($area);
        $counties = array_merge($counties, $temp);
      }

      $counties_string = implode("', '", $counties);
      $counties_string = "'" . $counties_string . "'";
      $select .= " AND cfc.field_county_1_value IN(" . $counties_string . ")";
    }

    $result = db_query($select, $scheduled_email->seid, $days_ago_timestamp);

    $rows = array();
    while ($row = db_fetch_object($result)) {
      if ($row) {
        $rows[] = $row;
      }
    }
    return $this->filter_matches_to_users_with_nursery_and_no_data_submitted($rows);
  }

  protected function filter_matches_to_users_with_nursery_and_no_data_submitted($rows) {
    $matches = array();
    foreach ($rows as $row) {
      $node = null;
      $flags = flag_get_user_flags('node', null, $row->uid);
      $data_submitted = true;
      if (count($flags) && isset($flags[PLANTRIGHT_FLAG_SURVEY])) {
        foreach ($flags[PLANTRIGHT_FLAG_SURVEY] as $flag) {
          $nid = $flag->content_id;
          $data_nodes = nodereferrer_referrers($nid, array('field_store_name'), array('survey_data'));
          if ($nid && !$data_nodes) {
            $data_submitted = false;
            $node = node_load($nid);
            break;
          }
        }
      }
      if (!$data_submitted) {
        $accounts = array(user_load($row->uid));
        $matches[] = array(
          'accounts' => $accounts,
          'node' => $node
        );
      }
    }
    return $matches;
  }

}