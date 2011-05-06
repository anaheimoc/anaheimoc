<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_microsite_imagecache_default_presets() {
  $items = array(
    'article_image' => array(
      'presetname' => 'article_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '616',
            'height' => '240',
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
function anaheimoc_microsite_node_info() {
  $items = array(
    'microsite' => array(
      'name' => t('Microsite'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Conference Name'),
      'has_body' => '1',
      'body_label' => t('Welcome Message'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
