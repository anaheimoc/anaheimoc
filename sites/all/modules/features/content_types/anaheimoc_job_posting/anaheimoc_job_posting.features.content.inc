<?php

/**
 * Implementation of hook_content_default_fields().
 */
function anaheimoc_job_posting_content_default_fields() {
  $fields = array();

  // Exported field: field_job_contact
  $fields['job_posting-field_job_contact'] = array(
    'field_name' => 'field_job_contact',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Contact name',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_job_contact_email
  $fields['job_posting-field_job_contact_email'] = array(
    'field_name' => 'field_job_contact_email',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'email',
    'required' => '0',
    'multiple' => '0',
    'module' => 'email',
    'active' => '1',
    'widget' => array(
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Contact email',
      'weight' => 0,
      'description' => '',
      'type' => 'email_textfield',
      'module' => 'email',
    ),
  );

  // Exported field: field_job_contact_link
  $fields['job_posting-field_job_contact_link'] = array(
    'field_name' => 'field_job_contact_link',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => '_blank',
      'rel' => 'nofollow',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'value',
    'title_value' => 'Apply online',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Apply online link',
      'weight' => '1',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_job_contact_phone
  $fields['job_posting-field_job_contact_phone'] = array(
    'field_name' => 'field_job_contact_phone',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'ca_phone',
    'required' => '0',
    'multiple' => '0',
    'module' => 'phone',
    'active' => '1',
    'phone_country_code' => 0,
    'ca_phone_separator' => '-',
    'ca_phone_parentheses' => 1,
    'widget' => array(
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Contact phone',
      'weight' => '-1',
      'description' => '',
      'type' => 'phone_textfield',
      'module' => 'phone',
    ),
  );

  // Exported field: field_job_description
  $fields['job_posting-field_job_description'] = array(
    'field_name' => 'field_job_description',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Job description',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_job_salary
  $fields['job_posting-field_job_salary'] = array(
    'field_name' => 'field_job_salary',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Salary',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_partner_reference
  $fields['job_posting-field_partner_reference'] = array(
    'field_name' => 'field_partner_reference',
    'type_name' => 'job_posting',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'partner_listing' => 'partner_listing',
      'ad' => 0,
      'article' => 0,
      'partner_listing_associate' => 0,
      'basic_profile' => 0,
      'blog_article' => 0,
      'blogger_profile' => 0,
      'convention_calendar' => 0,
      'coupon' => 0,
      'event_leisure' => 0,
      'feed_fast' => 0,
      'feature_article' => 0,
      'gallery' => 0,
      'front_slideshow' => 0,
      'gallery_image' => 0,
      'image_library_img' => 0,
      'job_posting' => 0,
      'media_contact' => 0,
      'media_outlet' => 0,
      'matching' => 0,
      'media_clipping' => 0,
      'venue_rooms' => 0,
      'microsite' => 0,
      'multichoice' => 0,
      'navigation_page' => 0,
      'oc_specialist_updates' => 0,
      'page' => 0,
      'partner_event' => 0,
      'partner_discounts' => 0,
      'partner_spotlight' => 0,
      'podcast' => 0,
      'press_release' => 0,
      'profile' => 0,
      'pr_contact' => 0,
      'quiz' => 0,
      'quiz_directions' => 0,
      'sybas_offer' => 0,
      'sybas_page' => 0,
      'staff_profile' => 0,
      'story' => 0,
      'testimonial' => 0,
      'travel_trade_pro_discounts' => 0,
      'travel_trade_opp' => 0,
      'truefalse' => 0,
      'webform' => 0,
      'whats_new_article' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_partner_reference][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Partner reference',
      'weight' => '2',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Apply online link');
  t('Contact email');
  t('Contact name');
  t('Contact phone');
  t('Job description');
  t('Partner reference');
  t('Salary');

  return $fields;
}
