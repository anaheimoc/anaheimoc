<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_coupon_node_info() {
  $items = array(
    'coupon' => array(
      'name' => t('Coupon'),
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
