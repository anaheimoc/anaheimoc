// $Id: pullquote.js,v 1.1 2010/09/07 21:40:30 stuckagain Exp $ 

Drupal.behaviors.pullquote = function (context) {
  $('span.pullquote:not(.pullquote-processed)', context).each(function () {
    var $span = $(this).addClass('pullquote-processed');
    // For now, paragraphs only. May be extended later on. (simply add ',div')
    var $parent = $span.parent('p');
    if ($parent.length) {
      // Apply conditional pullquote container styling.
      $parent.addClass('pullquote-container');
      $span.clone()
        .addClass('pullquote-quote')
        .prependTo($parent);
    }
  });
};