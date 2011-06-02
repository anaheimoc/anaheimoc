<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function anaheimoc_convention_calendar_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'convention_calendar_feed';
  $feeds_importer->config = array(
    'name' => 'Convention Calendar Feed',
    'description' => 'Import convention calendar nodes',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => 'TAB',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'convention_calendar',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Date Start',
            'target' => 'field_convention_datetime:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Date End',
            'target' => 'field_convention_datetime:end',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Status',
            'target' => 'field_convention_status',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Region',
            'target' => 'field_convention_region',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Est. Attendance',
            'target' => 'field_convention_attendance_est',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Est Out of Town',
            'target' => 'field_convention_ota_est',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'RoomEstimate',
            'target' => 'field_convention_rooms_est',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Code',
            'target' => 'field_convention_code',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'First Name',
            'target' => 'field_convention_contact_first',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Last Name',
            'target' => 'field_convention_contact_last',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Title',
            'target' => 'field_convention_contact_title',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Company',
            'target' => 'field_convention_account_company',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'Address 1',
            'target' => 'field_convention_account_addr_1',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Address 2',
            'target' => 'field_convention_account_addr_2',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'Address 3',
            'target' => 'field_convention_account_addr_3',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'City',
            'target' => 'field_convention_account_city',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'State',
            'target' => 'field_convention_account_state',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'Zip',
            'target' => 'field_convention_account_zip',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'Country',
            'target' => 'field_convention_account_country',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'Phone',
            'target' => 'field_convention_account_phone',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'Fax',
            'target' => 'field_convention_account_fax',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'Email',
            'target' => 'field_convention_account_email',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'Web',
            'target' => 'field_convention_account_url',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'Hotel HQ',
            'target' => 'field_convention_hq_hotels',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['convention_calendar_feed'] = $feeds_importer;
  return $export;
}
