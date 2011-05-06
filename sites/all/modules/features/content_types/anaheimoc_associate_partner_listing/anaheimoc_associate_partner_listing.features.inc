<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_associate_partner_listing_node_info() {
  $items = array(
    'partner_listing_associate' => array(
      'name' => t('Associate partner listing'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
