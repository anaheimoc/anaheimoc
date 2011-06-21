<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_whats_new_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_whats_new_article';
  $strongarm->value = 0;

  $export['comment_anonymous_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_whats_new_article';
  $strongarm->value = '3';

  $export['comment_controls_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_whats_new_article';
  $strongarm->value = '4';

  $export['comment_default_mode_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_whats_new_article';
  $strongarm->value = '1';

  $export['comment_default_order_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_whats_new_article';
  $strongarm->value = '50';

  $export['comment_default_per_page_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_whats_new_article';
  $strongarm->value = '0';

  $export['comment_form_location_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_whats_new_article';
  $strongarm->value = '1';

  $export['comment_preview_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_whats_new_article';
  $strongarm->value = '1';

  $export['comment_subject_field_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_whats_new_article';
  $strongarm->value = '0';

  $export['comment_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_whats_new_article';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '4',
    'author' => '3',
    'options' => '5',
    'comment_settings' => '6',
    'menu' => '-1',
    'taxonomy' => '-2',
    'path' => '7',
    'attachments' => '10',
    'domain' => '8',
  );

  $export['content_extra_weights_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_whats_new_article_field_article_image';
  $strongarm->value = 0;

  $export['ffp_whats_new_article_field_article_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_whats_new_article_field_article_image_additional';
  $strongarm->value = 0;

  $export['ffp_whats_new_article_field_article_image_additional'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_whats_new_article';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_whats_new_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_whats_new_article';
  $strongarm->value = '1';

  $export['upload_whats_new_article'] = $strongarm;
  return $export;
}
