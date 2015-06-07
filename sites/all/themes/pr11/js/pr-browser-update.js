//Drupal.behaviors.pr_browser_update = function (context) {
//
//  /**
//   * http://codepen.io/gapcode/pen/vEJNZN
//   * detect IE
//   * returns version of IE or false, if browser is not Internet Explorer
//   */
//  function detectIE() {
//    var ua = window.navigator.userAgent;
//
//    var msie = ua.indexOf('MSIE ');
//    if (msie > 0) {
//      // IE 10 or older => return version number
//      return parseInt(ua.substring(msie + 5, ua.indexOf('.', msie)), 10);
//    }
//
//    var trident = ua.indexOf('Trident/');
//    if (trident > 0) {
//      // IE 11 => return version number
//      var rv = ua.indexOf('rv:');
//      return parseInt(ua.substring(rv + 3, ua.indexOf('.', rv)), 10);
//    }
//
//    var edge = ua.indexOf('Edge/');
//    if (edge > 0) {
//      // IE 12 => return version number
//      return parseInt(ua.substring(edge + 5, ua.indexOf('.', edge)), 10);
//    }
//
//    // other browser
//    return false;
//  }
//
//  function getParameterByName(name) {
//    var match = RegExp('[?&]' + name + '=([^&]*)').exec(window.location.search);
//    return match && decodeURIComponent(match[1].replace(/\+/g, ' '));
//  }
//
//  // no popup query param. (popup query param can't be with any other params.
//  if (window.location.search !== '?popup') {
//    if (detectIE() !== false) {
//      // Check if shown in last 10 min.
//      var requestedAt = document.cookie.replace(/(?:(?:^|.*;\s* )iePromptTime\s*\=\s*([^;]*).*$)|^.*$/, "$1");
//      var now = new Date().getTime();
//      var cacheTime = 10 * 60 * 1000;
//      if (now - requestedAt > cacheTime) {
//        document.cookie = "iePromptTime=" + new Date().getTime();
//        var url = '/node/5780' + '?popup';
//        var $link = $('<a href="' + url + '" rel="lightframe"></a>').bind('click', function() {
//          Lightbox.start(this, false, true, false, false);
//        });
//        $link.css({
//          display:'none'
//        });
//        $('body').append($link);
//        $link.click();
//      }
//    }
//    else {
//      // Not IE. Add update browser script.
//      try {
//        var s = document.createElement('script');
//        s.type = 'text/javascript';
//        s.async = true;
//        s.src = ('https:'==document.location.protocol?'https://':'http://') + 'updatemybrowser.org/umb.js';
//        var b = document.getElementsByTagName('script')[0];
//        b.parentNode.insertBefore(s, b);
//      } catch(e) {}
//    }
//  }
//
//};
