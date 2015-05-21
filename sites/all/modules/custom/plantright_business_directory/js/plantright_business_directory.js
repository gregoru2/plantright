/**
 * Custom javascripts for plantright.
 */
Drupal.behaviors.plantright_bus_dir = function(context) {
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

        var $input = $('<input type="button" id="pbd-location-add-another" class="form-submit" value="Add another location" />')
        .click(function(e) {
          if (location_count >= 100) {
            $('#location-count-warning').remove();
            $input.after('<p id="location-count-warning">You have 100 or more locations. You may experience errors attempting to save. Please contact an administrator.</p>');
          }


          if ($('fieldset.location:nth-child(' + (location_count + 1) + ')').length > 0) {
            $('fieldset.location:nth-child(' + (location_count + 1) + ')').show();
            location_count++;
          }
          else if (location_count < 300) {
            if (Drupal.settings.plantright_business_directory.canEditBusiness) {
              $input.after('<p>You have reached the maximum number of locations that can be entered at one time. Please save and edit again to add more.</p>');
            }
            else {
              $input.after('<p>You have reached the maximum number of locations that can be entered. Please contact us to add more.</p>');
            }
            $input.remove();
          }
          else {
            $input.after('<p>You have reached the maximum number of locations.</p>');
            $input.remove();
          }

        });
        $locations.append($input);
      }
    }
  });
}
