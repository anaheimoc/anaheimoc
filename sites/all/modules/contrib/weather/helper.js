/* $Id: helper.js,v 1.20.2.4 2010/01/01 16:43:36 toddy Exp $
 *
 * Copyright © 2006-2010 Tobias Quathamer <t.quathamer@gmx.net>
 *
 * This file is part of the Drupal Weather module.
 *
 * Weather is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Weather is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Weather; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

Drupal.behaviors.weather_place_update = function() {
  // Update the ICAO and realname textfields after the place has changed
  $('#edit-place').change(function() {
    $('#edit-icao').val(this.options[this.selectedIndex].value);
    $('#edit-real-name').val(this.options[this.selectedIndex].text);
  });
}
