<div class="weather">
  <!-- <p><strong><?php print $weather['real_name']; ?></strong></p> -->
  <div class="weather-temp">
  <?php print t("!temperature",
          array('!temperature' => $weather['temperature'])); ?><br /><a href="/node/22190">
  <span class="weather-sponsor">Sponsored by:</span>
  <img src="http://anaheimoc.dev/sites/all/modules/contrib/weather/images/day-overcast.png" title="Sponsored by:" />
  </a>
  </div>
  <div class="weather-img">
  <a href="/node/22190">
    <img src="<?php print $weather['image']['filename']; ?>" height="60" width="60" alt="<?php print $weather['condition']; ?>" title="<?php print $weather['condition']; ?>" /></a>
  </div>
</div>
