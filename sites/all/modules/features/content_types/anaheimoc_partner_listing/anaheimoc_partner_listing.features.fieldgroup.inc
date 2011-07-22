<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function anaheimoc_partner_listing_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_mem_main_contact
  $groups['partner_listing-group_mem_main_contact'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_mem_main_contact',
    'label' => 'Main contact info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '2',
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
    'weight' => '2',
    'fields' => array(
      '0' => 'field_mem_phone_main',
      '1' => 'field_mem_phone_fax',
      '2' => 'field_mem_phone_800',
      '3' => 'field_mem_phone_sales',
      '4' => 'field_mem_phone_reservations',
      '5' => 'field_mem_internet_url',
      '6' => 'field_mem_internet_publicemail',
      '7' => 'field_mem_internet_facebookurl',
      '8' => 'field_mem_internet_twitteracct',
      '9' => 'field_mem_internet_res_label',
      '10' => 'field_mem_internet_reservationur',
    ),
  );

  // Exported group: group_partner_descriptions
  $groups['partner_listing-group_partner_descriptions'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_descriptions',
    'label' => 'Descriptions',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '3',
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
    'weight' => '3',
    'fields' => array(
      '0' => 'field_mem_description_keywords',
      '1' => 'field_mem_description_visitor',
      '2' => 'field_mem_description_visfeature',
      '3' => 'field_mem_description_meetings',
      '4' => 'field_mem_description_mtgfeature',
    ),
  );

  // Exported group: group_partner_dining_info
  $groups['partner_listing-group_partner_dining_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_dining_info',
    'label' => 'Dining Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '8',
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
    'weight' => '8',
    'fields' => array(
      '0' => 'field_tax_diningrates',
      '1' => 'field_tax_diningmealsserved',
      '2' => 'field_tax_diningamenities',
      '3' => 'field_mem_dining_dress',
    ),
  );

  // Exported group: group_partner_general_info
  $groups['partner_listing-group_partner_general_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_general_info',
    'label' => 'General Info',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-1',
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
    'weight' => '-1',
    'fields' => array(
      '0' => 'field_member_pkid',
      '1' => 'field_partner_url',
      '2' => 'field_memcompany',
      '3' => 'field_memcompanysort',
      '4' => 'field_mem_secondary_member',
      '5' => 'field_mem_feeds_import_date',
      '6' => 'field_tax_webpackage',
      '7' => 'field_tax_grid',
      '8' => 'field_tax_financial',
      '9' => 'field_mem_feature_puctcppermitno',
      '10' => 'field_mem_feature_parkingavail',
      '11' => 'field_mem_feature_shuttleservice',
      '12' => 'field_mem_feature_prices',
    ),
  );

  // Exported group: group_partner_green_info
  $groups['partner_listing-group_partner_green_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_green_info',
    'label' => 'Green Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '6',
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
    'weight' => '6',
    'fields' => array(
      '0' => 'field_mem_green_cflbulbs',
      '1' => 'field_mem_green_energystarprod',
      '2' => 'field_mem_green_eef_other',
      '3' => 'field_mem_green_lowflowtoilets',
      '4' => 'field_mem_green_lowflowfaucets',
      '5' => 'field_mem_green_linenreusepgrm',
      '6' => 'field_mem_green_bottledorpitcher',
      '7' => 'field_mem_green_laundrysysconsrv',
      '8' => 'field_mem_green_wcp_other',
      '9' => 'field_mem_green_wmprecyclingpgrm',
      '10' => 'field_mem_green_wmpmaterials',
      '11' => 'field_mem_green_wmp_other',
      '12' => 'field_mem_green_envcleanpdcts',
      '13' => 'field_mem_green_orgsustfandb',
      '14' => 'field_mem_green_orgsustfandbdet',
      '15' => 'field_mem_green_donateusablefood',
      '16' => 'field_mem_green_infoother',
    ),
  );

  // Exported group: group_partner_location
  $groups['partner_listing-group_partner_location'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_location',
    'label' => 'Location',
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
      '0' => 'field_mem_address',
      '1' => 'field_tax_region',
      '2' => 'field_mem_description_ptsofinter',
      '3' => 'field_distance_fromaccmiles',
      '4' => 'field_distance_fromacckilometers',
      '5' => 'field_distance_fromaccminutes',
      '6' => 'field_tax_distanceaccmiles',
      '7' => 'field_tax_distanceacckm',
      '8' => 'field_distance_fromsnamiles',
      '9' => 'field_distance_fromsnakilometers',
      '10' => 'field_distance_fromsnaminutes',
      '11' => 'field_tax_distancesnamiles',
      '12' => 'field_tax_distancesnakm',
    ),
  );

  // Exported group: group_partner_media
  $groups['partner_listing-group_partner_media'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_media',
    'label' => 'Media assets',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '0',
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
    'weight' => '0',
    'fields' => array(
      '0' => 'field_mem_logo',
      '1' => 'field_mem_images',
      '2' => 'field_mem_video_label',
      '3' => 'field_mem_video_link',
    ),
  );

  // Exported group: group_partner_meeting_info
  $groups['partner_listing-group_partner_meeting_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_meeting_info',
    'label' => 'Meeting Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '5',
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
    'weight' => '5',
    'fields' => array(
      '0' => 'field_tax_meeting_categories',
      '1' => 'field_tax_meeting_amenities',
      '2' => 'field_mem_meet_totroomincsuites',
      '3' => 'field_tax_lodgingtotalrooms',
      '4' => 'field_mem_meet_totalsuites',
      '5' => 'field_tax_lodgingtotalsuites',
      '6' => 'field_mem_meet_committablerooms',
      '7' => 'field_tax_totalcommittablerooms',
      '8' => 'field_mem_meet_disabledequiproom',
      '9' => 'field_tax_disabledequiprooms',
      '10' => 'field_mem_meet_estrackrate',
      '11' => 'field_tax_estrackrate',
      '12' => 'field_mem_meet_largesttheaterset',
      '13' => 'field_tax_maxtheatercap',
      '14' => 'field_mem_meet_largestbanqset',
      '15' => 'field_tax_maxbanquetcap',
      '16' => 'field_mem_meet_largestrecepset',
      '17' => 'field_tax_maxreceptioncap',
      '18' => 'field_mem_meet_largestmeetsqft',
      '19' => 'field_tax_maxmeetingroomsqft',
      '20' => 'field_mem_meet_meetingrooms',
      '21' => 'field_tax_totalmeetingrooms',
      '22' => 'field_mem_meet_disabledaccessrms',
      '23' => 'field_tax_disabledaccessmeetroom',
      '24' => 'field_mem_meet_numberrestaurants',
      '25' => 'field_tax_noofrestaurants',
      '26' => 'field_mem_meet_lrgrestaurantcap',
      '27' => 'field_tax_maxrestaurantcap',
    ),
  );

  // Exported group: group_partner_venue_info
  $groups['partner_listing-group_partner_venue_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_venue_info',
    'label' => 'Event Venue Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '7',
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
    'weight' => '7',
    'fields' => array(
      '0' => 'field_venue_buyoutcapacity',
      '1' => 'field_tax_venue_buyoutcapacity',
      '2' => 'field_venue_minprivateroomcap',
      '3' => 'field_tax_venue_minprivatecap',
      '4' => 'field_venue_maxprivateroomcap',
      '5' => 'field_tax_venue_maxprivatecap',
      '6' => 'field_tax_venue_parking',
      '7' => 'field_tax_venue_catering',
      '8' => 'field_tax_venue_alcohol',
      '9' => 'field_tax_venue_locationtype',
      '10' => 'field_tax_venue_accommodations',
      '11' => 'field_tax_venue_maxtheatercap',
      '12' => 'field_tax_venue_maxmeetingsqft',
      '13' => 'field_tax_venue_maxreceptioncap',
      '14' => 'field_tax_venue_maxbanquetcap',
    ),
  );

  // Exported group: group_partner_visitor_info
  $groups['partner_listing-group_partner_visitor_info'] = array(
    'group_type' => 'standard',
    'type_name' => 'partner_listing',
    'group_name' => 'group_partner_visitor_info',
    'label' => 'Visitor Information',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '4',
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
    'weight' => '4',
    'fields' => array(
      '0' => 'field_tax_visitor_categories',
      '1' => 'field_tax_visitoramenities',
      '2' => 'field_mem_lodging_roomcount',
      '3' => 'field_tax_lodgingroomcount_vis',
      '4' => 'field_tax_lodgingrates_visitors',
      '5' => 'field_tax_specialservices',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Descriptions');
  t('Dining Information');
  t('Event Venue Information');
  t('General Info');
  t('Green Information');
  t('Location');
  t('Main contact info');
  t('Media assets');
  t('Meeting Information');
  t('Visitor Information');

  return $groups;
}
