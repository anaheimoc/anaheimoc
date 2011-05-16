<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function anaheimoc_page_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_hero_feature_options
  $groups['anaheimoc_page-group_hero_feature_options'] = array(
    'group_type' => 'standard',
    'type_name' => 'anaheimoc_page',
    'group_name' => 'group_hero_feature_options',
    'label' => 'Hero feature options',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
        'label' => 'above',
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
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_anaheimoc_page_hero_tax',
      '1' => 'field_anaheimoc_page_hero_image',
      '2' => 'field_anaheimoc_page_hero_weight',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero feature options');

  return $groups;
}
