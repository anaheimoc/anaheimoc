<?php
// $Id: ad_views.views_default.inc,v 1.6.2.2 2009/09/10 22:23:08 milesgillham Exp $
/*
 * @file
 *
 * Default views.
 * By default they will not be enabled.
 */

/*
 * Implements hook_views_default_views()
 */

function ad_views_views_default_views() {
  $views = array();
  $view = ad_views_views_default_view_ads();
  if (!empty($view)) {
    $views[$view->name] = $view;
  }
  return $views; 
}

function ad_views_views_default_view_ads() {
  $view = new view;
  $view->name = 'Random advertisement';
  $view->description = 'Example view that displays a random advertisement.';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'ads';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'aid' => array(
      'id' => 'aid',
      'table' => 'ads',
      'field' => 'aid',
    ),
  ));
  $handler->override_option('sorts', array(
    'random' => array(
      'id' => 'random',
      'table' => 'views',
      'field' => 'random',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 1);
  $handler->override_option('distinct', 0);
  $handler->override_option('row_plugin', 'ad');
  $handler->override_option('row_options', array(
    'teaser_only' => 0,
  ));
  return $view;
}
