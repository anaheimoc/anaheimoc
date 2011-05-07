<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_job_posting_node_info() {
  $items = array(
    'job_posting' => array(
      'name' => t('Job posting'),
      'module' => 'features',
      'description' => t('Partner related Job postings'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
