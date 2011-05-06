<?php

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
