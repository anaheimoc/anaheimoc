<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_basic_profile_node_info() {
  $items = array(
    'basic_profile' => array(
      'name' => t('Basic profile'),
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
