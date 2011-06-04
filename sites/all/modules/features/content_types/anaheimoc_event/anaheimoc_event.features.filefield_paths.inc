<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_event_default_filefield_paths() {
  $settings = array();

  // Exported event_leisure-field_article_image
  $settings['event_leisure-field_article_image'] = array(
    'type' => 'event_leisure',
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
  // Exported event_leisure-field_event_leisure_image
  $settings['event_leisure-field_event_leisure_image'] = array(
    'type' => 'event_leisure',
    'field' => 'field_event_leisure_image',
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
