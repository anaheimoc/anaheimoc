<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_event_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_event_leisure';
  $strongarm->value = 0;

  $export['comment_anonymous_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_event_leisure';
  $strongarm->value = '3';

  $export['comment_controls_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_event_leisure';
  $strongarm->value = '4';

  $export['comment_default_mode_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_event_leisure';
  $strongarm->value = '1';

  $export['comment_default_order_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_event_leisure';
  $strongarm->value = '50';

  $export['comment_default_per_page_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_event_leisure';
  $strongarm->value = '0';

  $export['comment_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_event_leisure';
  $strongarm->value = '0';

  $export['comment_form_location_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_event_leisure';
  $strongarm->value = '1';

  $export['comment_preview_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_event_leisure';
  $strongarm->value = '1';

  $export['comment_subject_field_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_event_leisure';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '12',
    'author' => '13',
    'options' => '14',
    'comment_settings' => '15',
    'menu' => '6',
    'taxonomy' => '8',
    'path' => '16',
    'domain' => '10',
    'detailed_question' => '11',
  );

  $export['content_extra_weights_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_event_leisure_field_article_image';
  $strongarm->value = 0;

  $export['ffp_event_leisure_field_article_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_event_leisure_field_event_leisure_image';
  $strongarm->value = 0;

  $export['ffp_event_leisure_field_event_leisure_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_event_leisure';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_event_leisure'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_event_leisure';
  $strongarm->value = '0';

  $export['upload_event_leisure'] = $strongarm;
  return $export;
}
