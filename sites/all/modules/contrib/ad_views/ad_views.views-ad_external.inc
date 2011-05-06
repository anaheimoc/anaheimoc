<?php
// $Id: ad_views.views-ad_external.inc,v 1.1.2.3 2009/09/11 01:25:57 milesgillham Exp $
/*
 * @file
 *
 * This file provides ad_external module Views interface:
 *      Ad External (ad_external)
 *        {ad_external}
 *
 */

function get_ad_external_views_data() {
  $data = array();
  if (db_table_exists('ad_external')) {
    // All ads are in a single table group
    $data['ad_external']['table']['group'] = t('Ad External');
    // ad_external is a related table to ads
    $data['ad_external']['table']['join']['ads'] = array(
      'left_field' => 'aid',
      'field' => 'aid'
    );

    // Ad external - 'url'
    $data['ad_external']['url'] = array(
      'title' => t('URL'),
      // The help that appears on the UI
      'help' => t('The externnal ad URL.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_url',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_string',
        'name field' => 'title',
        'numeric' => FALSE,
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_string'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
  }
  return $data;
}

