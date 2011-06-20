<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_press_release_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press release'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Headline'),
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
function anaheimoc_press_release_views_api() {
  return array(
    'api' => '2',
  );
}
