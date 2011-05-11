<?php
// $Id: ad_views.views-ad_html.inc,v 1.1.2.8 2010/10/10 04:45:22 milesgillham Exp $
/*
 * @file
 *
 * This file provides ad_html module Views interface:
 *      Ad HTML (ad_html)
 *        {ad_html}
 *
 */

function get_ad_html_views_data() {
  $data = array();
  if (db_table_exists('ad_html')) {
    // All ads are in a single table group
    $data['ad_html']['table']['group'] = t('Ad HTML');
    // ad_html is a related table to ads
    $data['ad_html']['table']['join']['ads'] = array(
      'left_field' => 'aid',
      'field' => 'aid'
    );

/*
  $data['ad_html']['table']['join'] = array(
    'node' => array(
      'left_field' => 'aid',
      'field' => 'nid',
    ),
    // This goes to the node so that we have consistent authorship.
    'node_revisions' => array(
      'left_table' => 'node',
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
*/

    // node_revisions is a related table to ad_html
    $data['node_revisions']['table']['join']['ad_html'] = array(
      'left_table' => 'node',
      'left_field' => 'vid',
      'field' => 'vid'
    );
    $data['node']['table']['join']['ad_html'] = array(
      'left_field' => 'aid',
      'field' => 'nid'
    );

    // Ad HTML - 'html'
    $data['ad_html']['html'] = array(
      'title' => t('HTML'),
      // The help that appears on the UI
      'help' => t('The ad HTML.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_markup',
	'format' => 0
      )
    );
  }
  return $data;
}

