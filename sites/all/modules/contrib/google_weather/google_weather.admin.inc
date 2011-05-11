<?php
// $Id: google_weather.admin.inc,v 1.1 2010/10/13 10:37:11 kubalawebdesign Exp $

/**
 * @file
 * Provides infrequently used functions for google_weather.
 */

/**
 * Returns the 'save' $op info for hook_block().
 */
function google_weather_block_save($delta, $edit) {
  variable_set("google_weather_location_{$delta}", $edit['google_weather_location']);
  variable_set("google_weather_days_{$delta}", $edit['google_weather_days']);
}

/**
 * Menu callback: display the menu block addition form.
 */
function google_weather_block_add_block_form() {
  module_load_include('inc', 'block', 'block.admin');
  return block_admin_configure($form_state, 'google_weather', NULL);
}

/**
 * Returns the 'configure' $op info for hook_block().
 */
function google_weather_block_configure($delta, $edit) {
  $form_state = array('values' => google_weather_get_config($delta));
  return google_weather_configure_form($form_state);
}

/**
 * Returns the configuration for the requested block delta.
 *
 * @param $delta
 *   integer The delta that uniquely identifies the block in the block system. If
 *   not specified, the default configuration will be returned.
 * @return
 *   array An associated array of configuration options.
 */
function google_weather_get_config($delta = NULL) {
  $config = array(
    'delta' => $delta,
    'google_weather_location' => 'London',
    'google_weather_days' => 3,
  );

  if ($delta) {
    $config['google_weather_location']  = variable_get("google_weather_location_{$delta}",  'London');
    $config['google_weather_days'] = variable_get("google_weather_days_{$delta}", 3);
  }
  return $config;
}

/**
 * Return the title of the block.
 *
 * @param $delta
 *   integer index of google weather block.
 * @return
 *   string The title of the block.
 */
function google_weather_get_title($delta = 0) {
  $config = google_weather_get_config($delta);
  return t("Weather for @location", array('@location' => $config['google_weather_location']));
}

/**
 * Returns the 'list' $op info for hook_block().
 */
function google_weather_block_list() {
  foreach (variable_get('google_weather_ids', array()) as $delta) {
    $block[$delta]['info'] = google_weather_get_title($delta);
    $blocks[$delta]['cache'] = BLOCK_NO_CACHE;
  }
  return $block;
}

/**
 * Returns the configuration form for a menu tree.
 *
 * @param $form_state
 *   array An associated array of configuration options should be present in the
 *   'values' key. If none are given, default configuration is assumed.
 * @return
 *   array The form in Form API format.
 */
function google_weather_configure_form(&$form_state = NULL) {
  $config = array();

  if (!empty($form_state['values'])) {
    $config = $form_state['values'];
  }

  $config += google_weather_get_config();

  $form = array();

  $form['google_weather_location'] = array(
    '#type' => 'textfield',
    '#title' => t("Location"),
    '#default_value' => $config['google_weather_location'],
    '#required' => TRUE,
  );

  $form['google_weather_days'] = array(
    '#type' => 'select',
    '#title' => t("Forecast time"),
    '#default_value' => $config['google_weather_days'],
    '#options' => array(
      '2' => 1,
      '3' => 2,
      '4' => 3,
      '5' => 4,
    ),
    '#description' => t("Number of days, including today forecast"),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Save the new google weather block.
 */
function google_weather_block_add_block_form_submit($form, &$form_state) {
  // Determine the delta of new block.
  $block_ids = variable_get('google_weather_ids', array());
  $delta = empty($block_ids) ? 1 : max($block_ids) + 1;

  // Save the new array of block IDs
  $block_ids[] = $delta;
  variable_set('google_weather_ids', $block_ids);

  // Save the block configuration
  google_weather_block_save($delta, $form_state['values']);

  // Run the normal new block submission
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      db_query("INSERT INTO {blocks} (visibility, pages, custom, title, module, theme, status, weight, delta, cache) VALUES(%d, '%s', %d, '%s', '%s', '%s', %d, %d, %d, %d)", $form_state['values']['visibility'], trim($form_state['values']['pages']), $form_state['values']['custom'], $form_state['values']['title'], $form_state['values']['module'], $theme->name, 0, 0, $delta, BLOCK_NO_CACHE);
    }
  }

  foreach (array_filter($form_state['values']['roles']) as $rid) {
    db_query("INSERT INTO {blocks_roles} (rid, module, delta) VALUES (%d, '%s', '%s')", $rid, $form_state['values']['module'], $delta);
  }

  drupal_set_message(t('The block has been created.'));
  cache_clear_all();

  $form_state['redirect'] = 'admin/build/block';
  return;
}

/**
 * Menu callback: confirm deletion of menu blocks.
 */
function google_weather_delete(&$form_state, $delta = 0) {
  $title = google_weather_get_title($delta);
  $form['block_title'] = array('#type' => 'hidden', '#value' => $title);
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);

  return confirm_form($form, t('Are you sure you want to delete the "%name" block?', array('%name' => $title)), 'admin/build/block', NULL, t('Delete'), t('Cancel'));
}

/**
 * Delete google weather block
 */
function google_weather_delete_submit($form, &$form_state) {
  $delta = $form_state['values']['delta'];
  $block_ids = variable_get('google_weather_ids', array());
  unset($block_ids[array_search($delta, $block_ids)]);
  sort($block_ids);
  variable_set('google_weather_ids', $block_ids);
  variable_del("google_weather_location_{$delta}");
  variable_del("google_weather_days_{$delta}");

  db_query("DELETE FROM {blocks} WHERE module = 'google_weather' AND delta = %d", $delta);
  db_query("DELETE FROM {blocks_roles} WHERE module = 'google_weather' AND delta = %d", $delta);
  drupal_set_message(t('The "%name" block has been removed.', array('%name' => $form_state['values']['block_title'])));
  cache_clear_all();

  $form_state['redirect'] = 'admin/build/block';
  return;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function google_weather_block_list_alter(&$form, $form_state) {
  foreach (variable_get('google_weather_ids', array()) as $delta) {
    $form['google_weather_' . $delta]['delete'] = array('#value' => l(t('delete'), 'admin/build/block/delete-google-weather-block/'. $delta));
  }
}
