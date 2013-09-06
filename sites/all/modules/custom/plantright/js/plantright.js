/**
 * Custom javascripts for plantright.
 */
Drupal.behaviors.plantright = function(context) {
  // UI for additional locations on a business/retailer node.
  // Provides a button to show the location fields one at a time.
  $('#node-form', context).each(function() {
    var $form = $(this);
    if (!$form.hasClass('plantright-processed')) {
      $form.addClass('plantright-processed');
      if ($('input[name=form_id]', $form).attr('value') == 'business_node_form') {
        var $locations = $('fieldset.locations', $form);

        var key = 0;
        var location_count = 0;
        $('fieldset.location', $locations).each(function() {
          var $location = $(this);
          var is_empty = true;

          $('input[type=text]', $location).each(function() {
            if (!$(this).hasClass('location_auto_province') && $(this).val()) {
              is_empty = false;
              return false;
            }
          });
          if (is_empty && key > 0) {
            $location.hide();
          }
          else {
            location_count++;
          }
          key++;
        });

        var $input = $('<input type="button" class="form-submit" value="Add another location" />')
        .click(function(e) {
          $('fieldset.location:nth-child(' + (location_count + 1) + ')').show();
          location_count++;

        });
        $locations.append($input);
      }
    }
  });

  /**
 * Customizations for the user registration and login forms.
 * Handles usernames for shared and simliar email addresses.
 */
  $('#user-login-form #edit-name-wrapper label').text('Email:');

  // Show/hide/clear the username field.
  $('#user-register #edit-name', context).each(function() {
    var $name = $(this);
    var mail_val = $('#edit-mail').val();
    var default_name = $('#edit-mail', context).val().split('@')[0];

    if ($name.hasClass('error') && mail_val != '' && mail_val.indexOf('@') > -1) {
      // Username has an error, because it is a shared email.
      if ($name.val() == default_name) {
        // Determine if value is the default based on mail.
        // If it is, empty the field.
        $name.val('');
      }

    }
    else if ($name.val() == default_name) {
      // Hide the username only if it matches the email address' default.
      $name.parent('.form-item').hide();
    }
  });

  // On form submit, automatically set the username field when it's hidden.
  $('form#user-register', context).submit(function(e){
    var $form = $(this);
    if (!$('#edit-name', $form).is(':visible')) {
      var $name = $('#edit-mail', $form).val().split('@')[0];
      $('#edit-name', $form).val($name);
    }
  });

  // Customize the bulk upload on nursery survey photos to empty the desc.
  if (Drupal.settings.swfupload_settings && SWFUpload != undefined && SWFUpload.instances['SWFUpload_0'] != undefined) {
    var settings = Drupal.settings.swfupload_settings;
    for (var id in settings) {
      if (id == 'edit-field-survey-image') {
        if (Drupal.swfu != undefined && Drupal.swfu[id] != undefined) {
          var instance = Drupal.swfu[id];
          $('#swfupload_file_wrapper-field_survey_image td.title').each(function() {
            var $this = $(this);
            var desc = $('input.form-textfield', $this).show().val();
            var filename = $('div.wrapper > span', $this).hide().text();
            if (filename == '[filename]' || filename == '') {
              $('input.form-textfield', $this).val('');
            }
            setTimeout(function() {
              $('a.toggle-editable', $this).remove(); 
            }, 50)
          });
          $('td.icon .sfwupload-list-mime').css('height', '100px').css('width', '100px');
        
        }
      }
    };
  };
}
