<div class="location vcard">
  <div class="adr">
    <?php if (!empty($name)): ?>
      <span class="fn"><?php print $name; ?></span>
    <?php endif; ?>
    <?php if (!empty($street)): ?>
      <div class="street-address">
        <?php print $street; ?>
        <?php if (!empty($additional)): ?>
          <?php print ' ' . $additional; ?>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($city)): ?>
      <span class="locality"><?php print $city; ?></span><?php if (!empty($province)) print ', '; ?>
    <?php endif; ?>
    <?php if (!empty($province)): ?>
      <span class="region"><?php print $province_print; ?></span>
    <?php endif; ?>
    <?php if (!empty($postal_code)): ?>
      <span class="postal-code"><?php print $postal_code; ?></span>
    <?php endif; ?>
	<?php
		/** Removed country name */
	?>

    <?php if (!empty($fax)): ?>
      <div class="tel">
        <abbr class="type" title="fax"><?php print t("Fax"); ?>:</abbr>
        <span><?php print $fax; ?></span>
      </div>
    <?php endif; ?>

    <?php
		/** Removed latitude and longitude */
	?>
  </div>
  
  <?php if (!empty($phone)): ?>
  <div class="tel">
    <span class="value"><?php print $phone; ?></span>
  </div>
  <?php endif; ?>
  
  <?php if (!empty($map_link)): ?>
    <div class="map-link">
      <?php print $map_link; ?>
    </div>
  <?php endif; ?>
  
</div>
