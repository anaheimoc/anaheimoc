<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_sybas_page_imagecache_default_presets() {
  $items = array(
    'sybas_page_image' => array(
      'presetname' => 'sybas_page_image',
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
function anaheimoc_sybas_page_node_info() {
  $items = array(
    'sybas_page' => array(
      'name' => t('Show Your Badge and Save Page'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
