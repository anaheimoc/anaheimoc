<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_microsite_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_microsite';
  $strongarm->value = 0;

  $export['comment_anonymous_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_microsite';
  $strongarm->value = '3';

  $export['comment_controls_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_microsite';
  $strongarm->value = '4';

  $export['comment_default_mode_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_microsite';
  $strongarm->value = '1';

  $export['comment_default_order_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_microsite';
  $strongarm->value = '50';

  $export['comment_default_per_page_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_microsite';
  $strongarm->value = '0';

  $export['comment_form_location_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_microsite';
  $strongarm->value = '0';

  $export['comment_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_microsite';
  $strongarm->value = '1';

  $export['comment_preview_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_microsite';
  $strongarm->value = '1';

  $export['comment_subject_field_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_microsite';
  $strongarm->value = array(
    'title' => '4',
    'body_field' => '9',
    'revision_information' => '23',
    'author' => '22',
    'options' => '24',
    'comment_settings' => '26',
    'menu' => '8',
    'path' => '27',
    'attachments' => '25',
    'domain' => '21',
    'microsite_blocks_node_content_1' => '18',
    'microsite_blocks_node_content_2' => '19',
  );

  $export['content_extra_weights_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_microsite_field_microsite_conf_logo';
  $strongarm->value = 0;

  $export['ffp_microsite_field_microsite_conf_logo'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_microsite_field_microsite_main_img';
  $strongarm->value = 0;

  $export['ffp_microsite_field_microsite_main_img'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_microsite';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_microsite'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_microsite';
  $strongarm->value = '1';

  $export['upload_microsite'] = $strongarm;
  return $export;
}
