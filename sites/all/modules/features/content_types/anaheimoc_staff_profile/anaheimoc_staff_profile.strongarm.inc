<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_staff_profile_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_staff_profile';
  $strongarm->value = 0;

  $export['comment_anonymous_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_staff_profile';
  $strongarm->value = '3';

  $export['comment_controls_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_staff_profile';
  $strongarm->value = '4';

  $export['comment_default_mode_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_staff_profile';
  $strongarm->value = '1';

  $export['comment_default_order_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_staff_profile';
  $strongarm->value = '50';

  $export['comment_default_per_page_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_staff_profile';
  $strongarm->value = '0';

  $export['comment_form_location_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_staff_profile';
  $strongarm->value = '1';

  $export['comment_preview_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_staff_profile';
  $strongarm->value = '0';

  $export['comment_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_staff_profile';
  $strongarm->value = '1';

  $export['comment_subject_field_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_staff_profile';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '4',
    'revision_information' => '8',
    'author' => '7',
    'options' => '10',
    'comment_settings' => '12',
    'menu' => '6',
    'taxonomy' => '5',
    'path' => '11',
    'domain' => '9',
    'detailed_question' => '13',
  );

  $export['content_extra_weights_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_staff_profile_field_profile_image';
  $strongarm->value = 0;

  $export['ffp_staff_profile_field_profile_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_staff_profile';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_staff_profile'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_staff_profile';
  $strongarm->value = '0';

  $export['upload_staff_profile'] = $strongarm;
  return $export;
}
