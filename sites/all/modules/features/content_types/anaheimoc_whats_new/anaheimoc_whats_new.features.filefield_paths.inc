<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_whats_new_default_filefield_paths() {
  $settings = array();

  // Exported whats_new_article-field_article_image
  $settings['whats_new_article-field_article_image'] = array(
    'type' => 'whats_new_article',
    'field' => 'field_article_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/image',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );
  // Exported whats_new_article-field_article_image_additional
  $settings['whats_new_article-field_article_image_additional'] = array(
    'type' => 'whats_new_article',
    'field' => 'field_article_image_additional',
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
