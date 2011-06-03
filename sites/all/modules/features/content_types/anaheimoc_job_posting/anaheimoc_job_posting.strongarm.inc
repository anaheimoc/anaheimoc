<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_job_posting_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_job_posting';
  $strongarm->value = 0;

  $export['comment_anonymous_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_job_posting';
  $strongarm->value = '3';

  $export['comment_controls_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_job_posting';
  $strongarm->value = '4';

  $export['comment_default_mode_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_job_posting';
  $strongarm->value = '1';

  $export['comment_default_order_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_job_posting';
  $strongarm->value = '50';

  $export['comment_default_per_page_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_job_posting';
  $strongarm->value = '0';

  $export['comment_form_location_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_job_posting';
  $strongarm->value = '0';

  $export['comment_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_job_posting';
  $strongarm->value = '1';

  $export['comment_preview_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_job_posting';
  $strongarm->value = '1';

  $export['comment_subject_field_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_job_posting';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'comment_settings' => '9',
    'menu' => '3',
    'path' => '10',
    'attachments' => '8',
    'domain' => '4',
  );

  $export['content_extra_weights_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_job_posting';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_job_posting';
  $strongarm->value = '1';

  $export['upload_job_posting'] = $strongarm;
  return $export;
}
