/**
 * Custom javascripts for plantright business directory admin page.
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

//        $locationContainerTemplate = $('fieldset.location:first', $locations).clone();
//        $locationTemplate = $('fieldset.location:first', $locations).html();

        var $input = $('<input type="button" id="pbd-location-add-another" class="form-submit" value="Add another location" />')
        .click(function(e) {
//          if (location_count >= 300) {
//            // No more.
//            $input.after('<p>You have reached the maximum number of locations.</p>');
//            $input.remove();
//          } else {
//            if (location_count >= 100) {
//              // Give warning.
//              $('#location-count-warning').remove();
//              $input.after('<p id="location-count-warning">You have 100 or more locations. You may experience errors attempting to save. Please contact an administrator.</p>');
//            }
//
//            $newLocation = $locationTemplate.replace(/edit-locations-0-/g, 'edit-locations-' + location_count + '-').replace(/locations\[0\]/g, 'locations[' + location_count + ']');
//            $newLocationContainer = $locationContainerTemplate.clone();
//            $newLocationContainer.html($newLocation);
//            $newLocationContainer.find('.fieldset-title em').html(location_count + 1);
//            $newLocationContainer.find('input:not(.location_auto_province), select').val('');
//            $newLocationContainer.find('#edit-locations-' + location_count + '-delete-location-wrapper').remove();
//            $input.before($newLocationContainer);
//            location_count++;
//          }

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
