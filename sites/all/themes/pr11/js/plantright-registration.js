// Handle registgration popup, node 2392.
Drupal.behaviors.plantright_registration = function (context) {
  var choice_step_1 = null; // Primary contact.
  var choice_step_2 = null; // Buyer.

  $('#node-2392', context).each(function(){
    var $node = $(this);
    if (choice_step_1 === null) {
      $('#pr-reg-choices-2', $node).hide();
    }

    $('#pr-reg-choices-1 li.choice', $node).click(function(e) {
      e.preventDefault();
      var $chosen = $(this);
      if (choice_step_1 === null) {
        if ($chosen.hasClass('choice-yes')) {
          choice_step_1 = 1;
        }
        else {
          choice_step_1 = 0;
        }

        $('#pr-reg-choices-1 li.choice').not(this).fadeOut(400, function() {
          $('#pr-reg-choices-2', $node).slideDown();
        });
      }
      else {
        choice_step_1 = null;
        choice_step_2 = null;
        $('#pr-reg-choices-2', $node).slideUp(400, function() {
          $('#pr-reg-choices-1 li.choice').not(this).fadeIn(400);
        });

      }
    });
    $('#pr-reg-choices-2 li.choice', $node).click(function(e) {
      e.preventDefault();
      var $chosen = $(this);
      if ($chosen.hasClass('choice-yes')) {
        choice_step_2 = 1;
      }
      else {
        choice_step_2 = 0;
      }

      var location = '';
      if (choice_step_1 == 0 && choice_step_2 == 0) {
        // Not primary contact. Not buyer.
        location = '/retail-employee/register';
      }
      else if (choice_step_1 == 0 && choice_step_2 == 1) {
        // Not primary contact. Buyer.
        location = '/employee-buyer/register';
      }
      else if (choice_step_1 == 1 && choice_step_2 == 0) {
        // Primary contact. Not buyer.
        location = '/retail-manager/register';
      }
      else if (choice_step_1 == 1 && choice_step_2 == 1) {
        // Primary contact. Buyer.
        location = '/manager-buyer/register';
      }

      if (location && parent) {
        parent.window.location = location;
      }
      else if (location) {
        window.location = location;
      }
    });
  });
}
