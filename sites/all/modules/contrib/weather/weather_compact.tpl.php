<div class="weather">
  <p>
    <strong><?php print $weather['real_name']; ?>:</strong>
    <?php print $weather['condition'];
    if (isset($weather['temperature'])) {
      print ', ' . $weather['temperature'];
    }
    ?>
  </p>
</div>
