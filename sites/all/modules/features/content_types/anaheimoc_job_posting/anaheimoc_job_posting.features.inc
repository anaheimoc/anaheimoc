<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function anaheimoc_job_posting_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

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

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_job_posting_views_api() {
  return array(
    'api' => '2',
  );
}
