<?php
/* $Id: weather_parser.inc,v 1.21.2.10 2010/02/06 07:38:55 toddy Exp $
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



/**
 * Parses a raw METAR data string
 */
function weather_parse_metar($metar_raw_string) {
  // Some stations insert a space between the cloud conditions
  // and the altitude, e.g. "FEW 025" instead of "FEW025".
  // Therefore, we scan for such occurences and remove the space.
  $metar_raw_string = preg_replace("/(FEW|SCT|BKN|OVC)\s+([0-9]{3})/",
    '$1$2', $metar_raw_string);

  // Setup the metar data array
  $metar = array();
  $metar['#raw'] = $metar_raw_string;
  // Split string for parsing routines
  $raw_items = preg_split('/\s+/', strtoupper($metar_raw_string));

  // Run the data through the METAR routines
  foreach ($raw_items as $metar_raw) {
    if (_weather_parse_stop($metar_raw, $metar)) break;
    _weather_parse_icao($metar_raw, $metar);
    _weather_parse_timestamp($metar_raw, $metar);
    _weather_parse_reporttype($metar_raw, $metar);
    _weather_parse_wind($metar_raw, $metar);
    _weather_parse_visibility($metar_raw, $metar);
    _weather_parse_condition($metar_raw, $metar);
    _weather_parse_phenomena($metar_raw, $metar);
    _weather_parse_temperature($metar_raw, $metar);
    _weather_parse_pressure($metar_raw, $metar);
  }

  // Calculate sunrise and sunset times
  _weather_calculate_sunrise_sunset($metar);

  return $metar;
}




/**
 * Decide whether to stop parsing
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 * @return boolean
 */
function _weather_parse_stop($metar_raw, &$metar) {
  if (preg_match('/^(BECMG|TEMPO|NOSIG|RMK)$/', $metar_raw)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}



/**
 * Extract the ICAO code
 *
 * ICAO = International Civil Aviation Organization, this is a four
 * letter airport code, e. g. EDDH
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_icao($metar_raw, &$metar) {
  if (preg_match('/^([A-Z]{4}|K[A-Z0-9]{3})$/', $metar_raw) and !isset($metar['icao'])) {
    $metar['icao'] = $metar_raw;
  }
}



/**
 * Extract the timestamp
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_timestamp($metar_raw, &$metar) {
  if (preg_match('/^([0-9]{2})([0-9]{2})([0-9]{2})Z$/', $metar_raw, $matches)) {
    $timestamp['year'] = gmdate('Y');
    $timestamp['month'] = gmdate('n');
    $timestamp['day'] = $matches[1];
    $timestamp['hour'] = $matches[2];
    $timestamp['minute'] = $matches[3];
    // if the current day is lower than the one from the METAR data,
    // it must be a day from last month
    // Note: in case even the year wraps (month = 0 -> month = 12, year--),
    // the gmmktime() function further down will take care of this.
    if (gmdate('d') < $timestamp['day']) {
      $timestamp['month']--;
    }

    $metar['reported_on'] = gmmktime($timestamp['hour'],
      $timestamp['minute'],
      0, // these are the seconds
      $timestamp['month'],
      $timestamp['day'],
      $timestamp['year']);
  }
}



/**
 * Extract the report type
 *
 * This may be missing in the METAR data. If present, it should be
 * either AUTO or COR.
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_reporttype($metar_raw, &$metar) {
  if (preg_match('/^(AUTO|COR)$/', $metar_raw)) {
    $metar['reporttype'] = $metar_raw;
  }
}



/**
 * Extract the wind information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_wind($metar_raw, &$metar) {
  if (preg_match('/^'.
    '([0-9]{3}|VRB)'.    // Wind direction from true north or VRB for variable
    '([0-9]{2,3})'.      // Wind speed, two or three numbers
    '(G([0-9]{2,3}))?'.  // Gusts, two or three digits (optional)
    '(KT|MPS|KMH)'.      // Measurement unit (knots, meter/s, or km/h)
    '$/', $metar_raw, $matches)) {
    $metar['wind']['direction'] = (int) $matches[1];
    $wind_speed = (int) $matches[2];
    $wind_gusts = (int) $matches[4];
    $wind_unit = $matches[5];

    // Do a conversion to other formats
    switch ($wind_unit) {
      case 'KT':
        // Convert from knots to km/h, mph, and mps
        // nautical mile = 1852 meters
        // statue mile = 1609.344 meters
        $metar['wind']['speed_knots'] = $wind_speed;
        $metar['wind']['gusts_knots'] = $wind_gusts;
        $metar['wind']['speed_kmh'] = round($wind_speed * 1.852, 1);
        $metar['wind']['gusts_kmh'] = round($wind_gusts * 1.852, 1);
        $metar['wind']['speed_mph'] = round($wind_speed * 1.151, 1);
        $metar['wind']['gusts_mph'] = round($wind_gusts * 1.151, 1);
        $metar['wind']['speed_mps'] = round($wind_speed * 0.514, 1);
        $metar['wind']['gusts_mps'] = round($wind_gusts * 0.514, 1);
        break;
      case 'MPS':
        // Convert from meter/s to knots, km/h and mph
        // nautical mile = 1852 meters
        // statue mile = 1609.344 meters
        $metar['wind']['speed_knots'] = round($wind_speed * 1.944, 1);
        $metar['wind']['gusts_knots'] = round($wind_gusts * 1.944, 1);
        $metar['wind']['speed_kmh'] = round($wind_speed * 3.6, 1);
        $metar['wind']['gusts_kmh'] = round($wind_gusts * 3.6, 1);
        $metar['wind']['speed_mph'] = round($wind_speed * 2.237, 1);
        $metar['wind']['gusts_mph'] = round($wind_gusts * 2.237, 1);
        $metar['wind']['speed_mps'] = $wind_speed;
        $metar['wind']['gusts_mps'] = $wind_gusts;
        break;
      case 'KMH':
        // Convert from km/h to knots, mph, and mps
        // nautical mile = 1852 meters
        // statue mile = 1609.344 meters
        $metar['wind']['speed_knots'] = round($wind_speed * 0.540, 1);
        $metar['wind']['gusts_knots'] = round($wind_gusts * 0.540, 1);
        $metar['wind']['speed_kmh'] = $wind_speed;
        $metar['wind']['gusts_kmh'] = $wind_gusts;
        $metar['wind']['speed_mph'] = round($wind_speed * 0.621, 1);
        $metar['wind']['gusts_mph'] = round($wind_gusts * 0.621, 1);
        $metar['wind']['speed_mps'] = round($wind_speed * 0.278, 1);
        $metar['wind']['gusts_mps'] = round($wind_gusts * 0.278, 1);
        break;
    }
    $metar['wind']['speed_beaufort'] = _weather_calculate_beaufort($metar['wind']['speed_kmh']);
    $metar['wind']['gusts_beaufort'] = _weather_calculate_beaufort($metar['wind']['gusts_kmh']);
  }
  else if (preg_match('/^'.
    '([0-9]{3})'.        // Variable wind direction, start
    'V'.                 // Marker for "V"ariable
    '([0-9]{3})'.        // Variable wind direction, end
    '$/', $metar_raw, $matches)) {
    $metar['wind']['variable_start'] = (int) $matches[1];
    $metar['wind']['variable_end'] = (int) $matches[2];
  }
}



/**
 * Extract the visibility information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_visibility($metar_raw, &$metar) {
  if (preg_match('/^([0-9])$/', $metar_raw, $matches)) {
    // Special case: A single digit, e.g. in 1 1/2SM
    $metar['visibility']['#visibility_miles'] = $matches[1];
  }
  else if (preg_match('/^'.
    '(M?)([0-9])(\/?)([0-9]*)'.
    'SM'.
    '$/', $metar_raw, $matches)) {
    if ($matches[3] == '/') {
      // This is a fractional visibility, we need to convert this
      $visibility = $metar['visibility']['#visibility_miles'] + $matches[2] / $matches[4];
    }
    else {
      $visibility = $matches[2] . $matches[4];
    }
    $metar['visibility']['miles'] = $visibility;
    $metar['visibility']['kilometers'] = round($visibility * 1.609344, 1);
  }
  else if (preg_match('/^([0-9]{4})(NDV)?$/', $metar_raw, $matches)) {
    // NDV means "no directional variation", used by automatic stations
    $metar['visibility']['kilometers'] = round($matches[1] / 1000, 1);
    $metar['visibility']['miles'] = round($metar['visibility']['kilometers'] / 1.609344, 1);
  }
}



/**
 * Extract the phenomena information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_phenomena($metar_raw, &$metar) {
  if (preg_match('/^'.
    '(-|\+|VC)?'.     // Intensity or Proximity
    '(SH|TS|FZ)?'.    // Descriptor
    'RA'.             // Rain
    '$/', $metar_raw, $matches)) {
    $phen = array();
    if (isset($matches[1])) {
      switch ($matches[1]) {
        case '-': $phen['#light'] = TRUE; break;
        case '+': $phen['#heavy'] = TRUE; break;
        default: $phen['#moderate'] = TRUE;
      }
    }
    if (isset($matches[2])) {
      switch ($matches[2]) {
        case 'SH': $phen['#showers'] = TRUE; break;
        case 'FZ': $phen['#freezing'] = TRUE; break;
      }
    }
    $metar['phenomena']['rain'] = $phen;
  }
  else if (preg_match('/^'.
    '(-|\+|VC)?'.     // Intensity or Proximity
    '(FZ)?'.          // Descriptor
    'DZ'.             // Drizzle
    '$/', $metar_raw, $matches)) {
    $phen = array();
    if (isset($matches[1])) {
      switch ($matches[1]) {
        case '-': $phen['#light'] = TRUE; break;
        case '+': $phen['#heavy'] = TRUE; break;
        default: $phen['#moderate'] = TRUE;
      }
    }
    if (isset($matches[2])) {
      switch ($matches[2]) {
        case 'FZ': $phen['#freezing'] = TRUE; break;
      }
    }
    $metar['phenomena']['drizzle'] = $phen;
  }
  else if (preg_match('/^'.
    '(-|\+|VC)?'.     // Intensity or Proximity
    '(BL|DR|SH)?'.    // Descriptor
    'SN'.             // Snow
    '$/', $metar_raw, $matches)) {
    $phen = array();
    if (isset($matches[1])) {
      switch ($matches[1]) {
        case '-': $phen['#light'] = TRUE; break;
        case '+': $phen['#heavy'] = TRUE; break;
        default: $phen['#moderate'] = TRUE;
      }
    }
    if (isset($matches[2])) {
      switch ($matches[2]) {
        case 'BL': $phen['#blowing'] = TRUE; break;
        case 'DR': $phen['#low_drifting'] = TRUE; break;
        case 'SH': $phen['#showers'] = TRUE; break;
      }
    }
    $metar['phenomena']['snow'] = $phen;
  }
  else if (preg_match('/^'.
    'BR'.             // Mist
    '$/', $metar_raw, $matches)) {
    $metar['phenomena']['#mist'] = TRUE;
  }
  else if (preg_match('/^'.
    '(VC|MI|PR|BC)?'. // Proximity (VC) or Descriptor
    'FG'.             // Fog
    '$/', $metar_raw, $matches)) {
    $phen = array();
    if (isset($matches[1])) {
      switch ($matches[1]) {
        case 'MI': $phen['#shallow'] = TRUE; break;
        case 'PR': $phen['#partial'] = TRUE; break;
        case 'BC': $phen['#patches'] = TRUE; break;
      }
    }
    $metar['phenomena']['fog'] = $phen;
  }
  else if (preg_match('/^'.
    'FU'.             // Smoke
    '$/', $metar_raw, $matches)) {
    $metar['phenomena']['#smoke'] = TRUE;
  }
}



/**
 * Extract the condition information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_condition($metar_raw, &$metar) {
  $ordering = array(
    1 => array('CLR' => 'clear'),
    2 => array('FEW' => 'few'),
    3 => array('SCT' => 'scattered'),
    4 => array('BKN' => 'broken'),
    5 => array('OVC' => 'overcast')
  );
  $metar['condition_order'] = -1;
  if (preg_match('/^'.
    '(FEW|SCT|BKN|OVC)([0-9]{3})'.
    '(CB|TCU)?(\/\/\/)?'.
    '$/', $metar_raw, $matches)) {
    foreach ($ordering as $order => $data) {
      if (key($data) == $matches[1]) {
        $metar['#condition_text'][] = $data[key($data)];
        $metar['#condition_order'][] = $order;
        break;
      }
    }
  }
  else if (preg_match('/^'.
    '(CLR|SKC|CAVOK)'.
    '$/', $metar_raw, $matches)) {
    $metar['#condition_text'][] = 'clear';
    $metar['#condition_order'][] = 1;
    if ($matches[1] == 'CAVOK') {
      $metar['visibility']['kilometers'] = 10;
      $metar['visibility']['miles'] = round($metar['visibility']['kilometers'] / 1.609344, 1);
    }
  }
  else if (preg_match('/^'.
    '(NSC|NCD)'.
    '$/', $metar_raw, $matches)) {
    // NSC means no significant clouds,
    // NCD is from automatic stations, no cloud detected
    $metar['#condition_text'][] = 'no-significant-clouds';
    $metar['#condition_order'][] = 1;
  }
  else if (preg_match('/^'.
    'VV[0-9\/]{3}'.
    '$/', $metar_raw, $matches)) {
    // VV is the vertical visibility, this should be shown as overcast.
    // If no information is available, VV/// will be used.
    $metar['#condition_text'][] = 'overcast';
    $metar['#condition_order'][] = 5;
  }
  if (isset($metar['#condition_order'])) {
    foreach ($metar['#condition_order'] as $index => $order) {
      if ($order > $metar['condition_order']) {
        $metar['condition_order'] = $order;
        $metar['condition_text'] = $metar['#condition_text'][$index];
      }
    }
  }
}



/**
 * Extract the temperature information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_temperature($metar_raw, &$metar) {
  if (preg_match('/^'.
    '(M?[0-9]{2})'.      // Temperature (M indicates negative temperatures)
    '\/'.                // Slash is the separator
    '(M?[0-9]{2}|XX)?'.  // Optional: Dew point temperature, may be 'XX'
    '$/', $metar_raw, $matches)) {
    $metar['temperature']['celsius'] = (int) strtr($matches[1], 'M', '-');
    $metar['temperature']['fahrenheit'] =
      round($metar['temperature']['celsius'] * 9/5 + 32, 1);
    if (isset($matches[2]) and $matches[2] != 'XX') {
      $metar['dewpoint']['celsius'] = (int) strtr($matches[2], 'M', '-');
      $metar['dewpoint']['fahrenheit'] =
        round($metar['dewpoint']['celsius'] * 9/5 + 32, 1);
    }
  }
}



/**
 * Extract the pressure information
 *
 * @param string Raw METAR data to parse
 * @param array Parsed METAR data, will be altered
 */
function _weather_parse_pressure($metar_raw, &$metar) {
  if (preg_match('/^'.
    '(A|Q)([0-9]{4})'.      // Pressure, either inHg (A) or hPa (Q)
    '$/', $metar_raw, $matches)) {
    if ($matches[1] == 'A') {
      // Pressure is given in inch Hg
      $metar['pressure']['inHg'] = $matches[2] / 100;
      $metar['pressure']['mmHg'] = round($metar['pressure']['inHg'] * 25.4, 0);
      $metar['pressure']['hPa'] = round($metar['pressure']['inHg'] * 33.8639, 0);
      $metar['pressure']['kPa'] = round($metar['pressure']['inHg'] * 3.38639, 1);
    }
    else {
      // Pressure is given in HektoPascal, hPa
      $metar['pressure']['hPa'] = (int) $matches[2];
      $metar['pressure']['inHg'] = round($metar['pressure']['hPa'] * 0.02953, 2);
      $metar['pressure']['mmHg'] = round($metar['pressure']['inHg'] * 25.4, 0);
      $metar['pressure']['kPa'] = round($metar['pressure']['inHg'] * 3.38639, 1);
    }
  }
}



/**
 * Calculate the times of sunrise and sunset
 *
 * The times are GMT, so it's possible for the sunrise being
 * at 16:48 while the sun sets at 7:06.
 *
 * @param array Parsed METAR data, will be altered
 */
function _weather_calculate_sunrise_sunset(&$metar) {
  $info = weather_get_latitude_longitude($metar['icao']);

  // Use gmdate() so times are appropriate for gmmktime() used to
  // create new sunrise/sunset times below.
  $day_of_year = gmdate('z', $metar['reported_on']);
  $year = gmdate('Y', $metar['reported_on']);
  $month = gmdate('m', $metar['reported_on']);
  $day = gmdate('d', $metar['reported_on']);

  // setup pi constants: 0.5*pi, 1.0*pi, 1.5*pi, 2.0*pi
  $pi_05 = 1.570796;
  $pi_10 = 3.141593;
  $pi_15 = 4.712389;
  $pi_20 = 6.283185;

  // convert latitude and longitude degree into radian
  // x rad = y° * pi / 180 = 0.017453 * y°
  $latitude = 0.017453 * $info['latitude'];
  $longitude = 0.017453 * $info['longitude'];

  // we want always GMT time, so set to 0. Otherwise,
  // the timezone can be calculated as follows:
  // $timezone = 0.261799 * offset;
  $timezone = 0;

  // the sunrise/sunset altitude in radian (-0.833°)
  $altitude = -0.014539;

  $sunrise = 0;
  $sunset = 0;
  foreach (array('sunrise' => $pi_05, 'sunset' => $pi_15) as $type => $factor) {
    $a = $day_of_year + ($factor - $longitude) / $pi_20;
    // solar mean anomaly
    $sma = $a * 0.017202 - 0.0574039;
    // solar true longitude
    $stl = $sma + 0.0334405 * sin($sma);
    $stl += 4.93289 + 3.49066E-04 * sin(2 * $sma);

    // normalize the longitude to be between >= 0 and < 2.0*pi
    while ($stl < 0) {
      $stl += $pi_20;
    }
    while ($stl >= $pi_20) {
      $stl -= $pi_20;
    }

    if ($stl / $pi_05 - intval($stl / $pi_05) == 0) {
      $stl += 4.84814E-06;
    }

    // solar right ascension
    $sra = sin($stl) / cos($stl);
    $sra = atan2(0.91746 * $sra, 1);

    // adjust quadrant
    if ($stl > $pi_15) {
      $sra += $pi_20;
    }
    else if ($stl > $pi_05) {
      $sra += $pi_10;
    }

    // solar declination
    $sd = 0.39782 * sin($stl);
    $sd = $sd / sqrt(1 - $sd * $sd);
    $sd = atan2($sd, 1);

    $diurnal_arc = ($altitude - sin($sd) * sin($latitude)) / (cos($sd) * cos($latitude));

    // is there a sunrise or sunset at all?
    if ($diurnal_arc >= 1) {
      // no sunrise
      $no_sunrise = TRUE;
      break;
    }
    if ($diurnal_arc <= -1) {
      // no sunset
      $no_sunset = TRUE;
      break;
    }

    $diurnal_arc = $diurnal_arc / sqrt(1 - $diurnal_arc * $diurnal_arc);
    $diurnal_arc = $pi_05 - atan2($diurnal_arc, 1);

    if ($type == 'sunrise') {
      $diurnal_arc = $pi_20 - $diurnal_arc;
    }

    // calculate the time
    $localtime = $diurnal_arc + $sra - 0.0172028 * $a - 1.73364;
    // wall clock time
    $wallclock = $localtime - $longitude + $timezone;

    // normalize wallclock to be between >= 0 and < 2.0*pi
    while ($wallclock < 0) {
      $wallclock += $pi_20;
    }
    while ($wallclock >= $pi_20) {
      $wallclock -= $pi_20;
    }
    $wallclock = $wallclock * 3.81972;

    $hour = intval($wallclock);
    $minute = round(($wallclock - $hour) * 60, 0);

    if ($type == 'sunrise') {
      $sunrise = gmmktime($hour, $minute, 0, $month, $day, $year);
    }
    else {
      $sunset = gmmktime($hour, $minute, 0, $month, $day, $year);
    }
  }

  // handle special cases like no sunrise / sunset at all
  if (isset($no_sunset)) {
    $condition = 'day';
  }
  else if (isset($no_sunrise)) {
    $condition = 'night';
  }
  else {
    // correctly handle northern and southern hemisphere
    if ($sunrise <= $sunset) {
      // this should be on the northern hemisphere
      if ($metar['reported_on'] >= $sunrise and $metar['reported_on'] < $sunset) {
        $condition = 'day';
      }
      else {
        $condition = 'night';
      }
    }
    else {
      // this should be on the southern hemisphere
      if ($metar['reported_on'] >= $sunrise or $metar['reported_on'] <= $sunset) {
        $condition = 'day';
      }
      else {
        $condition = 'night';
      }
    }
  }

  $metar['daytime']['sunrise_on'] = $sunrise;
  $metar['daytime']['sunset_on'] = $sunset;
  if (isset($no_sunrise)) {
    $metar['daytime']['no_sunrise'] = TRUE;
  }
  else {
    $metar['daytime']['no_sunrise'] = FALSE;
  }
  if (isset($no_sunset)) {
    $metar['daytime']['no_sunset'] = TRUE;
  }
  else {
    $metar['daytime']['no_sunset'] = FALSE;
  }
  $metar['daytime']['condition'] = $condition;
}



/**
 * Calculate Beaufort wind scale for given wind speed
 *
 * @link http://en.wikipedia.org/wiki/Beaufort_scale
 *
 * @param float Wind speed in km/h
 * @return Beaufort number
 */
function _weather_calculate_beaufort($wind_speed) {
  if ($wind_speed >= 120) return 12;
  if ($wind_speed >= 103) return 11;
  if ($wind_speed >= 88) return 10;
  if ($wind_speed >= 76) return 9;
  if ($wind_speed >= 63) return 8;
  if ($wind_speed >= 51) return 7;
  if ($wind_speed >= 40) return 6;
  if ($wind_speed >= 30) return 5;
  if ($wind_speed >= 20) return 4;
  if ($wind_speed >= 12) return 3;
  if ($wind_speed >= 7) return 2;
  if ($wind_speed >= 1) return 1;
  return 0;
}
