<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function press_release_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press release'),
      'module' => 'features',
      'description' => t('A public relations announcement issued to the news media and other targeted publications for the purpose of letting the public know of company developments'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'has_body' => '1',
      'body_label' => t('Press release body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function press_release_views_api() {
  return array(
    'api' => '2',
  );
}
