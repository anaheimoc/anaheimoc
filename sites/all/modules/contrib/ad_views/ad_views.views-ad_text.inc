<?php
// $Id: ad_views.views-ad_text.inc,v 1.1.2.2 2009/09/10 22:23:08 milesgillham Exp $
/*
 * @file
 *
 * This file provides ad_text module Views interface:
 *      Ad Text (ad_text)
 *        {ad_text}
 *
 */

function get_ad_text_views_data() {
  $data = array();
  if (db_table_exists('ad_text')) {
    // All ads are in a single table group
    $data['ad_text']['table']['group'] = t('Ad Text');
    // ad_text is a related table to ads
    $data['ad_text']['table']['join']['ads'] = array(
      'left_field' => 'aid',
      'field' => 'aid'
    );
    // Ad URL - 'url'
    $data['ad_text']['url'] = array(
      'title' => t('URL'),
      // The help that appears on the UI
      'help' => t('The ad URL.'),
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
    // Ad AdHeader - 'adheader'
    $data['ad_text']['adheader'] = array(
      'title' => t('Ad Header'),
      // The help that appears on the UI
      'help' => t('The ad header.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field',
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
    // Ad AdBody - 'adbody'
    $data['ad_text']['adbody'] = array(
      'title' => t('Ad Body'),
      // The help that appears on the UI
      'help' => t('The ad body.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field',
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
  return $data;
}

