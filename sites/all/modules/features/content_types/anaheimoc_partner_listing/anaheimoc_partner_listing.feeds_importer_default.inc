<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function anaheimoc_partner_listing_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'partner_listing_upload';
  $feeds_importer->config = array(
    'name' => 'Partner listing upload',
    'description' => 'Feeds importer for updating partner listings',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(),
        'rawXML' => array(),
        'context' => '',
        'exp' => array(
          'errors' => FALSE,
          'tidy' => FALSE,
          'debug' => array(),
          'tidy_encoding' => 'UTF8',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'partner_listing',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_member_pkid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_tax_webpackage',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_tax_grid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_tax_visitoramenities',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'status',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_memcompanysort',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_mem_address:street',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_mem_address:additional',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_mem_address:name',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_mem_address:city',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_mem_address:province',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_mem_address:postal_code',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_mem_address:locpick][user_latitude',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_mem_address:locpick][user_longitude',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_mem_phone_main',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_mem_phone_fax',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_mem_phone_800',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_mem_phone_sales',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_mem_internet_url:url',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_mem_internet_publicemail',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_mem_internet_facebookurl:url',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_mem_internet_twitteracct:url',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_mem_internet_res_label',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_mem_internet_reservationur:url',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_mem_video_label',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_mem_video_link',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_mem_description_keywords',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_mem_description_visitor',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_mem_description_meetings',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'xpathparser:31',
            'target' => 'field_mem_description_visfeature',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'xpathparser:32',
            'target' => 'field_mem_description_mtgfeature',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'xpathparser:33',
            'target' => 'field_mem_description_ptsofinter',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'xpathparser:34',
            'target' => 'field_mem_secondary_member',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'xpathparser:35',
            'target' => 'field_distance_fromaccmiles',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'xpathparser:36',
            'target' => 'field_distance_fromacckilometers',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'xpathparser:37',
            'target' => 'field_distance_fromaccminutes',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'xpathparser:38',
            'target' => 'field_distance_fromsnamiles',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'xpathparser:39',
            'target' => 'field_distance_fromsnakilometers',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'xpathparser:40',
            'target' => 'field_distance_fromsnaminutes',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'xpathparser:41',
            'target' => 'field_mem_dining_dress',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'xpathparser:42',
            'target' => 'field_mem_lodging_roomcount',
            'unique' => FALSE,
          ),
          43 => array(
            'source' => 'xpathparser:43',
            'target' => 'field_mem_feature_parkingavail',
            'unique' => FALSE,
          ),
          44 => array(
            'source' => 'xpathparser:44',
            'target' => 'field_mem_feature_shuttleservice',
            'unique' => FALSE,
          ),
          45 => array(
            'source' => 'xpathparser:45',
            'target' => 'field_mem_feature_prices',
            'unique' => FALSE,
          ),
          46 => array(
            'source' => 'xpathparser:46',
            'target' => 'field_mem_feature_puctcppermitno',
            'unique' => FALSE,
          ),
          47 => array(
            'source' => 'xpathparser:47',
            'target' => 'field_mem_meet_totroomincsuites',
            'unique' => FALSE,
          ),
          48 => array(
            'source' => 'xpathparser:48',
            'target' => 'field_mem_meet_totalsuites',
            'unique' => FALSE,
          ),
          49 => array(
            'source' => 'xpathparser:49',
            'target' => 'field_mem_meet_committablerooms',
            'unique' => FALSE,
          ),
          50 => array(
            'source' => 'xpathparser:50',
            'target' => 'field_mem_meet_disabledequiproom',
            'unique' => FALSE,
          ),
          51 => array(
            'source' => 'xpathparser:51',
            'target' => 'field_mem_meet_estrackrate',
            'unique' => FALSE,
          ),
          52 => array(
            'source' => 'xpathparser:52',
            'target' => 'field_mem_meet_largesttheaterset',
            'unique' => FALSE,
          ),
          53 => array(
            'source' => 'xpathparser:53',
            'target' => 'field_mem_meet_largestbanqset',
            'unique' => FALSE,
          ),
          54 => array(
            'source' => 'xpathparser:54',
            'target' => 'field_mem_meet_largestrecepset',
            'unique' => FALSE,
          ),
          55 => array(
            'source' => 'xpathparser:55',
            'target' => 'field_mem_meet_largestmeetsqft',
            'unique' => FALSE,
          ),
          56 => array(
            'source' => 'xpathparser:56',
            'target' => 'field_mem_meet_meetingrooms',
            'unique' => FALSE,
          ),
          57 => array(
            'source' => 'xpathparser:57',
            'target' => 'field_mem_meet_disabledaccessrms',
            'unique' => FALSE,
          ),
          58 => array(
            'source' => 'xpathparser:58',
            'target' => 'field_mem_meet_numberrestaurants',
            'unique' => FALSE,
          ),
          59 => array(
            'source' => 'xpathparser:59',
            'target' => 'field_mem_meet_lrgrestaurantcap',
            'unique' => FALSE,
          ),
          60 => array(
            'source' => 'xpathparser:60',
            'target' => 'field_venue_buyoutcapacity',
            'unique' => FALSE,
          ),
          61 => array(
            'source' => 'xpathparser:61',
            'target' => 'field_venue_minprivateroomcap',
            'unique' => FALSE,
          ),
          62 => array(
            'source' => 'xpathparser:62',
            'target' => 'field_venue_maxprivateroomcap',
            'unique' => FALSE,
          ),
          63 => array(
            'source' => 'xpathparser:63',
            'target' => 'field_mem_green_cflbulbs',
            'unique' => FALSE,
          ),
          64 => array(
            'source' => 'xpathparser:64',
            'target' => 'field_mem_green_energystarprod',
            'unique' => FALSE,
          ),
          65 => array(
            'source' => 'xpathparser:65',
            'target' => 'field_mem_green_eef_other',
            'unique' => FALSE,
          ),
          66 => array(
            'source' => 'xpathparser:66',
            'target' => 'field_mem_green_lowflowtoilets',
            'unique' => FALSE,
          ),
          67 => array(
            'source' => 'xpathparser:67',
            'target' => 'field_mem_green_lowflowfaucets',
            'unique' => FALSE,
          ),
          68 => array(
            'source' => 'xpathparser:68',
            'target' => 'field_mem_green_linenreusepgrm',
            'unique' => FALSE,
          ),
          69 => array(
            'source' => 'xpathparser:69',
            'target' => 'field_mem_green_bottledorpitcher',
            'unique' => FALSE,
          ),
          70 => array(
            'source' => 'xpathparser:70',
            'target' => 'field_mem_green_laundrysysconsrv',
            'unique' => FALSE,
          ),
          71 => array(
            'source' => 'xpathparser:71',
            'target' => 'field_mem_green_wcp_other',
            'unique' => FALSE,
          ),
          72 => array(
            'source' => 'xpathparser:72',
            'target' => 'field_mem_green_wmprecyclingpgrm',
            'unique' => FALSE,
          ),
          73 => array(
            'source' => 'xpathparser:73',
            'target' => 'field_mem_green_wmpmaterials',
            'unique' => FALSE,
          ),
          74 => array(
            'source' => 'xpathparser:74',
            'target' => 'field_mem_green_wmp_other',
            'unique' => FALSE,
          ),
          75 => array(
            'source' => 'xpathparser:75',
            'target' => 'field_mem_green_envcleanpdcts',
            'unique' => FALSE,
          ),
          76 => array(
            'source' => 'xpathparser:76',
            'target' => 'field_mem_green_orgsustfandb',
            'unique' => FALSE,
          ),
          77 => array(
            'source' => 'xpathparser:77',
            'target' => 'field_mem_green_orgsustfandbdet',
            'unique' => FALSE,
          ),
          78 => array(
            'source' => 'xpathparser:78',
            'target' => 'field_mem_green_donateusablefood',
            'unique' => FALSE,
          ),
          79 => array(
            'source' => 'xpathparser:79',
            'target' => 'field_mem_green_infoother',
            'unique' => FALSE,
          ),
          80 => array(
            'source' => 'xpathparser:80',
            'target' => 'field_mem_feeds_import_date',
            'unique' => FALSE,
          ),
          81 => array(
            'source' => 'xpathparser:81',
            'target' => 'field_tax_distanceaccmiles',
            'unique' => FALSE,
          ),
          82 => array(
            'source' => 'xpathparser:82',
            'target' => 'field_tax_distanceacckm',
            'unique' => FALSE,
          ),
          83 => array(
            'source' => 'xpathparser:83',
            'target' => 'field_tax_distancesnamiles',
            'unique' => FALSE,
          ),
          84 => array(
            'source' => 'xpathparser:84',
            'target' => 'field_tax_distancesnakm',
            'unique' => FALSE,
          ),
          85 => array(
            'source' => 'xpathparser:85',
            'target' => 'field_tax_financial',
            'unique' => FALSE,
          ),
          86 => array(
            'source' => 'xpathparser:86',
            'target' => 'field_tax_diningrates',
            'unique' => FALSE,
          ),
          87 => array(
            'source' => 'xpathparser:87',
            'target' => 'field_tax_diningmealsserved',
            'unique' => FALSE,
          ),
          88 => array(
            'source' => 'xpathparser:88',
            'target' => 'field_tax_diningamenities',
            'unique' => FALSE,
          ),
          89 => array(
            'source' => 'xpathparser:89',
            'target' => 'field_tax_specialservices',
            'unique' => FALSE,
          ),
          90 => array(
            'source' => 'xpathparser:90',
            'target' => 'field_tax_lodgingrates_visitors',
            'unique' => FALSE,
          ),
          91 => array(
            'source' => 'xpathparser:91',
            'target' => 'field_tax_lodgingroomcount_vis',
            'unique' => FALSE,
          ),
          92 => array(
            'source' => 'xpathparser:92',
            'target' => 'field_tax_lodgingtotalrooms',
            'unique' => FALSE,
          ),
          93 => array(
            'source' => 'xpathparser:93',
            'target' => 'field_tax_lodgingtotalsuites',
            'unique' => FALSE,
          ),
          94 => array(
            'source' => 'xpathparser:94',
            'target' => 'field_tax_totalcommittablerooms',
            'unique' => FALSE,
          ),
          95 => array(
            'source' => 'xpathparser:95',
            'target' => 'field_tax_disabledequiprooms',
            'unique' => FALSE,
          ),
          96 => array(
            'source' => 'xpathparser:96',
            'target' => 'field_tax_estrackrate',
            'unique' => FALSE,
          ),
          97 => array(
            'source' => 'xpathparser:97',
            'target' => 'field_tax_totalmeetingrooms',
            'unique' => FALSE,
          ),
          98 => array(
            'source' => 'xpathparser:98',
            'target' => 'field_tax_disabledaccessmeetroom',
            'unique' => FALSE,
          ),
          99 => array(
            'source' => 'xpathparser:99',
            'target' => 'field_tax_noofrestaurants',
            'unique' => FALSE,
          ),
          100 => array(
            'source' => 'xpathparser:100',
            'target' => 'field_tax_maxrestaurantcap',
            'unique' => FALSE,
          ),
          101 => array(
            'source' => 'xpathparser:101',
            'target' => 'field_tax_maxtheatercap',
            'unique' => FALSE,
          ),
          102 => array(
            'source' => 'xpathparser:102',
            'target' => 'field_tax_maxbanquetcap',
            'unique' => FALSE,
          ),
          103 => array(
            'source' => 'xpathparser:103',
            'target' => 'field_tax_maxreceptioncap',
            'unique' => FALSE,
          ),
          104 => array(
            'source' => 'xpathparser:104',
            'target' => 'field_tax_maxmeetingroomsqft',
            'unique' => FALSE,
          ),
          105 => array(
            'source' => 'xpathparser:105',
            'target' => 'field_tax_venue_minprivatecap',
            'unique' => FALSE,
          ),
          106 => array(
            'source' => 'xpathparser:106',
            'target' => 'field_tax_meeting_amenities',
            'unique' => FALSE,
          ),
          107 => array(
            'source' => 'xpathparser:107',
            'target' => 'field_tax_venue_maxtheatercap',
            'unique' => FALSE,
          ),
          108 => array(
            'source' => 'xpathparser:108',
            'target' => 'field_tax_venue_maxbanquetcap',
            'unique' => FALSE,
          ),
          109 => array(
            'source' => 'xpathparser:109',
            'target' => 'field_tax_venue_maxreceptioncap',
            'unique' => FALSE,
          ),
          110 => array(
            'source' => 'xpathparser:110',
            'target' => 'field_tax_venue_maxmeetingsqft',
            'unique' => FALSE,
          ),
          111 => array(
            'source' => 'xpathparser:111',
            'target' => 'field_tax_venue_buyoutcapacity',
            'unique' => FALSE,
          ),
          112 => array(
            'source' => 'xpathparser:112',
            'target' => 'field_tax_venue_locationtype',
            'unique' => FALSE,
          ),
          113 => array(
            'source' => 'xpathparser:113',
            'target' => 'field_tax_venue_accommodations',
            'unique' => FALSE,
          ),
          114 => array(
            'source' => 'xpathparser:114',
            'target' => 'field_tax_venue_alcohol',
            'unique' => FALSE,
          ),
          115 => array(
            'source' => 'xpathparser:115',
            'target' => 'field_tax_venue_catering',
            'unique' => FALSE,
          ),
          116 => array(
            'source' => 'xpathparser:116',
            'target' => 'field_tax_venue_parking',
            'unique' => FALSE,
          ),
          117 => array(
            'source' => 'xpathparser:117',
            'target' => 'field_tax_venue_maxprivatecap',
            'unique' => FALSE,
          ),
          118 => array(
            'source' => 'xpathparser:118',
            'target' => 'field_mem_phone_reservations',
            'unique' => FALSE,
          ),
        ),
        'input_format' => '0',
        'author' => '1',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['partner_listing_upload'] = $feeds_importer;
  return $export;
}
