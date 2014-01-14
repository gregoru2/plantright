Drupal.behaviors.plantright_survey = function (context) {
  $('#page-node-add-survey-photos input.form-radio, #page-node-add-survey-submission input.form-radio, ').click(function() {
    $code = $(this).siblings('span.views-field-field-store-code-value').children('.field-content').html();
    $('input#edit-title').val($code);
  });
  $('#page-node-add-survey-submission .date-month label, #page-node-add-survey-submission .date-day label, #page-node-add-survey-submission .date-year label,  #page-node-add-survey-photos .views-field-field-store-code-value, #page-node-add-survey-submission .views-field-field-store-code-value').hide();
  $('#page-node-add-survey-photos #edit-field-survey-image-field-survey-image-add-more').val('Add another photo');
}
