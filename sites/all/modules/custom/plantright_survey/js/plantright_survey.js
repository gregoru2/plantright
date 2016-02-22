Drupal.behaviors.plantright_survey = function (context) {
  var survey_selector = '#plantright-survey-form';
  var survey_data_selector = survey_selector + '.plantright-survey-data-form';
  var survey_photo_selector = survey_selector + '.plantright-survey-photos-form';

  // Dev note: because radios don't have identifing container, only one set
  // of radio buttons can be in the given container.
  // If another needs added, you need a method of identifying the radios.
  $(survey_photo_selector + ' input.form-radio, ' + survey_data_selector + ' .group-survey-basic input.form-radio').click(function() {
    var code = $(this).siblings('span.views-field-field-store-code-value').children('.field-content').html();
    $('input#edit-title').val(code);
  });

  // Hide the store code value on the survey photos and survey data
  // for choosing the store name/code field.
  $(survey_selector + ' .views-field-field-store-code-value').hide();

  // Change the value of the input for survey photos.
  $(survey_photo_selector + '#edit-field-survey-image-field-survey-image-add-more').val('Add another photo');

  // Hide the date segment labels on the survey data date.
  var $survey_data = $(survey_data_selector);
  $survey_data.find('.date-month label, .date-day label, .date-year label').hide();

  // Handle survey data species data.
  var showItems = function($container) {
  // Show all except the first (did you find) and last field (which is the related genus)
    $container.find('.fieldset-content > .form-item-labeled').slice(1, -1).slideDown();
    $container.find('input.form-text').each(function() {
      var $elem = $(this);
      $elem.val($elem.data('pr-survey-val'))
    });
  };
  var hideItems = function($container) {
  // Hide all except the first (did you find) and last field (which is the related genus)
    $container.find('.fieldset-content > .form-item-labeled').slice(1, -1).slideUp();

    // Clear the values so none is saved if "no" selected.
    $container.find('input.form-text').each(function() {
      var $elem = $(this);
      if ($elem.val()) {
        $elem.data('pr-survey-val', $elem.val());
        $elem.val('');
      }
    });
  };

  var showHide = function($radio) {
    var val = $('input[name=' + $radio.attr('name') + ']:checked').val();
    if (val == 'Yes') {
      showItems($radio.closest('fieldset'));
    }
    else {
      hideItems($radio.closest('fieldset'));
    }
  }

  var index = 1;
  var $fieldset;

  $fieldset = $survey_data.find('form fieldset.group-species' + index);
  while($fieldset.length > 0) {

	// Add indent to all but first and last child fields.
	$fieldset.find('.form-item').filter(':not(:first-child)').filter(':not(:last-child)').addClass('form-item-indent');

    // Add click handler to the radio button.
    $fieldset.find('input:radio').click(function() {
      showHide($(this));
    }).each(function() {
      showHide($(this));
    })

    index++;
    $fieldset = $survey_data.find('form fieldset.group-species' + index)
  }
}
