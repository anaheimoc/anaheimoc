<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function whats_new_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_whats_new_press_info
  $groups['whats_new-group_whats_new_press_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'whats_new',
    'group_name' => 'group_whats_new_press_info',
    'label' => 'Press information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-2',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'hidden',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-2',
    'fields' => array(
      '0' => 'field_whats_new_press_contact',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Press information');

  return $groups;
}
