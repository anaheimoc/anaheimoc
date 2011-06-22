<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_partner_listing_default_filefield_paths() {
  $settings = array();

  // Exported partner_listing-field_mem_images
  $settings['partner_listing-field_mem_images'] = array(
    'type' => 'partner_listing',
    'field' => 'field_mem_images',
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
  // Exported partner_listing-field_mem_logo
  $settings['partner_listing-field_mem_logo'] = array(
    'type' => 'partner_listing',
    'field' => 'field_mem_logo',
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
