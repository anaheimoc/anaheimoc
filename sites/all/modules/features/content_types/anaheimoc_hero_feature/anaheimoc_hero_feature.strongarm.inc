<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_hero_feature_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_front_slideshow';
  $strongarm->value = 0;

  $export['comment_anonymous_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_front_slideshow';
  $strongarm->value = '3';

  $export['comment_controls_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_front_slideshow';
  $strongarm->value = '4';

  $export['comment_default_mode_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_front_slideshow';
  $strongarm->value = '1';

  $export['comment_default_order_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_front_slideshow';
  $strongarm->value = '50';

  $export['comment_default_per_page_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_front_slideshow';
  $strongarm->value = '0';

  $export['comment_form_location_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_front_slideshow';
  $strongarm->value = '0';

  $export['comment_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_front_slideshow';
  $strongarm->value = '1';

  $export['comment_preview_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_front_slideshow';
  $strongarm->value = '1';

  $export['comment_subject_field_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_front_slideshow';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-3',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '4',
    'menu' => '6',
    'path' => '5',
    'domain' => '-1',
    'nodewords' => '0',
  );

  $export['content_extra_weights_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_front_slideshow';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_front_slideshow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_front_slideshow';
  $strongarm->value = '0';

  $export['upload_front_slideshow'] = $strongarm;
  return $export;
}
