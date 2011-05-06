<?php
// $Id: ad_views.views.inc,v 1.18.2.10 2010/10/10 04:32:18 milesgillham Exp $
/*
 * @file
 *
 * This file provides multiple module Views interfaces. Support for Ad
 * modules is only loaded if the module is presently active.
 *
 * TODO:
 *    Ad Notify (ad_notify)
 *    Ad Owners (ad_owners)
 *    Ad Channel (ad_channel)
 *
 */


/**
 *  Implementation of hook_views_handlers().
 */
function ad_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'ad_views'),
      ),
    'handlers' => array(
      'ad_views_handler_field_markup' => array(
        'parent' => 'views_handler_field_markup',
        ),
      ),
    );
}

/*
 * Implements hook_views_plugins()
 */

function ad_views_views_plugins() {
  $data = array();
  $data['row']['ad'] = array(
    'title' => t('Advertisement'),
    'help' => t('Display the advertisement node view.'),
    'handler' => 'ad_views_plugin_row_ad',
    'theme' => 'ad_views_view_row_ad',
    'uses options' => TRUE,
    'type' => 'normal',
    );
  return $data;
}

/*
 * Implements hook_views_data()
 */

function ad_views_views_data() {
  $ad_data = array();
  // If the Views module and the Ad module are present then provide some views support
  if ((module_exists('views')) && (module_exists('ad'))) {
    // Primary table(s) supplied by Ad module
    $ad_data = array_merge($ad_data, get_ad_views_data());
    // We support these by module name ad_views.views-xxx.inc
    $ad_views_dir = drupal_get_path('module', 'ad_views'); // find where we live
    $supported_modules = glob($ad_views_dir . '/ad_views.views-*.inc');
    $supported_modules = preg_replace('/.*ad_views\.views-(.+)\.inc/', '$1', $supported_modules);
    // Step through each module to load only what is required
    foreach ($supported_modules as $module) {
      // is module registered?
      if (module_exists($module)) {
        // File name is ad_views.views-module.inc
        module_load_include('inc', 'ad_views', 'ad_views.views-'. $module);
        // Load function is get_module_views_data()
        $func = 'get_'. $module .'_views_data';
        $ad_data = array_merge($ad_data, $func());
      }
    }
  }
  return $ad_data;
}

#####################################################################
### Internal functions
#####################################################################

/*
 * Ad Module
 * ads is a valid base as it has first class data
 */
function get_ad_views_data() {
  $data = array();
  $data['ads']['table']['group'] = t('Ad');
  $data['ad_statistics']['table']['group'] = t('Ad Stats');
  $data['ad_clicks']['table']['group'] = t('Ad Clicks');
  // Base table is 'ads'
  $data['ads']['table']['base'] = array(
    'field' => 'aid',
    'title' => t('Advertisement'),
    'help' => t('The Ad item type allows views of Ad Module advertisements.'),
    'weight' => -10
  );

  // Join to Ads from Taxonomy Terms via a bunch of tables
  $data['term_data']['table']['join']['ads'] = array(
    'left_table' => 'term_node',
    'left_field' => 'tid',
    'field' => 'tid'
  );
  $data['term_node']['table']['join']['ads'] = array(
    'left_field' => 'aid',
    'field' => 'nid'
  );
/*
  $data['term_node']['table']['join']['ads'] = array(
    'left_table' => 'node',
    'left_field' => 'nid',
    'field' => 'nid'
  );
*/
  // node_revisions is a related table to ads
  $data['node_revisions']['table']['join']['ads'] = array(
    'left_table' => 'node',
    'left_field' => 'vid',
    'field' => 'vid'
  );
  // node is a related table to ads
  $data['node']['table']['join']['ads'] = array(
    'left_field' => 'aid',
    'field' => 'nid'
  );
  // users_roles is a related table to ads via users
  $data['users_roles']['table']['join']['ads'] = array(
    'left_table' => 'users',
    'left_field' => 'uid',
    'field' => 'uid'
  );
  // users is a related table to ads
  $data['users']['table']['join']['ads'] = array(
    'left_field' => 'uid',
    'field' => 'uid'
  );
  // ad_statistics is a related table to ads
  $data['ad_statistics']['table']['join']['ads'] = array(
    'left_field' => 'aid',
    'field' => 'aid'
  );
  // ad_clicks is a related table to ads
  $data['ad_clicks']['table']['join']['ads'] = array(
    'left_field' => 'aid',
    'field' => 'aid'
  );
  // Ad ID - 'aid'
  $data['ads']['aid'] = array(
    'title' => t('Aid'),
    // The help that appears on the UI
    'help' => t('The Ad ID of the ad.'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE
    ),
    // Table relationship
    'relationship' => array(
      'label' => t('Node'),
      'base' => 'node',
      'base field' => 'nid',
      // This allows us to not show this relationship if the base is already
      // node so won't create circular relationships.
      'skip base' => array('node')
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
/*
  // Ad rid - 'rid'
  $data['ads']['rid'] = array(
    'title' => t('Role'),
    // The help that appears on the UI
    'help' => t('The role id that relates to the userr that owns this ad'),
    // Table relationship
    'relationship' => array(
      'label' => t('User'),
      'base' => 'users',
      'base field' => 'uid',
      // This allows us to not show this relationship if the base is already
      // user so users won't create circular relationships.
      'skip base' => array('users')
    )
  );
*/
  // Ad uid - 'uid'
  $data['ads']['uid'] = array(
    'title' => t('User'),
    // The help that appears on the UI
    'help' => t('The users uid that owns this ad; initially, this is the user that created it.'),
/*
    // Table relationship
    'relationship' => array(
      'label' => t('User'),
      'base' => 'users',
      'base field' => 'uid',
      // This allows us to not show this relationship if the base is already
      // user so users won't create circular relationships.
      'skip base' => array('users')
    ),
*/
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_numeric'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad Status - 'adstatus'
  $data['ads']['adstatus'] = array(
    'title' => t('Status'),
    // The help that appears on the UI
    'help' => t('The approval status of the ad.'),
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
  // Ad Type - 'adtype'
  $data['ads']['adtype'] = array(
    'title' => t('Type'),
    // The help that appears on the UI
    'help' => t('The type of ad.'),
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
  // Ad Redirect - 'redirect'
  $data['ads']['redirect'] = array(
    'title' => t('Redirect URL'),
    // The help that appears on the UI
    'help' => t('The URL to redirect to.'),
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
  // Ad autoactivate - 'autoactivate'
  $data['ads']['autoactivate'] = array(
    'title' => t('Auto activate'),
    // The help that appears on the UI
    'help' => t('Is ad autoactivating?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad autoactivated - 'autoactivated'
  $data['ads']['autoactivated'] = array(
    'title' => t('Auto activated'),
    // The help that appears on the UI
    'help' => t('Is ad autoactivated?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad autoexpire - 'autoexpire'
  $data['ads']['autoexpire'] = array(
    'title' => t('Auto expire'),
    // The help that appears on the UI
    'help' => t('Is ad autoexpiring?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad autoexpired - 'autoexpired'
  $data['ads']['autoexpired'] = array(
    'title' => t('Auto expired'),
    // The help that appears on the UI
    'help' => t('Is ad autoexpired?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad activated - 'activated'
  $data['ads']['activated'] = array(
    'title' => t('Activated'),
    // The help that appears on the UI
    'help' => t('Is ad activated?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad maxviews - 'maxviews'
  $data['ads']['maxviews'] = array(
    'title' => t('Max views'),
    // The help that appears on the UI
    'help' => t('Maximum ad impressions.'),
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
  // Ad maxclicks - 'maxclicks'
  $data['ads']['maxclicks'] = array(
    'title' => t('Max clicks'),
    // The help that appears on the UI
    'help' => t('Maximum ad clicks.'),
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
  // Ad expired - 'expired'
  $data['ads']['expired'] = array(
    'title' => t('Expired'),
    // The help that appears on the UI
    'help' => t('Is ad expired?'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort'
    )
  );
  // Ad statistics - 'date'
  $data['ad_statistics']['date'] = array(
    'title' => t('Action date'),
    // The help that appears on the UI
    'help' => t('Date when action was made.'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_date'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort_date'
    )
  );
  // Ad statistics - 'action'
  // TODO - can we make this an enum with some custom
  // handlers?
  $data['ad_statistics']['action'] = array(
    'title' => t('Action type'),
    // The help that appears on the UI
    'help' => t('Actions: "view", "click", "enable", "disable".'),
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
  // Ad statistics - 'adgroup'
  $data['ad_statistics']['adgroup'] = array(
    'title' => t('Ad group'),
    // The help that appears on the UI
    'help' => t('Ad group.'),
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
  // Ad statistics - 'hostid'
  $data['ad_statistics']['hostid'] = array(
    'title' => t('Hostid'),
    // The help that appears on the UI
    'help' => t('Host from which action was made.'),
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
  // Ad statistics - 'count'
  $data['ad_statistics']['count'] = array(
    'title' => t('Action count'),
    // The help that appears on the UI
    'help' => t('Count of actions triggered.'),
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
  // Ad statistics - 'extra'
  $data['ad_statistics']['extra'] = array(
    'title' => t('Extra'),
    // The help that appears on the UI
    'help' => t('Allow add-on modules to provide additional statistics granularity.'),
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
  // Ad clicks - 'uid'
  $data['ad_clicks']['uid'] = array(
    'title' => t('User'),
    // The help that appears on the UI
    'help' => t('The {users}.uid that clicked this node.'),
    // Table relationship
    'relationship' => array(
      'label' => t('User'),
      'base' => 'users',
      'base field' => 'uid',
      // This allows us to not show this relationship if the base is already
      // user so users won't create circular relationships.
      'skip base' => array('users')
    )
  );
  // Ad clicks - 'status'
  $data['ad_clicks']['status'] = array(
    'title' => t('Status'),
    // The help that appears on the UI
    'help' => t('Status.'),
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
  // Ad clicks - 'hostname'
  $data['ad_clicks']['hostname'] = array(
    'title' => t('Host name'),
    // The help that appears on the UI
    'help' => t('Host from which action was made.'),
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
  // Ad clicks - 'user_agent'
  $data['ad_clicks']['user_agent'] = array(
    'title' => t('User agent'),
    // The help that appears on the UI
    'help' => t('Clicker\'s browser agent.'),
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
  // Ad clicks - 'adgroup'
  $data['ad_clicks']['adgroup'] = array(
    'title' => t('Ad group'),
    // The help that appears on the UI
    'help' => t('Ad group.'),
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
  // Ad clicks - 'hostid'
  $data['ad_clicks']['hostid'] = array(
    'title' => t('Hostid'),
    // The help that appears on the UI
    'help' => t('Host from which action was made.'),
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
  // Ad clicks - 'url'
  $data['ad_clicks']['url'] = array(
    'title' => t('URL'),
    // The help that appears on the UI
    'help' => t('Clicked URL.'),
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
  // Ad clicks - 'timestamp'
  $data['ad_clicks']['timestamp'] = array(
    'title' => t('Time stamp'),
    // The help that appears on the UI
    'help' => t('Date when action was made.'),
    // Information for displaying
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE
    ),
    // Information for accepting as an argument
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'title',
      'numeric' => TRUE,
    ),
    // Information for accepting as a filter
    'filter' => array(
      'handler' => 'views_handler_filter_date'
    ),
    // Information for sorting
    'sort' => array(
      'handler' => 'views_handler_sort_date'
    )
  );
  // Ad clicks - 'extra'
  $data['ad_clicks']['extra'] = array(
    'title' => t('Extra'),
    // The help that appears on the UI
    'help' => t('Allow add-on modules to provide additional statistics granularity.'),
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

