<?php

/**
 * Implementation of hook_theme().
 */
function anaheimoc_theme() {
  $items = array();
  
    // Split out pager list into separate theme function.
  $items['pager_list'] = array('arguments' => array(
    'tags' => array(),
    'limit' => 10,
    'element' => 0,
    'parameters' => array(),
    'quantity' => 9,
  ));

  return $items;
}

function anaheimoc_preprocess_page(&$vars) {
  //Add domain id variable to page.tpl.php
  global $_domain;
  $vars['domain_id'] = check_plain($_domain['domain_id']);
  //dpm($vars['front_page']);
  
  // Alter the $logo link on the microsite section
  if ($_domain['domain_id'] == 6){
    $vars['front_page'] = '';
  }
}

/**
 * The following function will work to override/add
 * general views theming functions and is independent
 * of any particular theme.
 */
function phptemplate_preprocess_views_view(&$vars){
	$view = $vars['view'];

	// Adds a views counter to all views.
	
	// If the view has results, show a counter of how many results there are
	if ($view->total_rows >= 1){
		$start = ($view->pager['current_page'] * $view->pager['items_per_page']) + 1;
		$finish = $start + count($view->result) - 1;
		$total = $view->total_rows;
		$vars['views_of_counter'] =  'Displaying ' . $start . ' - ' . $finish . ' of ' . $total;		
		}
		
	// If the view returns no results, show nothing
	else {
		$vars['views_of_counter'] =  '';
		}	
}


/**
 *Custom Search Block Form
 */
 
function anaheimoc_search_theme_form($form) {
  $form['search_theme_form']['#title'] = '';
  $form['search_theme_form']['#size'] = 22;
  $form['search_theme_form']['#value'] = '';
  $form['submit']['#value'] = '';
  $form['submit']['#type'] = 'image_button';
  $form['submit']['#src'] = drupal_get_path('theme', 'anaheimoc') . '/images/search.png';
  $form['submit']['#attributes']['class'] = 'btn';
  return '<div id="search" class="container-inline">' . drupal_render($form) . '</div>';
}

function anaheimoc_preprocess_node(&$variables, $hook) {
  $node = $variables['node'];
  // Variables available to every node are defined here

  // Now define node type-specific variables by calling their own preprocess functions (if they exist)
  $function = 'anaheimoc_preprocess_node'.'_'. $variables['node']->type;
  if (function_exists($function)) {
   $function(&$variables);
  }
  
  // CREATE NEW SUBMITTED DATE VARIABLES FOR USE ON ALL NODE TPL FILES
  $variables['date_day'] = format_date($node->created, 'custom', 'j');
  $variables['date_month'] = format_date($node->created, 'custom', 'F');
  $variables['date_year'] = format_date($node->created, 'custom', 'Y');
}

function anaheimoc_preprocess_node_image_library_img(&$variables) {
	global $user;
	if ($user->roles[4] && $user->roles[2] || $user->roles[3]){
	$variables['image_library_access_message'] = '';
	}
	else {
	$variables['image_library_access_message'] = '<p>You are not authorized to access the Image Library Download information.</p>' . '<p>Please review the '. l('terms of use and register', 'image-library/register' ) . ' to access download information.';
	}
}

/**
 * Override of theme_pager().
 * Easily one of the most obnoxious theming jobs in Drupal core.
 * Goals: consolidate functionality into less than 5 functions and
 * ensure the markup will not conflict with major other styles
 * (theme_item_list() in particular).
 */
function anaheimoc_pager($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  $pager_list = theme('pager_list', $tags, $limit, $element, $parameters, $quantity);

  $links = array();
  $links['pager-first'] = theme('pager_first', ($tags[0] ? $tags[0] : t('First')), $limit, $element, $parameters);
  $links['pager-previous'] = theme('pager_previous', ($tags[1] ? $tags[1] : t('Prev')), $limit, $element, 1, $parameters);
  $links['pager-next'] = theme('pager_next', ($tags[3] ? $tags[3] : t('Next')), $limit, $element, 1, $parameters);
  $links['pager-last'] = theme('pager_last', ($tags[4] ? $tags[4] : t('Last')), $limit, $element, $parameters);
  $links = array_filter($links);
  $pager_links = theme('links', $links, array('class' => 'links pager pager-links'));

  if ($pager_list) {
    return "<div class='pager clear-block'>$pager_list $pager_links</div>";
  }
}

/**
 * Split out page list generation into its own function.
 */
function anaheimoc_pager_list($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  global $pager_page_array, $pager_total, $theme_key;
  if ($pager_total[$element] > 1) {
    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.

    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $links = array();

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for ($i; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $links["$i pager-item"] = theme('pager_previous', $i, $limit, $element, ($pager_current - $i), $parameters);
        }
        if ($i == $pager_current) {
          $links["$i pager-current"] = array('title' => $i);
        }
        if ($i > $pager_current) {
          $links["$i pager-item"] = theme('pager_next', $i, $limit, $element, ($i - $pager_current), $parameters);
        }
      }
      return theme('links', $links, array('class' => 'links pager pager-list'));
    }
  }
  return '';
}

/**
 * Return an array suitable for theme_links() rather than marked up HTML link.
 */
function anaheimoc_pager_link($text, $page_new, $element, $parameters = array(), $attributes = array()) {
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query[] = drupal_query_string_encode($parameters, array());
  }
  $querystring = pager_get_querystring();
  if ($querystring != '') {
    $query[] = $querystring;
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    else if (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  return array(
    'title' => $text,
    'href' => $_GET['q'],
    'attributes' => $attributes,
    'query' => count($query) ? implode('&', $query) : NULL,
  );
}

/**
 * Override of theme_views_mini_pager().
 */
function anaheimoc_views_mini_pager($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.


  $links = array();
  if ($pager_total[$element] > 1) {
    $links['pager-previous'] = theme('pager_previous', (isset($tags[1]) ? $tags[1] : t('‹‹')), $limit, $element, 1, $parameters);
    $links['pager-current'] = array('title' => t('@current of @max', array('@current' => $pager_current, '@max' => $pager_max)));
    $links['pager-next'] = theme('pager_next', (isset($tags[3]) ? $tags[3] : t('››')), $limit, $element, 1, $parameters);
    return theme('links', $links, array('class' => 'links pager views-mini-pager'));
  }
}