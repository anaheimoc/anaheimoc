<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_partner_preferred_discounts_node_info() {
  $items = array(
    'partner_discounts' => array(
      'name' => t('Partner preferred discounts'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Offer title'),
      'has_body' => '1',
      'body_label' => t('Offer description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
