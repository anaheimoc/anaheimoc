<?php
// $Id: yahoo-weather-forecast-content.tpl.php,v 1.1.2.1 2009/12/01 16:42:25 pl2 Exp $

/**
 * @file
 * Yahoo weather content template.
 */
?>
<div class="yahoo-weather-current yahoo-weather-<?php print $daylight ?>-bg">
<?php if ($current_image) : ?>
<div class="weather-current">
  <?php print $current_image ?>
</div>
<?php endif; ?>
<?php if ($current) : ?>
  <p><strong><?php print t('Current conditions') ?>:</strong> <?php print $current ?></p>
<?php endif; ?>
<?php if (isset($temperature)) : ?>
  <p><strong><?php print t('Temperature') ?>:</strong> <?php print $temperature ?>° <?php print $temperature_units ?></p>
<?php endif; ?>
<?php if (isset($wind_speed)) : ?>
  <p><strong><?php print t('Wind') ?>:</strong> <?php print $wind_direction; ?> <?php print $wind_speed ?> <?php print $speed_units ?></p>
<?php endif; ?>
<?php if (isset($feels_like)) : ?>
  <p><strong><?php print t('Feels like') ?>:</strong> <?php print $feels_like ?>° <?php print $temperature_units ?></p>
<?php endif; ?>
<?php if (isset($humidity)) : ?>
  <p><strong><?php print t('Humidity') ?>:</strong> <?php print $humidity ?>%</p>
<?php endif; ?>
<?php if (isset($visibility)) : ?>
  <p><strong><?php print t('Visibility') ?>:</strong> <?php print $visibility ?> <?php print $distance_units ?></p>
<?php endif; ?>
<?php if (isset($pressure)): ?>
  <p><strong><?php print t('Pressure') ?>:</strong> <?php print $pressure ?> <?php print $pressure_units ?></p>
<?php endif; ?>
<?php if ($sunset): ?>
  <p><strong><?php print t('Sunrise') ?>:</strong> <?php print $sunrise ?></p>
  <p><strong><?php print t('Sunset') ?>:</strong> <?php print $sunset ?></p>
<?php endif; ?>
</div>

<?php if (!empty($forecasts)) : ?>
<div class="yahoo-weather-forecast">
<h2><?php print t('Forecasts') ?></h2>
<?php foreach ($forecasts as $key => $value) : ?>
<div class="forecast-item">
  <p><?php print $value['image'] ?></p>
  <p><strong><?php print $value['label'] ?></strong> <?php print $value['text'] ?></p>
  <p><strong><?php print t('Highest temperature') ?>:</strong> <?php print $value['high'] ?>° <?php print $temperature_units ?></p>
  <p><strong><?php print t('Lowest temperature') ?>:</strong> <?php print $value['low'] ?>° <?php print $temperature_units ?></p>
</div>
<?php endforeach; ?>
</div>
<?php endif; ?>
