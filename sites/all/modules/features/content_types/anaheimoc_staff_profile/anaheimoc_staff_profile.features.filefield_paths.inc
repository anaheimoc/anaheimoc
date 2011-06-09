<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_staff_profile_default_filefield_paths() {
  $settings = array();

  // Exported staff_profile-field_profile_image
  $settings['staff_profile-field_profile_image'] = array(
    'type' => 'staff_profile',
    'field' => 'field_profile_image',
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
