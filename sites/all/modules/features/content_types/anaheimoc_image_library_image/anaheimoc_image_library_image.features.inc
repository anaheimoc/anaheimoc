<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_image_library_image_imagecache_default_presets() {
  $items = array(
    'image_library_watermark' => array(
      'presetname' => 'image_library_watermark',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '300',
            'height' => '',
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
function anaheimoc_image_library_image_node_info() {
  $items = array(
    'image_library_img' => array(
      'name' => t('Image library image'),
      'module' => 'features',
      'description' => t('This content type is used to add images to the Anaheim/OC image library'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
