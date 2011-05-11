<?php
// $Id: bitsontherun.inc,v 1.1 2009/07/17 17:54:58 aaron Exp $

/**
 * @file
 *   This include processes bitsontherun.com media files for use by emfield.module.
 */

define('EMVIDEO_BITSONTHERUN_MAIN_URL', 'http://www.bitsontherun.com/');

/**
 *  This defines the version of the content data array that we serialize
 *  in emvideo_bitsontherun_data(). If we change the expected keys of that array,
 *  we must increment this value, which will allow older content to be updated
 *  to the new version automatically.
 */
define('EMVIDEO_BITSONTHERUN_DATA_VERSION', 1);

/**
 * hook emvideo_PROVIDER_info
 * this returns information relevant to a specific 3rd party video provider
 * @return
 *   an array of strings requested by various admin and other forms
 *   'name' => the translated name of the provider
 *   'url' => the url to the main page for the provider
 *   'settings_description' => a description of the provider that will be posted in the admin settings form
 *   'supported_features' => an array of rows describing the state of certain supported features by the provider.
 *      These will be rendered in a table, with the columns being 'Feature', 'Supported', 'Notes'.
 */
function emvideo_bitsontherun_info() {
  $features = array(
    array(t('Autoplay'), t('Yes'), ''),
    array(t('RSS Attachment'), t('Yes'), ''),
    array(t('Thumbnails'), t('Yes'), t('')),
  );
  return array(
    'provider' => 'bitsontherun',
    'name' => t('Bits On The Run'),
    'url' => EMVIDEO_BITSONTHERUN_MAIN_URL,
    'settings_description' => t('These settings specifically affect videos displayed from !bitsontherun.', array('!bitsontherun' => l(t('BitsOnTheRun.com'), EMVIDEO_BITSONTHERUN_MAIN_URL))),
    'supported_features' => $features,
  );
}

/**
 * hook emvideo_PROVIDER_settings
 * this should return a subform to be added to the emvideo_settings() admin settings page.
 * note that a form field will already be provided, at $form['PROVIDER'] (such as $form['bitsontherun'])
 * so if you want specific provider settings within that field, you can add the elements to that form field.
 */
function emvideo_bitsontherun_settings() {
  $form = array();
  $form['media_bitsontherun_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#default_value' => variable_get('media_bitsontherun_api_key', ''),
    '#description' => t('You must first apply for an API Key and Secret from !api.', array('!api' => l(t('Bits On The Run'), 'http://www.bitsontherun.com/signup/'))),
  );
  $form['media_bitsontherun_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('API Secret'),
    '#default_value' => variable_get('media_bitsontherun_api_secret', ''),
    '#description' => t('You must first apply for an API Key and Secret from !api.', array('!api' => l(t('Bits On The Run'), 'http://www.bitsontherun.com/signup/'))),
  );
  $form['media_bitsontherun_template'] = array(
    '#type' => 'textfield',
    '#title' => t('Template ID'),
    '#default_value' => variable_get('media_bitsontherun_template', '61902'),
    '#description' => t('Please enter the Template ID you wish for playback, available from any of your Bits On The Run video pages.'),
  );
  $form['media_bitsontherun_player'] = array(
    '#type' => 'textfield',
    '#title' => t('Player ID'),
    '#default_value' => variable_get('media_bitsontherun_player', '41901'),
    '#description' => t('Please enter the Player ID you wish for playback, available from the Bits On The Run !page.', array('!page' => l(t('players tab'), 'http://manage.bitsontherun.com/presentations/list'))),
  );
  return $form;
}

/**
 *  Build a unique signature to add to the query for an API call.
 *  @param array $args
 *    The query options.
 *  @return string
 *    An SHA1 hash to append to the query.
 */
function _emvideo_bitsontherun_sign($args = array()) {
  ksort($args);
  $sbs = null;
  foreach ($args as $key => $value) {
      if ($sbs != '') {
          $sbs .= '&';
      }
      // Construct Signature Base String. Ensure it will look the same
      // as when url() does its urlencoding.
      $sbs .= $key .'='. drupal_urlencode($value);
  }

  // Add shared secret to the Signature Base String and generate the signature
  $signature = sha1($sbs . variable_get('media_bitsontherun_api_secret', ''));

  return $signature;
}

/**
 *  Add the additional arguments required for each query for an API call.
 *
 *  @param array $args
 *    The query arguments.
 *  @return array
 *    The altered array.
 */
function _emvideo_bitsontherun_query($args) {
  // Generate a random 8 digit number and add the current timestamp.
  $args['api_nonce'] = str_pad(mt_rand(0, 99999999), 8, STR_PAD_LEFT);
  $args['api_timestamp'] = time();

  $args['api_key'] = variable_get('media_bitsontherun_api_key', '');

  // We could use php or json as well, but Morbus says they're all the same.
  $args['api_format'] = 'xml';

  // Sign the array of arguments.
  $args['api_signature'] = _emvideo_bitsontherun_sign($args);

  return $args;
}

/**
 * hook emvideo_PROVIDER_data
 *
 * provides an array to be serialised and made available with $item elsewhere
 */
function emvideo_bitsontherun_data($field, $item) {
  // <http|s>://<APIserver>/<APIversion>/<callClass>/<callSubclass>/<method|attribute>[?<parameters>]
  //http://api.bitsontherun.com/v1/videos/list?text=d%C3%A9mo&api_nonce=80684843&api_timestamp=1237387851&api_format=xml&api_signature=fbdee51a45980f9876834dc5ee1ec5e93f67cb89&api_key=XOqEAfxj
//   $options = array(
//     'video_key' => $item['value'],
//   );
//   dpm(_emvideo_bitsontherun_query($options));
//   dpm(url("http://api.bitsontherun.com/v1/videos/thumbnails/show", array('query' => _emvideo_bitsontherun_query($options))));
//   $xml = emfield_request_xml('bitsontherun', 'http://api.bitsontherun.com/v1/videos/thumbnails/show', _emvideo_bitsontherun_query($options));
//   $xml = simplexml_load_file(url("http://api.bitsontherun.com/v1/videos/thumbnails/show", array('query' => _emvideo_bitsontherun_query($options))));
//   dpm($xml);
//   if ($xml->response['status'] == 'ok') {
//   }
//   return $data;
}

/**
 *
 */
function emvideo_bitsontherun_rss($item, $teaser = NULL) {
}

/**
 * hook emvideo_PROVIDER_extract
 * this is called to extract the video code from a pasted URL or embed code.
 * @param $embed
 *   an optional string with the pasted URL or embed code
 * @return
 *   either an array of regex expressions to be tested, or a string with the video code to be used
 *   if the hook tests the code itself, it should return either the string of the video code (if matched), or an empty array.
 *   otherwise, the calling function will handle testing the embed code against each regex string in the returned array.
 */
function emvideo_bitsontherun_extract($embed = '') {
  // http://content.bitsontherun.com/preview/wCmux3Ov-61904-41917
  // <script type="text/javascript" src="http://content.bitsontherun.com/players/wCmux3Ov-61904-41917.js"></script>
  // <embed src="http://content.bitsontherun.com/players/wCmux3Ov-61904-41917.swf" width="640" height="480" bgcolor="#99ff99" allowfullscreen="true" allowscriptaccess="always"/>
  return array(
    '@\.bitsontherun\.com/preview/(.*?)-@i',
    '@\.bitsontherun\.com/players/(.*?)-@i',
  );
}

/**
 * hook emvideo_PROVIDER_embedded_link($video_code)
 * returns a link to view the video at the provider's site
 *  @param $video_code
 *    the string containing the video to watch
 *  @return
 *    a string containing the URL to view the video at the original provider's site
 */
function emvideo_bitsontherun_embedded_link($video_code) {
  $template = variable_get('media_bitsontherun_template', '328');
  $player = variable_get('media_bitsontherun_player', '1754');
  return "http://content.bitsontherun.com/preview/$code-$template-$player";
}

/**
 * The embedded flash displaying the bitsontherun video.
 */
function theme_emvideo_bitsontherun_flash($item, $width, $height, $autoplay) {
  $output = '';
  if ($code = drupal_urlencode($item['value'])) {
    $template = variable_get('media_bitsontherun_template', '328');
    $player = variable_get('media_bitsontherun_player', '1754');
    $autostart = $autoplay ? 'true' : 'false';
    if (variable_get('emfield_swfobject', FALSE)) {
      if (module_exists('swfobject_api')) {
        $url = "http://content.bitsontherun.com/players/$code-$template-$player.swf";
        $params = array('width' => $width, 'height' => $height);
        $variables = array('autostart' => $autostart);
        $output = theme("swfobject_api", $url, $params, $variables);
      }
      else {
        // @TODO
      }
    }
    else {
    $output = <<<FLASH
    <object id="player" classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" name="player" width="$width" height="$height">
      <param name="movie" value="http://content.bitsontherun.com/players/$code-$template-$player.swf" />
      <param name="bgcolor" value="#000000" />
      <param name="allowfullscreen" value="true" />
      <param name="flashvars" value="" />
      <object type="application/x-shockwave-flash" data="http://content.bitsontherun.com/players/$code-$template-$player.swf" width="$width" height="$height">
        <param name="bgcolor" value="#000000" />
        <param name="allowfullscreen" value="true" />
        <param name="flashvars" value="autostart=$autostart" />
        <p><a href="http://get.adobe.com/flashplayer">Get Flash</a> to see this player.</p>
      </object>
    </object>
FLASH;
    }
  }
  return $output;
}

/**
 * hook emvideo_PROVIDER_thumbnail
 * returns the external url for a thumbnail of a specific video
 * TODO: make the args: ($embed, $field, $item), with $field/$item provided if we need it, but otherwise simplifying things
 *  @param $field
 *    the field of the requesting node
 *  @param $item
 *    the actual content of the field from the requesting node
 *  @return
 *    a URL pointing to the thumbnail
 */
function emvideo_bitsontherun_thumbnail($field, $item, $formatter, $node, $width, $height) {
  return "http://content.bitsontherun.com/thumbs/{$item['value']}-$width.jpg";
}

/**
 * hook emvideo_PROVIDER_video
 * this actually displays the full/normal-sized video we want, usually on the default page view
 *  @param $embed
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_bitsontherun_video($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_bitsontherun_flash', $item, $width, $height, $autoplay);
  return $output;
}

/**
 * hook emvideo_PROVIDER_video
 * this actually displays the preview-sized video we want, commonly for the teaser
 *  @param $embed
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_bitsontherun_preview($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_bitsontherun_flash', $item, $width, $height, $autoplay);
  return $output;
}

/**
 * Implementation of hook_emfield_subtheme.
 */
function emvideo_bitsontherun_emfield_subtheme() {
    $themes = array(
        'emvideo_bitsontherun_flash'  => array(
            'arguments' => array('item' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => NULL),
            'file' => 'providers/bitsontherun.inc',
            'path' => drupal_get_path('module', 'media_bitsontherun'),
        )
    );
    return $themes;
}
