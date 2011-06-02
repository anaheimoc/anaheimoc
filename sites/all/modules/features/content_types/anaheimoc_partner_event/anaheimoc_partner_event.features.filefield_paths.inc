<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_partner_event_default_filefield_paths() {
  $settings = array();

  // Exported partner_event-field_article_image
  $settings['partner_event-field_article_image'] = array(
    'type' => 'partner_event',
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

  return $settings;
}
