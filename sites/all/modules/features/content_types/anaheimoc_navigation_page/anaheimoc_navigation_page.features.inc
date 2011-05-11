<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_navigation_page_imagecache_default_presets() {
  $items = array(
    'navigation_article_image' => array(
      'presetname' => 'navigation_article_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '616',
            'height' => '216',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_navigation_page_node_info() {
  $items = array(
    'navigation_page' => array(
      'name' => t('Navigation page'),
      'module' => 'features',
      'description' => t('The navigation page content type is for creating pages to be linked off of the main navigation section or for any other content structures where a parent/child relationship is required.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
