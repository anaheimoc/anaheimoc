<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function anaheimoc_page_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_editor_notes
  $groups['anaheimoc_page-group_editor_notes'] = array(
    'group_type' => 'standard',
    'type_name' => 'anaheimoc_page',
    'group_name' => 'group_editor_notes',
    'label' => 'Editor notes',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
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
    'weight' => '19',
    'fields' => array(
      '0' => 'field_page_editor_review',
      '1' => 'field_page_editor_notes',
    ),
  );

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
        'weight' => '-3',
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
  t('Editor notes');
  t('Hero feature options');

  return $groups;
}
