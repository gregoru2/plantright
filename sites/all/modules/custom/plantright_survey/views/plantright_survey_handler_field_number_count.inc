<?php

/**
 * A handler to provide a field to add the number of plant species found.
 *
 * @ingroup views_field_handlers
 */
class plantright_survey_handler_field_number_count extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    $val = 0;
    foreach ($values as $key => $value) {
      if (preg_match('/field_species\d+_number_value/', $key) && $value && $value > 0) {
//        $val += $value;
        $val++;
      }
    }
    return $val;
  }
}
