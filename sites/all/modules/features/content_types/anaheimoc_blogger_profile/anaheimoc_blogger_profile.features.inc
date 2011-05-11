<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_blogger_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_blogger_profile_imagecache_default_presets() {
  $items = array(
    'blogger_profile_image' => array(
      'presetname' => 'blogger_profile_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '216',
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
function anaheimoc_blogger_profile_node_info() {
  $items = array(
    'blogger_profile' => array(
      'name' => t('Blogger profile'),
      'module' => 'features',
      'description' => t('Bio and picture for Anaheim/OC Bloggers'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
