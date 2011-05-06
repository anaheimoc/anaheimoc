<?php
// $Id: ad_views.views-ad_flash.inc,v 1.2.2.2 2009/09/10 22:23:08 milesgillham Exp $
/*
 * @file
 *
 * This file provides ad_flash module Views interface:
 *      Ad Flash (ad_flash)
 *        {ad_flash}
 *
 */

function get_ad_flash_views_data() {
  $data = array();
  if (db_table_exists('ad_flash')) {
    // All ads are in a single table group
    $data['ad_flash']['table']['group'] = t('Ad Flash');
    // ad_flash is a related table to ads
    $data['ad_flash']['table']['join']['ads'] = array(
      'left_field' => 'aid',
      'field' => 'aid'
    );

    // Ad flash - 'fid' relationship
    $data['ad_flash']['fid'] = array(
      'title' => t('Fid'),
      // The help that appears on the UI
      'help' => t('The {files}.fid File ID that this ad relates to.'),
      // Table relationship
      'relationship' => array(
        'label' => t('Files'),
        'base' => 'files',
        'base field' => 'fid',
        // This allows us to not show this relationship if the base is already
        // files so files won't create circular relationships.
        'skip base' => array('files')
      )
    );
    // Ad flash - 'url'
    $data['ad_flash']['url'] = array(
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
    // Ad flash - 'width'
    $data['ad_flash']['width'] = array(
      'title' => t('Width'),
      // The help that appears on the UI
      'help' => t('Ad width.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
    // Ad flash - 'height'
    $data['ad_flash']['height'] = array(
      'title' => t('Height'),
      // The help that appears on the UI
      'help' => t('Ad height.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
  }

  if (db_table_exists('ad_flash_format')) {
    // All ads are in a single table group
    $data['ad_flash_format']['table']['group'] = t('Ad Flash Format');
    $data['ad_flash_format']['table']['base'] = array(
      'field' => 'gid',
      'title' => t('Ad Flash Format'),
      'help' => t('Flash module ad formats.')
    );

    // Ad flash format gid - 'gid'
    $data['ad_flash_format']['gid'] = array(
      'title' => t('Gid'),
      // The help that appears on the UI
      'help' => t('The Ad Flash Format ID.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
    // Ad flash format - 'min_width'
    $data['ad_flash_format']['min_width'] = array(
      'title' => t('Min width'),
      // The help that appears on the UI
      'help' => t('Ad minimum width.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
    // Ad flash format - 'min_height'
    $data['ad_flash_format']['min_height'] = array(
      'title' => t('Minimum height'),
      // The help that appears on the UI
      'help' => t('Ad minimum height.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
    // Ad flash format - 'max_width'
    $data['ad_flash_format']['max_width'] = array(
      'title' => t('Max width'),
      // The help that appears on the UI
      'help' => t('Ad maximum width.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
    // Ad flash format - 'max_height'
    $data['ad_flash_format']['max_height'] = array(
      'title' => t('Maximum height'),
      // The help that appears on the UI
      'help' => t('Ad maximum height.'),
      // Information for displaying
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE
      ),
      // Information for accepting as an argument
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE
      ),
      // Information for accepting as a filter
      'filter' => array(
        'handler' => 'views_handler_filter_numeric'
      ),
      // Information for sorting
      'sort' => array(
        'handler' => 'views_handler_sort'
      )
    );
  }

  return $data;
}

