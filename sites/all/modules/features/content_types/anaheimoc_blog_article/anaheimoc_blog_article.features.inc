<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_blog_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_blog_article_imagecache_default_presets() {
  $items = array(
    'blog_article_image' => array(
      'presetname' => 'blog_article_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '616',
            'height' => '316',
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
function anaheimoc_blog_article_node_info() {
  $items = array(
    'blog_article' => array(
      'name' => t('Blog post'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Blog post title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_blog_article_views_api() {
  return array(
    'api' => '2',
  );
}
