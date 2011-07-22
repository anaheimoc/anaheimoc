<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function anaheimoc_blog_article_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_blog_hero_feature
  $groups['blog_article-group_blog_hero_feature'] = array(
    'group_type' => 'standard',
    'type_name' => 'blog_article',
    'group_name' => 'group_blog_hero_feature',
    'label' => 'Hero Feature',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '1',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
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
    'weight' => '1',
    'fields' => array(
      '0' => 'field_anaheimoc_page_hero_tax',
      '1' => 'field_anaheimoc_page_hero_image',
      '2' => 'field_anaheimoc_page_hero_weight',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hero Feature');

  return $groups;
}
