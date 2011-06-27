<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_travel_trade_opportunity_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_travel_trade_opp';
  $strongarm->value = 0;

  $export['comment_anonymous_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_travel_trade_opp';
  $strongarm->value = '3';

  $export['comment_controls_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_travel_trade_opp';
  $strongarm->value = '4';

  $export['comment_default_mode_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_travel_trade_opp';
  $strongarm->value = '1';

  $export['comment_default_order_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_travel_trade_opp';
  $strongarm->value = '50';

  $export['comment_default_per_page_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_travel_trade_opp';
  $strongarm->value = '0';

  $export['comment_form_location_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_travel_trade_opp';
  $strongarm->value = '1';

  $export['comment_preview_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_travel_trade_opp';
  $strongarm->value = '1';

  $export['comment_subject_field_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_travel_trade_opp';
  $strongarm->value = '0';

  $export['comment_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_travel_trade_opp';
  $strongarm->value = array(
    'webform' => '11',
    'title' => '-5',
    'body_field' => '4',
    'revision_information' => '7',
    'author' => '8',
    'options' => '9',
    'comment_settings' => '12',
    'menu' => '-3',
    'path' => '13',
    'attachments' => '10',
    'domain' => '6',
  );

  $export['content_extra_weights_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_travel_trade_opp_field_tt_opp_logo';
  $strongarm->value = 0;

  $export['ffp_travel_trade_opp_field_tt_opp_logo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_travel_trade_opp';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_travel_trade_opp'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_travel_trade_opp';
  $strongarm->value = '1';

  $export['upload_travel_trade_opp'] = $strongarm;
  return $export;
}
