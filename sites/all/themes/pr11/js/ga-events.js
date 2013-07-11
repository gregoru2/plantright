/**
 * @file
 * Contains code for Google Analytics event tracking.
 */

jQuery(document).ready(function($) {
  var filetypes = /\.(rtf|txt|zip|exe|pdf|doc.?|xl.{0,2}|ppt.{0,2}|mp3)$/i;
  var baseHref = 'http://' + document.domain;

  $('a').each(function() {
    var href = $(this).attr('href');
    if (href && (href.match(/^https?\:/i)) && (!href.match(document.domain))) {
      $(this).click(function(e) {
        e.preventDefault();
        window.open(href);
        _gaq.push(['_trackEvent', 'External', 'Click', extLink]);
      });
      $(this).mousedown(function(e) {
        if (e.which == 1) {
          return;
        }

        var extLink = href.replace(/^https?\:\/\//i, '');
        window.open(href);
        _gaq.push(['_trackEvent', 'External', 'Click', extLink]);
      });
    }
    else if (href && href.match(/^mailto\:/i)) {
      $(this).mousedown(function(e) {
        var mailLink = href.replace(/^mailto\:/i, '');
        _gaq.push(['_trackEvent', 'Email', 'Click', mailLink]);
      });
    }
    else if (href && href.match(filetypes)) {
      $(this).click(function(e) {
        e.preventDefault();
        window.open(href);
        _gaq.push(['_trackEvent', 'Download', extension, filePath]);
      });
      $(this).mousedown(function(e) {
        if (e.which == 1) {
          return;
        }

        var extension = (/[.]/.exec(href)) ? /[^.]+$/.exec(href) : undefined;
        var filePath = href;
        window.open(href);
        _gaq.push(['_trackEvent', 'Download', extension, filePath]);
      });
    }
    else if (href && href.match(/.*\/certificate\/pdf/i)) {
      $(this).mousedown(function(e) {
        var filePath = href;
        _gaq.push(['_trackEvent', 'Download', 'pdf', filePath]);
      });
    }
  });
});


