<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_specialist_updates_default_filefield_paths() {
  $settings = array();

  // Exported oc_specialist_updates-field_article_image
  $settings['oc_specialist_updates-field_article_image'] = array(
    'type' => 'oc_specialist_updates',
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
  // Exported oc_specialist_updates-field_article_image_additional
  $settings['oc_specialist_updates-field_article_image_additional'] = array(
    'type' => 'oc_specialist_updates',
    'field' => 'field_article_image_additional',
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

  return $settings;
}
