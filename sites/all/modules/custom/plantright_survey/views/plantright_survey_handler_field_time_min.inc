<?php

/**
 * A handler to get difference in survey time in minutes
 *
 * @ingroup views_field_handlers
 */
class plantright_survey_handler_field_time_min extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    $diff_seconds = _plantright_survey_diff_field_time_helper($values);
    return $diff_seconds / 60;
  }
}


