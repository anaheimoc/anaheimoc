<?php
// $Id: slideshare.theme.inc,v 1.3 2009/11/25 16:04:43 antoniodemarco Exp $

/**
 * @file
 *
 * Theme functions for Slideshare module
 */

/**
 * Flash embed.
 */
function theme_slideshare_flash($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $matches = array();
  preg_match_all('/<object[^>]*>(.*?)<\/object>/', $item['data']['EMBED'][0], $matches);
  $output = '<object width="'. $width .'" height="'. $height .'" style="margin: 0;">'. $matches[1][0] .'</object>';
  $output = preg_replace('/width="(\d*)"/', 'width="'. $width .'"', $output);
  $output = preg_replace('/height="(\d*)"/', 'height="'. $height .'"', $output);
  return $output;
}