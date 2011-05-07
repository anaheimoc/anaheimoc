<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_sybas_offer_node_info() {
  $items = array(
    'sybas_offer' => array(
      'name' => t('Show Your Badge and Save Offer'),
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
