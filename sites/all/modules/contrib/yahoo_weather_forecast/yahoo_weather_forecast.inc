<?php
// $Id: yahoo_weather_forecast.inc,v 1.1.2.1 2009/10/08 11:48:04 pl2 Exp $

/**
 * @file
 * Yahoo API image file library.
 */

/**
 * yahoo_weather_forecast_img_associate
 *
 * @param mixed $code
 * @access public
 * @return void
 */
function yahoo_weather_forecast_img_associate($code) {
  $images = array(
    0 => array('file' => 'overcast-fog-heavy-rain.png', 'title' => t('Tornado')),
    1 => array('file' => 'overcast-heavy-rain.png', 'title' => t('Tropical storm')),
    2 => array('file' => 'overcast-fog-heavy-rain.png', 'title' => t('Hurricane')),
    3 => array('file' => 'overcast-heavy-rain.png', 'title' => t('Severe thunderstorms')),
    4 => array('file' => 'overcast-moderate-rain.png', 'title' => t('Thunderstorms')),
    5  => array('file' => 'overcast-light-snow.png', 'title' => t('Mixed rain ad snow')),
    6 => array('file' => 'overcast-light-rain.png', 'title' => t('Mixed rain ad sleet')),
    7 => array('file' => 'overcast-light-snow.png', 'title' => t('Mixed snow and sleet')),
    8 => array('file' => 'broken-light-rain.png', 'title' => t('Freezing drizzle')),
    9 => array('file' => 'broken-light-rain.png', 'title' => t('Drizzle')),
    10 => array('file' => 'clear-heavy-rain.png', 'title' => t('Freezing raing')),
    11 => array('file' => 'overcast-fog-light-rain.png', 'title' => t('Showers')),
    12 => array('file' => 'overcast-fog-light-rain.png', 'title' => t('Showers')),
    13 => array('file' => 'overcast-fog-heavy-snow.png', 'title' => t('Snow flurries')),
    14 => array('file' => 'few-heavy-snow.png', 'title' => t('Light snow showers')),
    15 => array('file' => 'scattered-light-snow.png', 'title' => t('Blowing snow')),
    16 => array('file' => 'overcast-heavy-snow.png', 'title' => t('Snow')),
    17 => array('file' => 'overcast-heavy-rain.png', 'title' => t('Hail')),
    18 => array('file' => 'overcast-light-rain.png', 'title' => t('Sleet')),
    19 => array('file' => 'clear-fog.png', 'title' => t('Dust')),
    20 => array('file' => 'overcast-fog.png', 'title' => t('Foggy')),
    21 => array('file' => 'overcast-fog.png', 'title' => t('Haze')),
    22 => array('file' => 'overcast-fog.png', 'title' => t('Smoky')),
    23 => array('file' => 'broken-fog-light-rain.png', 'title' => t('Blustery')),
    24 => array('file' => 'few.png', 'title' => t('Windy')),
    25 => array('file' => 'overcast.png', 'title' => t('Cold')),
    26 => array('file' => 'broken.png', 'title' => t('Cloudy')),
    27 => array('file' => 'night-overcast.png', 'title' => t('Mostly cloudy (night)')),
    28 => array('file' => 'day-overcast.png', 'title' => t('Mostly cloudy (day)')),
    29 => array('file' => 'night-few.png', 'title' => t('Partly cloudy (night)')),
    30 => array('file' => 'day-few.png', 'title' => t('Partly cloudy (day)')),
    31 => array('file' => 'night-clear.png', 'title' => t('Clear (night)')),
    32 => array('file' => 'day-clear.png', 'title' => t('Sunny')),
    33 => array('file' => 'night-clear.png', 'title' => t('Fair (night)')),
    34 => array('file' => 'day-clear.png', 'title' => t('Fair (day)')),
    35 => array('file' => 'overcast-moderate-rain.png', 'title' => t('Mixed rain and hail')),
    36 => array('file' => 'clear.png', 'title' => t('Hot')),
    37 => array('file' => 'clear-heavy-rain.png', 'title' => t('Isolated thunderstorms')),
    38 => array('file' => 'clear-light-rain.png', 'title' => t('Scattered thunderstorms')),
    39 => array('file' => 'clear-light-rain.png', 'title' => t('Scattered thunderstroms')),
    40 => array('file' => 'clear-moderate-rain.png', 'title' => t('Scattered showers')),
    41 => array('file' => 'overcast-heavy-snow.png', 'title' => t('Heavy snow')),
    42 => array('file' => 'clear-heavy-snow.png', 'title' => t('Scattered snow showers')),
    43 => array('file' => 'overcast-heavy-snow.png', 'title' => t('Heavy snow')),
    44 => array('file' => 'few.png', 'title' => t('Partly cloudy')),
    45 => array('file' => 'overcast-light-rain.png', 'title' => t('Thundershowers')),
    46 => array('file' => 'clear-light-snow.png', 'title' => t('Snow showers')),
    47 => array('file' => 'clear-moderate-rain.png', 'title' => t('Isolated thundershowers')),
    3200 => array('file' => 'nodata.png', 'title' => t('Not available')),

  );

  return $images[$code];
}

