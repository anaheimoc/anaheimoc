<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_convention_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_convention_calendar_node_info() {
  $items = array(
    'convention_calendar' => array(
      'name' => t('Convention calendar'),
      'module' => 'features',
      'description' => t('Meetings and convention calendar for the Anaheim/OC area'),
      'has_title' => '1',
      'title_label' => t('Meeting name'),
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
function anaheimoc_convention_calendar_views_api() {
  return array(
    'api' => '2',
  );
}
