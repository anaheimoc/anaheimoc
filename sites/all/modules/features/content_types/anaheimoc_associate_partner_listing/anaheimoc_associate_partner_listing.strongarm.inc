<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_associate_partner_listing_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_partner_listing_associate';
  $strongarm->value = 0;

  $export['comment_anonymous_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_partner_listing_associate';
  $strongarm->value = '3';

  $export['comment_controls_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_partner_listing_associate';
  $strongarm->value = '4';

  $export['comment_default_mode_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_partner_listing_associate';
  $strongarm->value = '1';

  $export['comment_default_order_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_partner_listing_associate';
  $strongarm->value = '50';

  $export['comment_default_per_page_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_partner_listing_associate';
  $strongarm->value = '0';

  $export['comment_form_location_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_partner_listing_associate';
  $strongarm->value = '0';

  $export['comment_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_partner_listing_associate';
  $strongarm->value = '1';

  $export['comment_preview_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_partner_listing_associate';
  $strongarm->value = '1';

  $export['comment_subject_field_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_partner_listing_associate';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '2',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'comment_settings' => '9',
    'menu' => '3',
    'path' => '10',
    'attachments' => '8',
    'domain' => '4',
  );

  $export['content_extra_weights_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_partner_listing_associate';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_partner_listing_associate'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_partner_listing_associate';
  $strongarm->value = '0';

  $export['upload_partner_listing_associate'] = $strongarm;
  return $export;
}
