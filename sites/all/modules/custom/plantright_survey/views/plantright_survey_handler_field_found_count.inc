<?php

/**
 * A handler to provide a field to add the count of plant species found.
 *
 * @ingroup views_field_handlers
 */
class plantright_survey_handler_field_found_count extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function render($values) {
    $val = 0;
    foreach ($values as $key => $value) {
      if (preg_match('/field_species\d+_found_value/', $key) && 'Yes' == $value) {
        $val++;
      }
    }
    return $val;
  }
}
