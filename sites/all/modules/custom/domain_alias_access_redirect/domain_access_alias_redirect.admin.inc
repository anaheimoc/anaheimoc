<?php

/**
 * Form to select the path generated for a particular site.
 */
function domain_access_alias_redirect_path_form($form_state) {
  $form = array();
  // Get list of domains.
  $domains = domain_domains();
  
  foreach ($domains as $domain_key => $domain) {
    $subdomain = ($domain['original_subdomain']) ? $domain['original_subdomain'] : $domain['subdomain'];
    $domain_paths = array($subdomain => $subdomain);
    foreach($domain['aliases'] as $domain_alias) {
      $domain_paths[$domain_alias['pattern']] = $domain_alias['pattern'];
    }
    $form['domain-access-alias-redirect-path-'. $domain['domain_id']] = array(
      '#type' => 'select',
      '#title' => t('Alias redirect for @subdomain', array('@subdomain' => $subdomain)),
      '#options' => $domain_paths,
      '#default_value' => variable_get('domain-access-alias-redirect-path-'. $domain['domain_id'], $subdomain),
    );
  }
  
  return system_settings_form($form);
}