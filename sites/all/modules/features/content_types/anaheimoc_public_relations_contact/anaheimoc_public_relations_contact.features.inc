<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_public_relations_contact_node_info() {
  $items = array(
    'pr_contact' => array(
      'name' => t('Public relations contact'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
