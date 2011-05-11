<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_press_release_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press release'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Headline'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
