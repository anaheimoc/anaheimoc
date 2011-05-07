<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_meeting_venue_rooms_node_info() {
  $items = array(
    'venue_rooms' => array(
      'name' => t('Meeting Venue Rooms'),
      'module' => 'features',
      'description' => '',
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
