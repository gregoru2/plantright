/**
 * @file
 * Contains code for Google Analytics event tracking.
 */

jQuery(document).ready(function($) {
  var filetypes = /\.(zip|exe|pdf|doc*|xls*|ppt*|mp3)$/i;
  var baseHref = 'http://' + document.domain;

  $('a').each(function() {
    var href = $(this).attr('href');
    if (href && (href.match(/^https?\:/i)) && (!href.match(document.domain))) {
      $(this).mousedown(function(e) {
        var extLink = href.replace(/^https?\:\/\//i, '');
        _gaq.push(['_trackEvent', 'External', 'Click', extLink]);
        if ($(this).attr('target') == undefined || $(this).attr('target').toLowerCase() != '_blank') {
          e.preventDefault();
          setTimeout(function() {
            window.open(href);
          }, 200);
          return false;
        }
      });
    }
    else if (href && href.match(/^mailto\:/i)) {
      $(this).mousedown(function(e) {
        var mailLink = href.replace(/^mailto\:/i, '');
        _gaq.push(['_trackEvent', 'Email', 'Click', mailLink]);
      });
    }
    else if (href && href.match(filetypes)) {
      $(this).mousedown(function(e) {
        var extension = (/[.]/.exec(href)) ? /[^.]+$/.exec(href) : undefined;
        var filePath = href;
        //_gaq.push(['_trackEvent', 'Download', extension, filePath]);
        if ($(this).attr('target') == undefined || $(this).attr('target').toLowerCase() != '_blank') {
          e.preventDefault();
          setTimeout(function() {
            window.open(href);
          }, 200);
          return false;
        }
      });
    }
  });
});


