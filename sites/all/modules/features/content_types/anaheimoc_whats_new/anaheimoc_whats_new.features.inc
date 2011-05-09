<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_whats_new_imagecache_default_presets() {
  $items = array(
    'whats_new_image' => array(
      'presetname' => 'whats_new_image',
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
function anaheimoc_whats_new_node_info() {
  $items = array(
    'whats_new_article' => array(
      'name' => t('What\'s new'),
      'module' => 'features',
      'description' => '',
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
