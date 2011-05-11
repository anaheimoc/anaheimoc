<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_page_default_filefield_paths() {
  $settings = array();

  // Exported anaheimoc_page-field_article_image
  $settings['anaheimoc_page-field_article_image'] = array(
    'type' => 'anaheimoc_page',
    'field' => 'field_article_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/images',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );

  return $settings;
}
