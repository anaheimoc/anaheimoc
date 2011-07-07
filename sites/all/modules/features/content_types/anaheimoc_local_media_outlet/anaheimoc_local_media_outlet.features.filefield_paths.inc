<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_local_media_outlet_default_filefield_paths() {
  $settings = array();

  // Exported media_outlet-field_global_logo
  $settings['media_outlet-field_global_logo'] = array(
    'type' => 'media_outlet',
    'field' => 'field_global_logo',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/logo',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );

  return $settings;
}
