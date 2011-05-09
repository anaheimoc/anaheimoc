<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_feature_article_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feature_article';
  $strongarm->value = 0;

  $export['comment_anonymous_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feature_article';
  $strongarm->value = '3';

  $export['comment_controls_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feature_article';
  $strongarm->value = '4';

  $export['comment_default_mode_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feature_article';
  $strongarm->value = '1';

  $export['comment_default_order_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feature_article';
  $strongarm->value = '50';

  $export['comment_default_per_page_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feature_article';
  $strongarm->value = '0';

  $export['comment_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feature_article';
  $strongarm->value = '0';

  $export['comment_form_location_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feature_article';
  $strongarm->value = '1';

  $export['comment_preview_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feature_article';
  $strongarm->value = '1';

  $export['comment_subject_field_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feature_article';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '0',
    'options' => '3',
    'comment_settings' => '4',
    'menu' => '-4',
    'path' => '5',
    'attachments' => '10',
    'domain' => '2',
    'support_articles_node_content_1' => '7',
    'partner_list_builder_node_content_1' => '6',
  );

  $export['content_extra_weights_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feature_article';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_feature_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feature_article';
  $strongarm->value = '1';

  $export['upload_feature_article'] = $strongarm;
  return $export;
}
