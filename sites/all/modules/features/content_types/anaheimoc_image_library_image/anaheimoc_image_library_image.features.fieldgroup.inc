<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function anaheimoc_image_library_image_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_image_library_sizes
  $groups['image_library_img-group_image_library_sizes'] = array(
    'group_type' => 'standard',
    'type_name' => 'image_library_img',
    'group_name' => 'group_image_library_sizes',
    'label' => 'Image sizes',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        'label' => 'hidden',
        'teaser' => array(
          'format' => 'no_style',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'no_style',
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
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_image_lib_img',
      '1' => 'field_image_lib_large',
      '2' => 'field_image_lib_medium',
      '3' => 'field_image_lib_small',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image sizes');

  return $groups;
}
