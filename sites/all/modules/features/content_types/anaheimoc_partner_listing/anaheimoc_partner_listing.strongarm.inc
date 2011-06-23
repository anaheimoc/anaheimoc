<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_partner_listing_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_partner_listing';
  $strongarm->value = 0;

  $export['comment_anonymous_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_partner_listing';
  $strongarm->value = '3';

  $export['comment_controls_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_partner_listing';
  $strongarm->value = '4';

  $export['comment_default_mode_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_partner_listing';
  $strongarm->value = '1';

  $export['comment_default_order_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_partner_listing';
  $strongarm->value = '50';

  $export['comment_default_per_page_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_partner_listing';
  $strongarm->value = '0';

  $export['comment_form_location_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_partner_listing';
  $strongarm->value = '0';

  $export['comment_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_partner_listing';
  $strongarm->value = '1';

  $export['comment_preview_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_partner_listing';
  $strongarm->value = '1';

  $export['comment_subject_field_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_partner_listing';
  $strongarm->value = array(
    'title' => '-2',
    'revision_information' => '13',
    'author' => '12',
    'options' => '14',
    'comment_settings' => '16',
    'menu' => '10',
    'taxonomy' => '-3',
    'path' => '15',
    'attachments' => '17',
    'domain' => '11',
    'detailed_question' => '18',
  );

  $export['content_extra_weights_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_partner_listing_field_mem_images';
  $strongarm->value = 0;

  $export['ffp_partner_listing_field_mem_images'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_partner_listing_field_mem_logo';
  $strongarm->value = 0;

  $export['ffp_partner_listing_field_mem_logo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_partner_listing';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_partner_listing'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_partner_listing';
  $strongarm->value = '1';

  $export['upload_partner_listing'] = $strongarm;
  return $export;
}
