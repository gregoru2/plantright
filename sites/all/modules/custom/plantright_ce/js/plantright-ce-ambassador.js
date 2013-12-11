/**
 * Custom javascripts for plantright continuing education ambassador agreement.
 */
Drupal.behaviors.plantright_ce_ambassador = function(context) {
  var is_ambassador = Drupal.settings.plantright_ce.ambassador;
  if (is_ambassador) {
    $('#ce-resources-terms').hide();
    $('#ce-resources-resources').show();
  }
  else {
    var $terms_container = $('#ce-resources-terms').show();
    var $terms_resources = $('#ce-resources-resources').hide();
    
    var $terms = $terms_container.find('.ce-resources-term').hide();
    var $terms_success = $terms_container.find('.ce-resources-success').hide();
    var $terms_intro = $terms_container.find('.ce-resources-terms-intro');
    
    var handle_term = function(index) {
      if (index < $terms.length) {
        var $current_term = $terms.eq(index);
    
        var $agree_button = $('<div class="ce-resources-term-agree">I Agree</div>');
        $current_term.show();
        $current_term.append($agree_button);
        $agree_button.click(function(e) {
          $current_term.hide();
          handle_term(index + 1);
        });
      }
      else {
        $terms_success.show();
        $terms_resources.show();
        $terms_intro.hide();
        $.ajax({
          url: '/ajax/plantright-ce-ambassador'
        }).success(function(data) {
          console.log(data);
        });
      }
    }

    handle_term(0);

    
  }
  
}
