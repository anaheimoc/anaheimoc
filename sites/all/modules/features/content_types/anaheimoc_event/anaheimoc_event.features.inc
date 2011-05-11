<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_event_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_event_imagecache_default_presets() {
  $items = array(
    'event_image' => array(
      'presetname' => 'event_image',
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
function anaheimoc_event_node_info() {
  $items = array(
    'event_leisure' => array(
      'name' => t('Event (calendar of events)'),
      'module' => 'features',
      'description' => t('Events for the leisure/visitor calendar of events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
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
function anaheimoc_event_views_api() {
  return array(
    'api' => '2',
  );
}
