<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_hero_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_hero_feature_node_info() {
  $items = array(
    'front_slideshow' => array(
      'name' => t('Hero Feature Story (Homepage Slideshow)'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Teaser'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_hero_feature_views_api() {
  return array(
    'api' => '2',
  );
}
