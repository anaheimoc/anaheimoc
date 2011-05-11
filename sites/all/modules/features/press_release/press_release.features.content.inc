<?php

/**
 * Implementation of hook_content_default_fields().
 */
function press_release_content_default_fields() {
  $fields = array();

  // Exported field: field_pr_attachment_file
  $fields['press_release-field_pr_attachment_file'] = array(
    'field_name' => 'field_pr_attachment_file',
    'type_name' => 'press_release',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '3',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'pdf',
      'file_path' => 'assets/pr/press-release/files',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '2M',
      'max_filesize_per_node' => '6M',
      'label' => 'Press release attachments (files)',
      'weight' => 0,
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_pr_attachment_image
  $fields['press_release-field_pr_attachment_image'] = array(
    'field_name' => 'field_pr_attachment_image',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '3',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '1',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'assets/pr/press-release/images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '10M',
      'max_filesize_per_node' => '50M',
      'max_resolution' => '2000x2000',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Press release attachments (images)',
      'weight' => '1',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_pr_boilerplate
  $fields['press_release-field_pr_boilerplate'] = array(
    'field_name' => 'field_pr_boilerplate',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '3',
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '1500',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '8',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_pr_boilerplate][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Boilerplate copy',
      'weight' => '3',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_pr_contact
  $fields['press_release-field_pr_contact'] = array(
    'field_name' => 'field_pr_contact',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '5',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '3',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'staff_profile' => 'staff_profile',
      'page' => 0,
      'press_release' => 0,
      'profile' => 0,
      'story' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Contact',
      'weight' => '5',
      'description' => 'This is an autocomplete field.  Start typing the name of the staff member you want to reference and select the appropriate choice.',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_pr_member_reference
  $fields['press_release-field_pr_member_reference'] = array(
    'field_name' => 'field_pr_member_reference',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '4',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '10',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'board_of_directors_test' => 0,
      'calendar_event_listing' => 0,
      'event_test' => 0,
      'exec_bio_test' => 0,
      'feed_fast' => 0,
      'local_media' => 0,
      'media_outlet' => 0,
      'member_listing' => 0,
      'member_listing_test' => 0,
      'page' => 0,
      'people_on_the_move_test' => 0,
      'press_release' => 0,
      'profile' => 0,
      'story' => 0,
      'venue_rooms_test' => 0,
      'whats_new_test' => 0,
      'contact_database' => FALSE,
      'event' => FALSE,
      'feed' => FALSE,
      'feed_item' => FALSE,
      'image' => FALSE,
      'features_test' => FALSE,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_pr_member_reference][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Member reference',
      'weight' => '4',
      'description' => 'Enter the member organization(s) that this press release references.',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_pr_release_date
  $fields['press_release-field_pr_release_date'] = array(
    'field_name' => 'field_pr_release_date',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'short',
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
    'type' => 'datetime',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => 'America/Los_Angeles',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'month_day_year',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'l M j, Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '+0:+3',
      'label_position' => 'above',
      'label' => 'Release date',
      'weight' => '-2',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_pr_subheadline
  $fields['press_release-field_pr_subheadline'] = array(
    'field_name' => 'field_pr_subheadline',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'plain',
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
    'max_length' => '150',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_pr_subheadline][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub-headline',
      'weight' => '-4',
      'description' => 'Enter the press release\'s sub-headline if available.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_pr_video_link
  $fields['press_release-field_pr_video_link'] = array(
    'field_name' => 'field_pr_video_link',
    'type_name' => 'press_release',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'video_preview',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'video_preview',
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
    'type' => 'emvideo',
    'required' => '0',
    'multiple' => '0',
    'module' => 'emvideo',
    'active' => '1',
    'widget' => array(
      'video_width' => '425',
      'video_height' => '350',
      'video_autoplay' => 0,
      'preview_width' => '300',
      'preview_height' => '245',
      'preview_autoplay' => 0,
      'thumbnail_width' => '120',
      'thumbnail_height' => '90',
      'thumbnail_default_path' => '',
      'thumbnail_link_title' => 'See video',
      'meta_fields' => array(
        'title' => 0,
        'description' => 0,
      ),
      'providers' => array(
        'bitsontherun' => 'bitsontherun',
        'bliptv' => 'bliptv',
        'viddler' => 'viddler',
        'vimeo' => 'vimeo',
        'youtube' => 'youtube',
      ),
      'default_value' => array(
        '0' => array(
          'embed' => '',
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Video link',
      'weight' => '2',
      'description' => '',
      'type' => 'emvideo_textfields',
      'module' => 'emvideo',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Boilerplate copy');
  t('Contact');
  t('Member reference');
  t('Press release attachments (files)');
  t('Press release attachments (images)');
  t('Release date');
  t('Sub-headline');
  t('Video link');

  return $fields;
}
