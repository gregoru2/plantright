/**
 * @file
 * Contains code for Google Analytics event tracking.
 */

Drupal.behaviors.plantright_ga_events = function (context) {
jQuery(document).ready(function($) {
  var filetypes = /\.(rtf|txt|zip|exe|pdf|doc.?|xl.{0,2}|ppt.{0,2}|mp3)$/i;
  var baseHref = 'http://' + document.domain;

  $('a').each(function() {
    var href = $(this).attr('href');
    if (href && (href.match(/^https?\:/i)) && (!href.match(document.domain))) {
      // External Links.
      var log_ext_event = function() {
        var extLink = href.replace(/^https?\:\/\//i, '');
        _gaq.push(['_trackEvent', 'External', 'Click', extLink]);
      }

      // Click on mousedown. Mousedown is for right/middle click.
      // Need to use click for left click to get prevent popup blocking.
      $(this).click(function(e) {
        e.preventDefault();
        window.open(href);
        log_ext_event();
      });
      $(this).mousedown(function(e) {
        if (e.which == 1) { // Exclude left click.
          return;
        }

        window.open(href);
        log_ext_event();
      });
    }
    else if (href && href.match(/^mailto\:/i)) {
      // Mail Links.
      $(this).mousedown(function(e) {
        var mailLink = href.replace(/^mailto\:/i, '');
        _gaq.push(['_trackEvent', 'Email', 'Click', mailLink]);
      });
    }
    else if (href && href.match(filetypes)) {
      // File Links.
      var log_file_event = function() {
        var extension = (/[.]/.exec(href)) ? /[^.]+$/.exec(href) : undefined;
        extension = extension[0];
        var filePath = href;
        _gaq.push(['_trackEvent', 'Download', extension, filePath]);
      }

      // Click on mousedown. Mousedown is for right/middle click.
      // Need to use click for left click to get prevent popup blocking.
      $(this).click(function(e) {
        e.preventDefault();
        log_file_event();
        window.open(href);
      });
      $(this).mousedown(function(e) {
        if (e.which == 1) { // Exclude left click.
          return;
        }

        log_file_event();
        window.open(href);
      });
    }
    else if (href && href.match(/.*\/pdf/i)) {
      // Certificate Links.
      $(this).mousedown(function(e) {
        var filePath = href;
        _gaq.push(['_trackEvent', 'Download', 'pdf', filePath]);
      });
    }
  });
});

}
