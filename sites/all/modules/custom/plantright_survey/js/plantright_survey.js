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

  // IMAGE UPLOAD VIA IMAGEFIELD_ZIP
  // Not using the Drupal context, because context won't include the full form when images change.
  var $photoForm = $(survey_photo_selector);
  var $imgsTable = $photoForm.find('#field_survey_image_values');

  // Change header.
  $imgsTable.find('thead').hide();
  $imgsTable.before('<div class="form-item">\n\
    <label>Photos: <span class="form-required" title="This field is required.">*</span></label>\n\
    <p class="survey-photo-upload-note">Click the button below to upload your photos and provide descriptions. In the description field, please include the plant name and specify if the photo is of the plant itself or the plant\'s tag (e.g.: Pampas grass, tag).</p>\n\
    <p class="survey-photo-issues-note">Please note that you may now upload photos directly from your mobile devices (including iOS and Android devices). Please wait for all photos to load before clicking “Submit.” If you encounter errors submitting your photos, please contact <a href="mailto:PlantRight@suscon.org">PlantRight@suscon.org</a>. Thank you!</p>\n\
  </div>');

  // Hide all rows with file inputs to fix weird behavior of imagefield zip that shows empty file inputs.
  // (Use file inputs because ones that are multi upload have an image not input
  $imgsTable.find('tbody tr').each(function(index, val) {
    var $row = $(val);
    if ($row.find('input[type=file]').length > 0) {
      $row.hide();
    } else {
      // Show.
      $row.show();
      // Set desc to the filename (if filename is empty)
      var $imgPreview = $row.find('.imagefield-preview img');
      var $descInput = $row.find('input[type=text]');
      if ($imgPreview.length > 0 && $descInput.length > 0 && $descInput.val() === '') {
        var desc = $imgPreview.attr('title')
        if (!desc || desc === '') {
          // Title is empty. Use src.
          desc = $imgPreview.attr('src');
          desc = desc.substring(desc.lastIndexOf('/') + 1);
        }
        // Remove file extension from desc.
        desc = desc.replace(/\.[^.]+$/, '');
        $descInput.val(desc);
      }
    }
  });

  // Hide the add more button right after the images table.
  $photoForm.find('#field_survey_image_values + .content-add-more').hide();

  // Hide the "Multiple image label"
  $photoForm.find('label[for=edit-field-survey-image-upload]').hide();

  // Hide the "Start Upload" button because we're auto starting on input change.
  $photoForm.find('.zip-field input[type=submit]').hide();
  
  // Executed each time the files change. So resetting the file input to show and removing any throbbers.
  $photoForm.find('.zip-field input[type=file]').show();
  $photoForm.find('.zip-field .ahah-progress, .zip-field .throbber').remove();

  // Listen for the zip field input change in order to automatically start the upload
  // Because imagefield makes users click the start button
  $photoForm.find('.zip-field input[type=file]').unbind('change.pr-upload-change').bind('change.pr-upload-change', function() {
    // Click the "Start Upload" button.
    var $btn = $photoForm.find('.zip-field input[type=submit]');
    if (!$btn.hasClass('pr-btn-clicked')) {
      // Don't call mousedown twice within 200 milliseconds
      $btn.trigger('mousedown').addClass('pr-btn-clicked');
      $photoForm.find('.zip-field input[type=file]').hide();
      setTimeout(function() {
        $btn.removeClass('pr-btn-clicked');
      }, 200);
    }
  });
  // END IMAGEFIELD ZIP UPLOAD CUSTOMIZATIONS
  
  // Let them know max size applies to all.
  var $sizeDesc = $('.zip-field .zip-description');
  var desc = $sizeDesc.html().replace('Maximum filesize', '<br/>Maximum size per photo batch');
  desc += '. (You may upload in multiple batches if the total of all your images are larger.)';
  $sizeDesc.html(desc);

  // Disable submit until images are uploaded 
  var throbber = '<div class="ahah-progress ahah-progress-throbber"><div class="throbber">&nbsp;</div></div>';
  var triesLeft = 120;
  $photoForm.find('input[type=submit][value=Submit]').bind('mousedown', function(e) {
    var $button = $(this);
    $photoForm.find('#pr-survey-js-valid-msg').remove();
    var validFail = false;
    if ($photoForm.find('.zip-field .throbber').length > 0) {
      validFail = throbber + ' Submitting... Your images are still uploading. Large files may time some time to complete.<br/> Please do not navigate away from this page. (You may change to another application and return.)';
      if (triesLeft > 0) {
        triesLeft--;
        setTimeout(function() {
          $button.trigger('mousedown');
        }, 1000);
      }
    }
    
    if (!validFail && $photoForm.find('#field-survey-image-items .error').length > 0) {
      validFail = 'There was a problem uploading one or more of your photos';
    }
    
    if (!validFail && $photoForm.find('#field_survey_image_values .imagefield-preview').length < 1) {
      validFail = 'You have not uploaded any photos';
    }

    if (validFail) {
      $button.before('<label id="pr-survey-js-valid-msg" class="error"><strong>' + validFail + '</strong></label>');
      e.stopPropagation();
      e.preventDefault();
      return false;
    }
  });

}
