/**
 * Custom javascripts for plantright.
 */
Drupal.behaviors.plantright = function(context) {
  // UI for additional locations on a business/retailer node.
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
}
