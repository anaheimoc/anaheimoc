<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_local_media_outlet_node_info() {
  $items = array(
    'media_outlet' => array(
      'name' => t('Local media outlet'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Outlet'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
