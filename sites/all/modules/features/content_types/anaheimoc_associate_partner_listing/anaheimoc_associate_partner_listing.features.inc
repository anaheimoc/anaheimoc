<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_associate_partner_listing_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_associate_partner_listing_node_info() {
  $items = array(
    'partner_listing_associate' => array(
      'name' => t('Associate partner listing'),
      'module' => 'features',
      'description' => '',
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
function anaheimoc_associate_partner_listing_views_api() {
  return array(
    'api' => '2',
  );
}
