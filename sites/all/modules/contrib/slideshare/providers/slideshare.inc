<?php
// $Id: slideshare.inc,v 1.7 2009/12/05 18:35:24 sfyn Exp $

/**
 * @file
 *
 * Implementation of Embedded Media Field hooks.
 */
define('EMVIDEO_SLIDESHARE_MAIN_URL', 'http://slideshare.net/');
define('EMVIDEO_SLIDESHARE_XML', 'http://www.slideshare.net/api/2/');
define('EMVIDEO_SLIDESHARE_DOMAIN_DEFAULT', 'net');

/**
 * Implementation of hook_<provider>_info()
 */
function emvideo_slideshare_info() {
  return array(
    'provider' => 'slideshare',
    'name' => t('Slideshare'),
    'url' => EMVIDEO_SLIDESHARE_MAIN_URL,
    'settings_description' => t('These settings specifically affect videos displayed from <a href="@slideshare" target="_blank">Slideshare</a>.', array('@slideshare' => EMVIDEO_SLIDESHARE_MAIN_URL )),
    'supported_features' => array(
       array(t('Autoplay'), t('No'), ''),
       array(t('RSS Attachment'), t('No'), ''),
       array(t('Thumbnails'), t('Yes'), ''),
    ),
  );
}

/**
 * Implementation of hook_<provider>_settings()
 */
function emvideo_slideshare_settings() {
  $form = array();
  $form['emvideo_slideshare_api_key'] = array(
    '#type' => 'textfield', '#title' => t('API Key'),
    '#default_value' => variable_get('emvideo_slideshare_api_key', ''),
    '#description' => t('API key provided by SlideShare, to obtain one apply to <a href="http://www.slideshare.net/developers/applyforapi" target="_blank">http://www.slideshare.net/applyforapi</a>.')
  );
  $form['emvideo_slideshare_shared_secret'] = array(
    '#type' => 'textfield', '#title' => t('Shared Secret'),
    '#default_value' => variable_get('emvideo_slideshare_shared_secret', ''),
    '#description' => t('Shared Secret by SlideShare, to obtain one apply to <a href="http://www.slideshare.net/developers/applyforapi" target="_blank">http://www.slideshare.net/applyforapi</a>.')
  );

  //  Username and Password for future development.
//  $form['emvideo_slideshare_username'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Username'),
//    '#default_value' => variable_get('emvideo_slideshare_username', ''),
//    '#description' => t('Username of your Slideshare account, only required for advanced requests.')
//  );
//  $form['emvideo_slideshare_password'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Password'),
//    '#default_value' => variable_get('emvideo_slideshare_password', ''),
//    '#description' => t('Password of your Slideshare account, only required for advanced requests.')
//  );
  return $form;
}

/**
 * Parser function for submissions via emvideo.
 *
 * @param $embed
 *   A URL or wordpress embed code for the slideshow to embed.
 * @return
 *   The slideshow_id of the slideshare presentation.
 *
 * TODO: refine the regex used to match urls so it can pull a url out of the regular
 * embed code, or write a condition to pull the slideshow id out of the embed code.
 */
function emvideo_slideshare_extract($embed) {
  $matches = NULL;
  if (preg_match('/[0-9]+/',filter_xss($embed, array('div')),$matches)) { //Parse regular and wordpress embed code
    return $matches[0];
  }
  else if (preg_match('/http:.+www.slideshare.net[^#.]+/',check_url($embed),$matches)) { //URL parsing

    // Very inefficient - getting the slideshow id from the url
    $api_key = variable_get('emvideo_slideshare_api_key', '');
    $shared_secret = variable_get('emvideo_slideshare_shared_secret', '');

    if ($api_key && $shared_secret) {
      $ts = time();
      $hash = sha1($shared_secret . $ts);
      $args['api_key'] = $api_key;
      $args['ts'] = $ts;
      $args['hash'] = $hash;
      $args['slideshow_url'] = $matches[0];
      $cacheable = FALSE;

      $result = module_invoke('emfield', 'request_xml', 'slideshare', EMVIDEO_SLIDESHARE_XML .'get_slideshow', $args, $cacheable);
      return $result['SLIDESHOW']['ID'][0];
    }
  }
  else {
    return FALSE;
  }
}

/**
 * Implementation of hook_<provider>_request()
 */
function emvideo_slideshare_request($embed, $cacheable = TRUE) {
  /**
   * ATTENTION: in case we will save wrong data or we will change the way we will store the data,
   * which is possible since we will store the id and not the full url, we can always reload by running
   * the function emfield_reload($nid)
   */
  $api_key = variable_get('emvideo_slideshare_api_key', '');
  $shared_secret = variable_get('emvideo_slideshare_shared_secret', '');

  if ($api_key && $shared_secret) {
    $ts = time();
    $hash = sha1($shared_secret . $ts);
//    $username = variable_get('emvideo_slideshare_username', '');
//    $password = variable_get('emvideo_slideshare_password', '');
    watchdog ('slideshare','embed contains '.$embed);
    $args['api_key'] = $api_key;
    $args['ts'] = $ts;
    $args['hash'] = $hash;
    $args['slideshow_id'] = $embed;
    $cacheable = FALSE;

    $result = module_invoke('emfield', 'request_xml', 'slideshare', EMVIDEO_SLIDESHARE_XML .'get_slideshow', $args, $cacheable);
    return $result;
  }
  else {
    return array();
  }
}

/**
 * Implementation of hook_<provider>_video_link()
 */
function emvideo_slideshare_video_link($video_code) {
  //  return 'http://video.slideshare.'. variable_get('emvideo_slideshare_domain', EMVIDEO_SLIDESHARE_DOMAIN_DEFAULT) .'/videoplay?docid='. $video_code;
  return NULL;
}

/**
 * Implementation of hook_<provider>_data()
 */
function emvideo_slideshare_data($field, $item) {
  $result = emvideo_slideshare_request($item['value']);
  return $result['SLIDESHOW'];
}

/**
 * Implementation of hook_<provider>_thumbnail()
 */
function emvideo_slideshare_thumbnail($field, $item, $formatter, $node, $width, $height) {
  return $item['data']['THUMBNAILURL'][0];
}

/**
 * Implementation of hook_<provider>_video()
 */
function emvideo_slideshare_video($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('slideshare_flash', $embed, $width, $height, $field, $item, $node, $autoplay);
  return $output;
}

/**
 * Implementation of hook_<provider>_preview()
 */
function emvideo_slideshare_preview($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('slideshare_flash', $embed, $width, $height, $field, $item, $node, $autoplay);
  return $output;
}
