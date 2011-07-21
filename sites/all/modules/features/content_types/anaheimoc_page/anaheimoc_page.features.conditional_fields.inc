<?php

/**
 * Implementation of hook_conditional_fields_default_fields().
 */
function anaheimoc_page_conditional_fields_default_fields() {
$items = array();
$items[] = array (
  'control_field_name' => 'field_anaheimoc_page_hero_tax',
  'field_name' => 'field_anaheimoc_page_hero_weight',
  'type' => 'anaheimoc_page',
  'trigger_values' => 
  array (
    586 => '586',
  ),
);
$items[] = array (
  'control_field_name' => 'field_anaheimoc_page_hero_tax',
  'field_name' => 'field_anaheimoc_page_hero_image',
  'type' => 'anaheimoc_page',
  'trigger_values' => 
  array (
    586 => '586',
  ),
);
$items[] = array (
  'control_field_name' => 'field_page_editor_review',
  'field_name' => 'field_page_editor_notes',
  'type' => 'anaheimoc_page',
  'trigger_values' => 
  array (
    1 => '1',
  ),
);
return $items;
}
