<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_testimonial_node_info() {
  $items = array(
    'testimonial' => array(
      'name' => t('Testimonial'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Quote'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
