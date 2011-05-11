<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_page_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anaheimoc_page';
  $strongarm->value = '0';

  $export['comment_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_anaheimoc_page';
  $strongarm->value = 0;

  $export['comment_anonymous_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_anaheimoc_page';
  $strongarm->value = '3';

  $export['comment_controls_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_anaheimoc_page';
  $strongarm->value = '4';

  $export['comment_default_mode_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_anaheimoc_page';
  $strongarm->value = '1';

  $export['comment_default_order_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_anaheimoc_page';
  $strongarm->value = '50';

  $export['comment_default_per_page_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_anaheimoc_page';
  $strongarm->value = '0';

  $export['comment_form_location_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_anaheimoc_page';
  $strongarm->value = '1';

  $export['comment_preview_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_anaheimoc_page';
  $strongarm->value = '1';

  $export['comment_subject_field_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_anaheimoc_page';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '5',
    'menu' => '-4',
    'path' => '6',
    'attachments' => '4',
    'domain' => '0',
  );

  $export['content_extra_weights_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_anaheimoc_page_field_article_image';
  $strongarm->value = 0;

  $export['ffp_anaheimoc_page_field_article_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_anaheimoc_page';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_anaheimoc_page'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_anaheimoc_page';
  $strongarm->value = '1';

  $export['upload_anaheimoc_page'] = $strongarm;
  return $export;
}
