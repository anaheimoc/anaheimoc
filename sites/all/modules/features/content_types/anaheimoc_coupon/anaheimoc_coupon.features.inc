<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function anaheimoc_coupon_imagecache_default_presets() {
  $items = array(
    'coupon_partner_logo' => array(
      'presetname' => 'coupon_partner_logo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '136',
            'height' => '70',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function anaheimoc_coupon_views_api() {
  return array(
    'api' => '2',
  );
}
