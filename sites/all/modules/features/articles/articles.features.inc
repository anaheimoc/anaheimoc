<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function articles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function articles_imagecache_default_presets() {
  $items = array(
    '140x140' => array(
      'presetname' => '140x140',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '140',
            'height' => '140',
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
function articles_node_info() {
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
    'feature_article' => array(
      'name' => t('Feature article'),
      'module' => 'features',
      'description' => t('The <em><strong>Feature Article</strong></em> content type is attached directly to its parent content type, <em><strong>Navigation Page</strong></em>.  The Feature article content type also has a child content type, which is the <em><strong>Article</strong></em> content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'navigation_page' => array(
      'name' => t('Navigation page'),
      'module' => 'features',
      'description' => t('The navigation page content type is for creating pages to be linked off of the main navigation section or for any other content structures where a parent/child relationship is required.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
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
function articles_views_api() {
  return array(
    'api' => '2',
  );
}
