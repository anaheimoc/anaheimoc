<?php

/**
 * Implementation of hook_content_default_fields().
 */
function articles_content_default_fields() {
  $fields = array();

  // Exported field: field_article_parent
  $fields['article-field_article_parent'] = array(
    'field_name' => 'field_article_parent',
    'type_name' => 'article',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'feature_article' => 'feature_article',
      'article' => 0,
      'blog_post' => 0,
      'coupon' => 0,
      'event_calendar_listing' => 0,
      'faq' => 0,
      'job_posting' => 0,
      'page' => 0,
      'press_release' => 0,
      'profile' => 0,
      'staff_profile' => 0,
      'story' => 0,
      'navigation_page' => 0,
      'travel_trade_opportunity' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Add Support Article',
        'hover_title' => 'Add Support Article',
        'destination' => 'node',
      ),
      'fallback' => 'autocomplete',
      'edit_fallback' => 1,
      'label' => 'Feature Article',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Exported field: field_featured_article_image
  $fields['feature_article-field_featured_article_image'] = array(
    'field_name' => 'field_featured_article_image',
    'type_name' => 'feature_article',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => '140x140_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => '140x140_default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_feaure_article_parent
  $fields['feature_article-field_feaure_article_parent'] = array(
    'field_name' => 'field_feaure_article_parent',
    'type_name' => 'feature_article',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'navigation_page' => 'navigation_page',
      'article' => 0,
      'blog_post' => 0,
      'coupon' => 0,
      'event_calendar_listing' => 0,
      'feature_article' => 0,
      'faq' => 0,
      'job_posting' => 0,
      'page' => 0,
      'press_release' => 0,
      'profile' => 0,
      'staff_profile' => 0,
      'story' => 0,
      'travel_trade_opportunity' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'node_link' => array(
        'teaser' => 0,
        'full' => 1,
        'title' => 'Add new item to this page',
        'hover_title' => 'Add new article',
        'destination' => 'node',
      ),
      'fallback' => 'select',
      'edit_fallback' => 0,
      'label' => 'Navigation Page',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_url',
      'module' => 'nodereference_url',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Feature Article');
  t('Image');
  t('Navigation Page');

  return $fields;
}
