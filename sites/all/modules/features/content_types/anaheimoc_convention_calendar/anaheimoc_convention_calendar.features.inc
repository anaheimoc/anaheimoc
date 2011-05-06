<?php

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
