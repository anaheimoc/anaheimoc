<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_local_media_outlet_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_local_media_outlet_node_info() {
  $items = array(
    'media_contact' => array(
      'name' => t('Local media contact'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'media_outlet' => array(
      'name' => t('Local media outlet'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Outlet'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_local_media_outlet_views_api() {
  return array(
    'api' => '2',
  );
}
