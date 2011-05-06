<?php
// $Id: ad_views.views-ad_image.inc,v 1.4.2.2 2009/09/10 22:23:08 milesgillham Exp $
/*
 * @file
 *
 * This file provides ad_image module Views interface:
 *      Ad Image (ad_image)
 *        {ad_image}
 *        {ad_image_format}
 *
 */

function get_ad_image_views_data() {
  $data = array();
  if (db_table_exists('ad_image')) {
    // All ads are in a single table group
    $data['ad_image']['table']['group'] = t('Ad Image');
    // ad_image is a related table to ads
    $data['ad_image']['table']['join']['ads'] = array(
      'left_field' => 'aid',
      'field' => 'aid'
    );

    // Ad image - 'fid' relationship
    $data['ad_image']['fid'] = array(
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
    // Ad image - 'url'
    $data['ad_image']['url'] = array(
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
    // Ad image - 'tooltip'
    $data['ad_image']['tooltip'] = array(
      'title' => t('Tooltip'),
      // The help that appears on the UI
      'help' => t('The tooltip.'),
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
    // Ad image - 'remote_image'
    $data['ad_image']['remote_image'] = array(
      'title' => t('Remote image'),
      // The help that appears on the UI
      'help' => t('The remote image URL.'),
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
    // Ad image - 'width'
    $data['ad_image']['width'] = array(
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
        'numeric' => TRUE,
        'validate type' => 'aid'
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
    // Ad image - 'height'
    $data['ad_image']['height'] = array(
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
        'numeric' => TRUE,
        'validate type' => 'aid'
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

  if (db_table_exists('ad_image_format')) {
    // All ads are in a single table group
    $data['ad_image_format']['table']['group'] = t('Ad Image Format');
    $data['ad_image_format']['table']['base'] = array(
      'field' => 'gid',
      'title' => t('Ad Image Format'),
      'help' => t('Image module ad formats.')
    );

    // Ad image format gid - 'gid'
    $data['ad_image_format']['gid'] = array(
      'title' => t('Gid'),
      // The help that appears on the UI
      'help' => t('The Ad Image Format ID.'),
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
    // Ad image format - 'min_width'
    $data['ad_image_format']['min_width'] = array(
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
    // Ad image format - 'min_height'
    $data['ad_image_format']['min_height'] = array(
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
    // Ad image format - 'max_width'
    $data['ad_image_format']['max_width'] = array(
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
    // Ad image format - 'max_height'
    $data['ad_image_format']['max_height'] = array(
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
    // Ad image format - 'max_size'
    $data['ad_image_format']['max_size'] = array(
      'title' => t('Maximum size'),
      // The help that appears on the UI
      'help' => t('Ad maximum size.'),
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

