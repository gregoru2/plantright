// $Id: tao.js,v 1.1.2.1 2010/09/28 19:39:45 yhahn Exp $

Drupal.behaviors.tao = function (context) {
  $('fieldset.collapsible:not(.tao-processed) > legend > .fieldset-title').each(function() {
    var fieldset = $(this).parents('fieldset').eq(0);
    fieldset.addClass('tao-processed');

    // Expand any fieldsets containing errors.
    if ($('input.error, textarea.error, select.error', fieldset).size() > 0) {
      $(fieldset).removeClass('collapsed');
    }

    // Add a click handler for toggling fieldset state.
    $(this).click(function() {
      if (fieldset.is('.collapsed')) {
        $(fieldset).removeClass('collapsed').children('.fieldset-content').show();
      }
      else {
        $(fieldset).addClass('collapsed').children('.fieldset-content').hide();
      }
      return false;
    });
  });
  $('body#page-node-add-business input#edit-title').change(function(){
    $('span.nursery-name').text($(this).val());
  });

  $('#node-2012').each(function() {
    $('div.partnership p.cta a').click(function(e) {
      e.preventDefault();
      var $link = $(this);
      var url = $link.attr('href');
      $link.attr('href', url + '?popup');
      Lightbox.start(this, false, true, false, false);
      $link.attr('href', url);
    });
  });
};

jQuery(document).ready(function($) {
  if (!Modernizr.textshadow) {
    $('.pr-slide .pr-slide-text').textshadow('2px 7px 5px rgba(0, 0, 0, 0.7)');
    $('.pr-slide .slide-highlight').textshadow('3px 10px 5px rgba(0, 0, 0, 0.5)');
    $('.pr-slide .slide-heading').textshadow('3px 10px 5px rgba(0, 0, 0, 0.5)');
    $('.pr-slide .slide-attr').textshadow('2px 6px 5px rgba(0, 0, 0, 0.5)');
    $('.pr-slide .slide-text-left').textshadow('2px 8px 5px rgba(0, 0, 0, 0.5)');
    $('.pr-slide .slide-link').textshadow('2px 8px 5px rgba(0, 0, 0, 0.5)');
  }

  $('#page-node-add-survey-photos input.form-radio').click(function() {
    $code = $(this).siblings('span.views-field-field-store-code-value').children('.field-content').html();
    //console.log($code);
    $('input#edit-title').val($code);
  });
  $('#page-node-add-survey-photos input#edit-field-survey-image-field-survey-image-add-more').val('Add another photo');
  $('.folded').hide();
  $('.fold').click(function(e) {
    $(this).toggleClass('open');
    $(this).next('.folded').toggle();
    e.preventDefault();
  });
  $('.testimonial-nav a').each(function(){
    if (this.href === window.location.href) {
      this.className += ' active';
    }
  });
  $('div.block-retailer_progress .dropdown').hide();
  $('div.block-retailer_progress a.dropdown-toggle').click(function(e) {
    $(this).toggleClass('expanded');
    $(this).next('.dropdown').toggle();
    e.preventDefault();
  });
  $('#pr-retailer-progress-partnership-steps').each(function(){
    var $box = $(this).append($('<div class="content"></div>').append($('#progress-block').html()));
    $box.addClass('block-retailer-progress');
    $box.find('.content > p').remove();
    $box.find('h2').remove();
    $box.find('h3').remove();

    $('a.dropdown-toggle', $box).click(function(e) {
      $(this).toggleClass('expanded');
      $(this).next('.dropdown').toggle();
      e.preventDefault();
    });
  });

  $('#tabbed .tab-content:not(:first)').hide();
  $('#tabbed h3:first').addClass('active');
  $('#tabbed h3').click(function(){
    var boxHeight,
    thisId = this.id;
    $('#tabbed h3.active').removeClass('active');
    $(this).addClass('active');
    $('.tab-content').hide();
    $('.tab-content.' + thisId).show();
    boxHeight = $('.tab-content.' + thisId).outerHeight();
    $('#tab-box').height(boxHeight);
  });
  $('#block-admin-account li:eq(1)').remove();
  $('ul.primary-tabs li a').each(function(){
    //console.log($(this).text());
    if($(this).text() === 'Invitations') {
      $(this).parent().remove();
    }
  });
  if ($('#page-user-0').length) {
    $('.messages ul').remove();
    $('.messages').remove();
    $('.status').remove();
    document.title = 'Please activate your account (check your email)';
  }
});