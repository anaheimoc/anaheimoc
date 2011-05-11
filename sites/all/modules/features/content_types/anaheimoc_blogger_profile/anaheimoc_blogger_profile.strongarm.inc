<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_blogger_profile_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blogger_profile';
  $strongarm->value = 0;

  $export['comment_anonymous_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blogger_profile';
  $strongarm->value = '0';

  $export['comment_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_blogger_profile';
  $strongarm->value = '3';

  $export['comment_controls_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blogger_profile';
  $strongarm->value = '4';

  $export['comment_default_mode_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_blogger_profile';
  $strongarm->value = '1';

  $export['comment_default_order_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blogger_profile';
  $strongarm->value = '50';

  $export['comment_default_per_page_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blogger_profile';
  $strongarm->value = '0';

  $export['comment_form_location_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blogger_profile';
  $strongarm->value = '1';

  $export['comment_preview_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blogger_profile';
  $strongarm->value = '1';

  $export['comment_subject_field_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_blogger_profile';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '4',
    'author' => '3',
    'options' => '5',
    'comment_settings' => '6',
    'menu' => '-2',
    'path' => '7',
    'domain' => '2',
  );

  $export['content_extra_weights_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blogger_profile';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_blogger_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_blogger_profile';
  $strongarm->value = '0';

  $export['upload_blogger_profile'] = $strongarm;
  return $export;
}
