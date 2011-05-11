<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_article_imagecache_default_presets() {
  $items = array(
    'article_article_image' => array(
      'presetname' => 'article_article_image',
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
    'article_node_content_image' => array(
      'presetname' => 'article_node_content_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '136',
            'height' => '136',
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
function anaheimoc_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'module' => 'features',
      'description' => t('The <em><strong>Article</strong></em> content type is a child of the <em><strong>Feature Article</strong></em> content type.  Articles are directly attached to Feature Article nodes. The Article content type provides supplemental information and enhances the depth of information of a Feature Article.'),
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

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_article_views_api() {
  return array(
    'api' => '2',
  );
}
