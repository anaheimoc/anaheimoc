<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_event_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_event_leisure';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '10',
    'author' => '11',
    'options' => '12',
    'comment_settings' => '13',
    'menu' => '0',
    'path' => '14',
    'domain' => '9',
  );

  $export['content_extra_weights_event_leisure'] = $strongarm;
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
