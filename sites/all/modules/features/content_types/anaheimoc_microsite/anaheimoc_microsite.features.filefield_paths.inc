<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_microsite_default_filefield_paths() {
  $settings = array();

  // Exported microsite-field_microsite_conf_logo
  $settings['microsite-field_microsite_conf_logo'] = array(
    'type' => 'microsite',
    'field' => 'field_microsite_conf_logo',
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
  // Exported microsite-field_microsite_main_img
  $settings['microsite-field_microsite_main_img'] = array(
    'type' => 'microsite',
    'field' => 'field_microsite_main_img',
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
