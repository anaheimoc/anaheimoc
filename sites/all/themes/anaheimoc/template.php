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
		
	//Create some variables to use in Views Summary View
	
	$summary_rows = count($rows);
	$row_thirds = round($summary_rows/3);
	$row_number = 0;
			
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
  $variables['update_day'] = format_date($node->changed, 'custom', 'j');
  $variables['update_month'] = format_date($node->changed, 'custom', 'F');
  $variables['update_year'] = format_date($node->changed, 'custom', 'Y');
  
  //SHARE LINKS
  if (module_exists('service_links')) {
    if (user_access('access service links') && service_links_show($variables['node'])) {
      $variables['social_share'] = theme('links', array(
      $variables['node']->service_links['service-links-twitter'],
      $variables['node']->service_links['service-links-facebook'],
      $variables['node']->service_links['service-links-linkedin'],
      $variables['node']->service_links['service-links-google']
      ));
    }
  }
}

function anaheimoc_preprocess_node_partner_listing(&$variables) {
  //dpm($variables);
  //$node = $variables['node'];
  $variables['visitor_description'] = $variables['field_mem_description_visitor'][0]['safe'];
  $variables['meetings_description'] = $variables['field_mem_description_meetings'][0]['safe'];
  
  // Create Partner Logo variable
  $variables['partner_logo'] = theme('imagecache', 'partner_logo', $variables['field_mem_logo'][0]['filepath'],'','',array('class' => 'partner-logo'));
  
  // Create Partner Teaser Image variable
  $variables['partner_image_teaser'] = theme('imagecache', 'partner_listing_preview', $variables['field_mem_images'][0]['filepath'],'','',array('class' => 'partner-image-teaser'));
  
  // Build Gmap Teaser Array
  $map_teaser_array = array(
  'id' => "map-teaser",       // id attribute for the map
    'width' => "296px",       // map width in pixels or %
    'height' => "171px",      // map height in pixels
    'latitude' => $variables['field_mem_address'][0]['latitude'],    // map center latitude
    'longitude' => $variables['field_mem_address'][0]['longitude'],  // map center longitude
    'zoom' => 14,              // zoom level
    'maxzoom' => 14,
    'maptype' => "Map",       // baselayer type
    'controltype' => "Small",  // size of map controls
    'behavior' => array(
      'locpick' => FALSE,
      'nomousezoom' => TRUE,
      'nodrag' => TRUE,
      'nokeyboard' => FALSE,
      'overview' => FALSE,
      'scale' => FALSE,
    ),
    'markers' => array(
      array(
		    'options' => array(),
		    'text' => 'Partner Location',
		    'longitude' => $variables['field_mem_address'][0]['longitude'],
		    'latitude' => $variables['field_mem_address'][0]['latitude'],
		    'markername' => 'small red',
		    'offset' => 0,
	    )
    )
  );
  
  // Render gmap using theme function
  $variables['map_teaser'] = theme('gmap', array('#settings' => $map_teaser_array));
  
  
  // Create Partner Address variables
  $partner_address_street = $variables['field_mem_address'][0]['street'];
  $partner_address_city = $variables['field_mem_address'][0]['city'];
  $partner_address_state = $variables['field_mem_address'][0]['province'];
  $partner_address_province = $variables['field_mem_address'][0]['postal_code'];
  
  // Theme the address variables and send them to the node template
  $variables['partner_address'] = '<address>' . $partner_address_street . '<br />' . $partner_address_city . ', ' . $partner_address_state . ' ' . $partner_address_province . '</address>';
  
  // Phone, Fax, Toll Free and Website variables
  
  $variables['partner_phone'] = 'Phone: ' . $variables['field_mem_phone_main'][0]['safe'];
  $variables['partner_fax'] = 'Fax: ' . $variables['field_mem_phone_fax'][0]['safe'];
  $variables['partner_tollfree'] = 'Toll Free: ' . $variables['field_mem_phone_800'][0]['safe'];
  $variables['partner_website'] = l('Website', $variables['field_mem_internet_url'][0]['url'], array('attributes' => array('onclick' => 'window.open(this.href); return false;')));
  
  // Book Now Variable
  $book_now_label = $variables['field_mem_internet_res_label'][0]['safe'];
  $book_now_link = $variables['field_mem_internet_reservationur'][0]['url'];
  
  $variables['book_now'] = l($book_now_label, $book_now_link, array('attributes' => array('onclick' => 'window.open(this.href); return false;')));
  
  $variables['coupon_offer'] = views_embed_view('coupons', 'block_6', $node->nid);
  
  // Video Tour Variables
  $video_tour_label = '';
  $video_tour_link = '';
  $variables['video_tour'] = l($video_tour_label, $video_tour_link);
  
  //$variables['partner_logo'] = views_embed_view('partner_listing_alt', 'block_7', $node->nid);  
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

function anaheimoc_preprocess_nws_weather_forecast_period(&$vars){
$vars['period_start'] = date('l', $vars['timeforecast']['start-valid-unix']);
}


/**
 * Override of theme_quiz_take_summary
 */
function anaheimoc_quiz_take_summary($quiz, $questions, $score, $summary) {
  
  // Create special button for webform redirect  
  $dsp_register_link = l('CLAIM YOUR CERTIFICATE', 'oc-specialist/register', array('query' => 'pass_key=' . $score['passing'] . '&eval=' . $score['is_evaluated'], 'attributes' => array('class' => 'button')));
  $dsp_register = '<div id="call_to_action">' . $dsp_register_link . '</div>';
  
  $output .= '';
  if (!empty($score['possible_score'])) {
    if (!$score['is_evaluated']) {
      $msg = t('Parts of this @quiz have not been evaluated yet. The score below is not final.', array('@quiz' => QUIZ_NAME));
      drupal_set_message($msg, 'warning');
    }
    $output .= '<div id="quiz_score_possible">'. t('You got %num_correct of %question_count possible points.', array('%num_correct' => $score['numeric_score'], '%question_count' => $score['possible_score'])) .'</div>'."\n";
    $output .= '<div id="quiz_score_percent">'. t('Your score: %score %', array('%score' => $score['percentage_score'])) .'</div>'."\n";
  }
  if (isset($summary['passfail']))
    $output .= '<div id="quiz_summary">'. $summary['passfail'] . $dsp_register . '</div>'."\n";

  if (isset($summary['result']))
    $output .= '<div id="quiz_summary">'. $summary['result'] .'</div>'."\n";
  // Get the feedback for all questions. These are included here to provide maximum flexibility for themers
  if ($quiz->display_feedback) {
    $output .= drupal_get_form('quiz_report_form', $questions);
  }
  return $output;
}


/**
 * The slideshow controls.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_controls($vss_id, $view, $options) {
  $classes = array(
    'views_slideshow_singleframe_controls',
    'views_slideshow_controls',
  );

  $attributes['class'] = implode(' ', $classes);
  $attributes['id'] = "views_slideshow_singleframe_controls_" . $vss_id;
  $attributes = drupal_attributes($attributes);

  $output = "<div$attributes>";
  $output .= theme('views_slideshow_singleframe_control_previous', $vss_id, $view, $options);
  if ($options['views_slideshow_singleframe']['timeout']) {
    $output .= theme('views_slideshow_singleframe_control_pause', $vss_id, $view, $options);
  }
  $output .= theme('views_slideshow_singleframe_control_next', $vss_id, $view, $options);
  $output .= "</div>\n";
  return $output;
}

/**
 * Views Slideshow: "previous" control.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_control_previous($vss_id, $view, $options) {
  return l('&laquo;', '#', array(
    'attributes' => array(
      'class' => 'views_slideshow_singleframe_previous views_slideshow_previous',
      'id' => "views_slideshow_singleframe_prev_" . $vss_id,
    ),
    'fragment' => ' ',
    'external' => TRUE,
    'html' => TRUE,
  ));
}

/**
 * Views Slideshow: "pause" control.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_control_pause($vss_id, $view, $options) {
  return l(t('Pause'), '', array(
    'attributes' => array(
      'class' => 'views_slideshow_singleframe_pause views_slideshow_pause',
      'id' => "views_slideshow_singleframe_playpause_" . $vss_id,
    ),
    'fragment' => ' ',
    'external' => TRUE,
  ));
}

/**
 * Views Slideshow: "next" control.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_control_next($vss_id, $view, $options) {
  return l('&raquo;', '#', array(
    'attributes' => array(
      'class' => 'views_slideshow_singleframe_next views_slideshow_next',
      'id' => "views_slideshow_singleframe_next_" . $vss_id,
    ),
    'fragment' => ' ',
    'external' => TRUE,
    'html' => TRUE,
  ));
}

/**
 * Views Slideshow: pager.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_pager($vss_id, $view, $options) {
  $pager_type = $options['views_slideshow_singleframe']['pager_type'];

  $attributes['class'] = "views_slideshow_singleframe_pager views_slideshow_pager$pager_type";
  $attributes['id'] = "views_slideshow_singleframe_pager_" . $vss_id;
  $attributes = drupal_attributes($attributes);

  return "<div$attributes></div>";
}

/**
 * Views Slideshow: image counter.
 *
 * @ingroup themeable
 */
function anaheimoc_views_slideshow_singleframe_image_count($vss_id, $view, $options) {
  $attributes['class'] = 'views_slideshow_singleframe_image_count views_slideshow_image_count';
  $attributes['id'] = "views_slideshow_singleframe_image_count_" . $vss_id;
  $attributes = drupal_attributes($attributes);

  $counter = '<span class="num">1</span> ' . t('of') . ' <span class="total">1</span>';

  return "<div$attributes>$counter</div>";
}