<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_travel_trade_opportunity_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_travel_trade_opportunity_imagecache_default_presets() {
  $items = array(
    'partner_listing_list_logo' => array(
      'presetname' => 'partner_listing_list_logo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '136',
            'height' => '',
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
function anaheimoc_travel_trade_opportunity_node_info() {
  $items = array(
    'travel_trade_opp' => array(
      'name' => t('Travel Trade Opportunity'),
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
function anaheimoc_travel_trade_opportunity_views_api() {
  return array(
    'api' => '2',
  );
}
