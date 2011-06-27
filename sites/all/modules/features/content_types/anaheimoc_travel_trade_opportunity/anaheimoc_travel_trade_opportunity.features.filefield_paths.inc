<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_travel_trade_opportunity_default_filefield_paths() {
  $settings = array();

  // Exported travel_trade_opp-field_tt_opp_logo
  $settings['travel_trade_opp-field_tt_opp_logo'] = array(
    'type' => 'travel_trade_opp',
    'field' => 'field_tt_opp_logo',
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
