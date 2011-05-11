<div class="weather">
  <!-- <p><strong><?php print $weather['real_name']; ?></strong></p> -->
  <div class="weather-temp">
  <span class="weather-sponsor"><a href="/node/22190">Sponsored by: </a></span>
  <img src="http://anaheimoc.dev/sites/all/modules/contrib/weather/images/day-overcast.png" title="Sponsored by:" /><br />
  <?php print t("!temperature",
          array('!temperature' => $weather['temperature'])); ?><br /><a href="/node/22190"><span class="forecast" style="font-size: 10px;">Forecast</span></a></div>
  <div class="weather-img">
    <img src="<?php print $weather['image']['filename']; ?>" height="60" width="60" alt="<?php print $weather['condition']; ?>" title="<?php print $weather['condition']; ?>" />
  </div>
</div>
