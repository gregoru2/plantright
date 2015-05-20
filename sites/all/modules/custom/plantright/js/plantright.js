  /**
 * Custom javascripts for plantright.
 */
Drupal.behaviors.plantright = function(context) {
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

}
