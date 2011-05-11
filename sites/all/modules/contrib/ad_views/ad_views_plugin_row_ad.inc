<?php
// $Id: ad_views_plugin_row_ad.inc,v 1.1.2.7 2009/11/26 07:10:06 milesgillham Exp $
/*
 * Implementation of ad_views_row_plugin
 */

class ad_views_plugin_row_ad extends views_plugin_row {

  function options(&$options) {
//    $options['ad_display'] = 'default';
    // Using raw until issue #524454 is resolved.
    $options['ad_display'] = 'raw';
  }

  function options_form(&$form, &$form_state) {
    $form['ad_display'] = array(
      '#title' => t('Ad Display'),
      '#description' => t('Display method to use. If no items display then switch to a different type that is right for your environment. Using the JavaScript, jQuery, and IFrame display methods allows you to display random ads and track impressions even on cached pages. When using the Raw display method together with Drupal\'s page cache, impressions will be properly tracked but advertisements will only change when the page cache is updated. <strong>Note that there is a known problem (#524454) in using any other type but Raw with Firefox!</strong> Ensure that you have set the correct !perms.',array('!perms' => '<a href="/admin/user/permissions">Ad Permissions (show advertisements)</a>')),
      '#type' => 'radios',
      '#default_value' => $this->options['ad_display'],
      '#options' => array(
        'raw' => t('Raw'),
        'iframe' => t('Iframe'),
        'jquery' => t('JQuery'),
        'javascript' => t('Javascript'),
        'default' => t('Default (from !ads)', array('!ads' => '<a href="/admin/content/ad/configure">Ads Settings</a>'))
      )
    );
  }
}
