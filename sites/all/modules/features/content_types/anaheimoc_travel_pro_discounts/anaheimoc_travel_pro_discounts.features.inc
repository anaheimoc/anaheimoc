<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_travel_pro_discounts_node_info() {
  $items = array(
    'travel_trade_pro_discounts' => array(
      'name' => t('Travel Pro Discounts'),
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
