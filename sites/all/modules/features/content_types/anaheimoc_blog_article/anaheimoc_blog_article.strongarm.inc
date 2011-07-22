<?php

/**
 * Implementation of hook_strongarm().
 */
function anaheimoc_blog_article_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_blog_article';
  $strongarm->value = 0;

  $export['comment_anonymous_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_blog_article';
  $strongarm->value = '0';

  $export['comment_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_blog_article';
  $strongarm->value = '3';

  $export['comment_controls_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_blog_article';
  $strongarm->value = '4';

  $export['comment_default_mode_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_blog_article';
  $strongarm->value = '1';

  $export['comment_default_order_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_blog_article';
  $strongarm->value = '50';

  $export['comment_default_per_page_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_blog_article';
  $strongarm->value = '0';

  $export['comment_form_location_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_blog_article';
  $strongarm->value = '1';

  $export['comment_preview_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_blog_article';
  $strongarm->value = '1';

  $export['comment_subject_field_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_blog_article';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-1',
    'revision_information' => '5',
    'author' => '4',
    'options' => '6',
    'comment_settings' => '7',
    'menu' => '3',
    'taxonomy' => '-2',
    'path' => '8',
    'domain' => '2',
    'detailed_question' => '10',
    'path_redirect' => '11',
  );

  $export['content_extra_weights_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_blog_article_field_anaheimoc_page_hero_image';
  $strongarm->value = 0;

  $export['ffp_blog_article_field_anaheimoc_page_hero_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_blog_article_field_article_image';
  $strongarm->value = 0;

  $export['ffp_blog_article_field_article_image'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ffp_blog_article_field_article_image_additional';
  $strongarm->value = 0;

  $export['ffp_blog_article_field_article_image_additional'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_blog_article';
  $strongarm->value = array();

  $export['node_options_blog_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_blog_article';
  $strongarm->value = '0';

  $export['upload_blog_article'] = $strongarm;
  return $export;
}
