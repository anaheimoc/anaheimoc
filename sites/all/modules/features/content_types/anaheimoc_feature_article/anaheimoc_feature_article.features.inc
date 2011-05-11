<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_feature_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_feature_article_imagecache_default_presets() {
  $items = array(
    'feature_article_image' => array(
      'presetname' => 'feature_article_image',
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
function anaheimoc_feature_article_node_info() {
  $items = array(
    'feature_article' => array(
      'name' => t('Feature Article'),
      'module' => 'features',
      'description' => t('The <em><strong>Feature Article</strong></em> content type is attached directly to its parent content type, <em><strong>Navigation Page</strong></em>.  The Feature article content type also has a child content type, which is the <em><strong>Article</strong></em> content type.'),
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
function anaheimoc_feature_article_views_api() {
  return array(
    'api' => '2',
  );
}
