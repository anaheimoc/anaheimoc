<div class="weather">
  <!-- <p><strong><?php print $weather['real_name']; ?></strong></p> -->
  <div class="weather-temp">
  	<a href="/node/22190"><?php print t("!temperature",
         	 array('!temperature' => $weather['temperature'])); ?></a>
  </div>
  <div class="weather-img">
  	<a href="/node/22190"><img src="<?php print $weather['image']['filename']; ?>" height="60" width="60" alt="<?php print $weather['condition']; ?>" title="<?php print $weather['condition']; ?>" /></a>
  </div>
  <!-- <div class="weather-sponsor">
  	<span><a href="/node/22190">Sponsored by: </a></span>
  		<a href="/node/22190"><img src="http://anaheimoc.dev/sites/all/modules/contrib/weather/images/day-overcast.png" title="Sponsored by:" /></a><br />
  	</div> -->
 
</div>
