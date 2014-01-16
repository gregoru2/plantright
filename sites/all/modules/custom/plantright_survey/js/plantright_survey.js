Drupal.behaviors.plantright_survey = function (context) {
  // Dev note: because radios don't have identifing container, only one set
  // of radio buttons can be in the given container.
  // If another needs added, you need a method of identifying the radios.
  $('#page-node-add-survey-photos input.form-radio, #page-node-add-survey-submission .group-survey-basic input.form-radio, ').click(function() {
    $code = $(this).siblings('span.views-field-field-store-code-value').children('.field-content').html();
    $('input#edit-title').val($code);
  });
  $('#page-node-add-survey-submission .date-month label, #page-node-add-survey-submission .date-day label, #page-node-add-survey-submission .date-year label,  #page-node-add-survey-photos .views-field-field-store-code-value, #page-node-add-survey-submission .views-field-field-store-code-value').hide();
  $('#page-node-add-survey-photos #edit-field-survey-image-field-survey-image-add-more').val('Add another photo');
}
