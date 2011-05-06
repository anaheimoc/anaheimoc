<?php

/**
 * Implementation of hook_content_default_fields().
 */
function whats_new_content_default_fields() {
  $fields = array();

  // Exported field: field_whats_new_press_contact
  $fields['whats_new-field_whats_new_press_contact'] = array(
    'field_name' => 'field_whats_new_press_contact',
    'type_name' => 'whats_new',
    'display_settings' => array(
      'weight' => '5',
      'parent' => 'group_whats_new_press_info',
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
      'label' => 'Press contact',
      'weight' => '5',
      'description' => 'Use this field to enter the appropriate press contact information (e.g. name, email phone #).  The press contact info will only appear in on the Press What\'s New page.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Press contact');

  return $fields;
}
