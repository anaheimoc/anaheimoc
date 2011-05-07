<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_staff_profile_imagecache_default_presets() {
  $items = array(
    '220x220' => array(
      'presetname' => '220x220',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'smartcrop',
          'action' => 'smartcrop_scale_and_crop',
          'data' => array(
            'width' => '216',
            'height' => '216',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_staff_profile_node_info() {
  $items = array(
    'staff_profile' => array(
      'name' => t('Staff profile'),
      'module' => 'features',
      'description' => t('Profile page for AOCVCB Employees'),
      'has_title' => '1',
      'title_label' => t('Full name'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
