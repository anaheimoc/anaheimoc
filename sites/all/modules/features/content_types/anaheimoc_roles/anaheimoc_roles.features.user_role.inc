<?php

/**
 * Implementation of hook_user_default_roles().
 */
function anaheimoc_roles_user_default_roles() {
  $roles = array();

  // Exported role: Blog staff
  $roles['Blog staff'] = array(
    'name' => 'Blog staff',
  );

  // Exported role: Hotel Partner
  $roles['Hotel Partner'] = array(
    'name' => 'Hotel Partner',
  );

  // Exported role: Meetings staff
  $roles['Meetings staff'] = array(
    'name' => 'Meetings staff',
  );

  // Exported role: Microsite staff
  $roles['Microsite staff'] = array(
    'name' => 'Microsite staff',
  );

  // Exported role: Partnership staff
  $roles['Partnership staff'] = array(
    'name' => 'Partnership staff',
  );

  // Exported role: Press staff
  $roles['Press staff'] = array(
    'name' => 'Press staff',
  );

  // Exported role: Staff
  $roles['Staff'] = array(
    'name' => 'Staff',
  );

  // Exported role: Staff - Advanced
  $roles['Staff - Advanced'] = array(
    'name' => 'Staff - Advanced',
  );

  // Exported role: Staff Manager
  $roles['Staff Manager'] = array(
    'name' => 'Staff Manager',
  );

  // Exported role: Staff VP
  $roles['Staff VP'] = array(
    'name' => 'Staff VP',
  );

  // Exported role: Travel Trade staff
  $roles['Travel Trade staff'] = array(
    'name' => 'Travel Trade staff',
  );

  // Exported role: Visitors staff
  $roles['Visitors staff'] = array(
    'name' => 'Visitors staff',
  );

  // Exported role: admin
  $roles['admin'] = array(
    'name' => 'admin',
  );

  // Exported role: image library user
  $roles['image library user'] = array(
    'name' => 'image library user',
  );

  return $roles;
}
