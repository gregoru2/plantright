Drupal.behaviors.plantright_survey = function (context) {
  $('#page-node-add-survey-photos input.form-radio').click(function() {
    console.log(this);
    $code = $(this).siblings('span.views-field-field-store-code-value').children('.field-content').html();
    $('input#edit-title').val($code);
  });
  $('#page-node-add-survey-photos #edit-field-survey-image-field-survey-image-add-more').val('Add another photo');
}
