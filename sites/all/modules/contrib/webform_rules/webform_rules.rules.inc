<?php
// $Id: webform_rules.rules.inc,v 1.1.2.4 2010/12/18 10:50:12 stborchert Exp $

/**
 * @file
 * Functions for rules integration.
 */

/**
 * Implementation of hook_rules_event_info().
 * @ingroup rules
 */
function webform_rules_rules_event_info() {
  return array(
    'webform_rules_submit_as_draft' => array(
      'label' => t('After a webform has been saved as draft'),
      'module' => t('Webform'),
      'arguments' => _webform_rules_event_variables(),
    ),
    'webform_rules_submit' => array(
      'label' => t('After a webform has been submitted'),
      'module' => t('Webform'),
      'arguments' => _webform_rules_event_variables(),
    ),
  );
}

/**
 * Implementation of hook_condition_info().
 */
function webform_rules_rules_condition_info() {
  return array(
    'webform_rules_condition_webform_id' => array(
      'label' => t('Select a webform'),
      'arguments' => array(
        'form_id' => array('type' => 'value', 'label' => t('The form id of the submitted form')),
        'selected_webform' => array('label' => t('Webform'), 'type' => 'string'),
      ),
      'help' => t('This condition just compares two texts. It returns TRUE, if both texts are equal.'),
      'module' => 'Webform',
    ),
  );
}

/**
 * Implementation of hook_rules_data_type_info().
 */
function webform_rules_data_type_info() {
  return array(
    'webform_data' => array(
      'label' => t('webform data'),
      'class' => 'webform_rules_data_type_webform_data',
      'savable' => TRUE,
      'identifiable' => TRUE,
      'use_input_form' => FALSE,
      'module' => 'Webform',
      'token type' => 'webform',
    ),
  );
}

/**
 * Function to compare the form id of the submitted webform with the selected
 * form.
 */
function webform_rules_condition_webform_id($form_id, $selected_webform) {
  return $form_id == $selected_webform;
}

/**
 * Generates the condition form to select a webform.
 */
function webform_rules_condition_webform_id_form($settings, &$form) {
  $query = db_query("SELECT nid, title FROM node WHERE type = '%s'", 'webform');
  $options = array();
  while ($webform = db_fetch_array($query)) {
    $form_id = 'webform-client-form-'. $webform['nid'];
    $options[$form_id] = $webform['title'];
  }
  $form['settings']['selected_webform'] = array(
    '#type' => 'select',
    '#title' => t('Webform'),
    '#options' => $options,
    '#default_value' => isset($settings['selected_webform']) ? $settings['selected_webform'] : '',
    '#required' => TRUE,
  );
}

/**
 * Helper function for event variables.
 *
 * @return
 *   All available variables for the rules events provided by webform_rules.
 */
function _webform_rules_event_variables() {
  return array(
    'user' => array(
      'type' => 'user',
      'label' => t('User, who submitted the webform'),
    ),
    'node' => array(
      'type' => 'node',
      'label' => t('The webform node'),
    ),
    'data' => array(
      'type' => 'webform_data',
      'label' => t('The submitted webform data'),
      'save' => TRUE,
    ),
    'form_id' => array(
      'type' => 'string',
      'label' => t('The form id of the submitted form'),
      'hidden' => TRUE,
    ),
    'selected_webform' => array(
      'type' => 'string',
      'label' => t('The webform'),
      'hidden' => TRUE,
    ),
  );
}

/**
 * Defines the webform_data type
 */
class webform_rules_data_type_webform_data extends rules_data_type {

  function save() {
    $changed = FALSE;
    // Get eventually modified data.
    $submission = &$this->get();
    if (!$submission || !is_array($submission)) {
      // No data found.
      return FALSE;
    }
    $sid = $submission['sid'];
    // Load saved submission data.
    $saved_submission = $this->load($sid);
    if (count($saved_submission) != 1) {
      // No submission found with given id.
      return FALSE;
    }
    $new_submission = $saved_submission[$sid];
    $node = node_load($new_submission->nid);
    if (!$node) {
      // Webform could not be loaded.
      return FALSE;
    }
    // Replace saved submission data with modified values.
    foreach ($submission['components'] as $key => $value) {
      $cid = $value['component']['cid'];
      $new_val = is_array($value['value']) ? $value['value'] : array($value['value']);
      if ($new_val != $new_submission->data[$cid]['value']) {
        $changed = TRUE;
      }
      $new_submission->data[$cid]['value'] = $new_val;
    }
    // Update submission data if necessary.
    if ($changed) {
      // TODO: changed is always TRUE atm?
      webform_submission_update($node, $new_submission);
    }
    return TRUE;
  }

  function load($sid) {
    return webform_get_submissions(array('sid' => $sid));
  }

  function get_identifier() {
    $submission = &$this->get();
    return $submission->sid;
  }

}
