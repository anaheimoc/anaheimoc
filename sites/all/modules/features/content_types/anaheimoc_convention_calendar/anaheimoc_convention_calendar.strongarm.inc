<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_convention_calendar_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_convention_calendar';
  $strongarm->value = 0;

  $export['comment_anonymous_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_convention_calendar';
  $strongarm->value = '3';

  $export['comment_controls_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_convention_calendar';
  $strongarm->value = '0';

  $export['comment_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_convention_calendar';
  $strongarm->value = '4';

  $export['comment_default_mode_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_convention_calendar';
  $strongarm->value = '1';

  $export['comment_default_order_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_convention_calendar';
  $strongarm->value = '50';

  $export['comment_default_per_page_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_convention_calendar';
  $strongarm->value = '0';

  $export['comment_form_location_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_convention_calendar';
  $strongarm->value = '1';

  $export['comment_preview_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_convention_calendar';
  $strongarm->value = '1';

  $export['comment_subject_field_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_convention_calendar';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '23',
    'author' => '22',
    'options' => '24',
    'comment_settings' => '26',
    'menu' => '20',
    'taxonomy' => '-3',
    'path' => '25',
    'domain' => '21',
  );

  $export['content_extra_weights_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_convention_calendar';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_convention_calendar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_convention_calendar';
  $strongarm->value = '0';

  $export['upload_convention_calendar'] = $strongarm;
  return $export;
}
