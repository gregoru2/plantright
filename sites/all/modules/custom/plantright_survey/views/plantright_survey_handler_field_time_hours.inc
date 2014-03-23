<?php

/**
 * A handler to get difference in survey time in hours.
 *
 * @ingroup views_field_handlers
 */
class plantright_survey_handler_field_time_hours extends views_handler_field {

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    $diff_seconds = _plantright_survey_diff_field_time_helper($values);
    if ($diff_seconds < 0) {
      return 'time error';
    }
    
    $time = $diff_seconds / 60;
    $hours = floor($time / 60);
    $minutes = ($time % 60);

    $format = '%d:%d';
    return sprintf($format, $hours, $minutes);
  }

}
