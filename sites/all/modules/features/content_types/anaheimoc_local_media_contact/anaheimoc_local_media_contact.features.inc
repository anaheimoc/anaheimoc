<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_local_media_contact_node_info() {
  $items = array(
    'media_contact' => array(
      'name' => t('Local media contact'),
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
