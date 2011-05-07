<?php

/**
 * Implementation of hook_content_default_fields().
 */
function anaheimoc_sybas_offer_content_default_fields() {
  $fields = array();

  // Exported field: field_microsite_sybas_ref
  $fields['sybas_offer-field_microsite_sybas_ref'] = array(
    'field_name' => 'field_microsite_sybas_ref',
    'type_name' => 'sybas_offer',
    'display_settings' => array(
      'weight' => '-2',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sybas_page' => 'sybas_page',
      'ad' => 0,
      'article' => 0,
      'blog_article' => 0,
      'event_leisure' => 0,
      'feed_fast' => 0,
      'feature_article' => 0,
      'gallery' => 0,
      'front_slideshow' => 0,
      'gallery_image' => 0,
      'image_library_img' => 0,
      'matching' => 0,
      'venue_rooms' => 0,
      'microsite' => 0,
      'multichoice' => 0,
      'navigation_page' => 0,
      'page' => 0,
      'partner_listing' => 0,
      'press_release' => 0,
      'profile' => 0,
      'quiz' => 0,
      'quiz_directions' => 0,
      'sybas_offer' => 0,
      'staff_profile' => 0,
      'story' => 0,
      'truefalse' => 0,
      'webform' => 0,
      'whats_new_article' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Show Your Badge and Save Pages',
      'weight' => '-2',
      'description' => 'Choose the Show Your Badge and Save categories to include this offer on.',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_partner_reference
  $fields['sybas_offer-field_partner_reference'] = array(
    'field_name' => 'field_partner_reference',
    'type_name' => 'sybas_offer',
    'display_settings' => array(
      'weight' => '-1',
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
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Partner reference');
  t('Show Your Badge and Save Pages');

  return $fields;
}
