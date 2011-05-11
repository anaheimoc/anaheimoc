<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_media_clip_node_info() {
  $items = array(
    'media_clipping' => array(
      'name' => t('Media clipping'),
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
