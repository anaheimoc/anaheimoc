<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function whats_new_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function whats_new_node_info() {
  $items = array(
    'whats_new' => array(
      'name' => t('What\'s New'),
      'module' => 'features',
      'description' => t('The <strong><em>What\'s New</em></strong> content type is used for adding new information about the destination to the website.'),
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

/**
 * Implementation of hook_views_api().
 */
function whats_new_views_api() {
  return array(
    'api' => '2',
  );
}
