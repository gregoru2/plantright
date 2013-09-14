<?php
/*
 * account: user account object
 * name : the username
 * img
 * page_width
 * page_height
 * directory
 * path
 */
?>

<div id="pdf-agreement">
  <div id="page-1">
    <div id="agreement-text-1" class="text">
      <?php print $name; ?>
    </div>
    <div id="agreement-text-2" class="text">
      <?php print $name; ?>
    </div>
    <div id="agreement-image-1"><img src="<?php print $directory . '/' . $path; ?>/agreement-pdf-1.jpg" width="809px" height="1044px" /></div>
  </div>
  <div id="page-2">
    <div id="agreement-text-3" class="text">
      <div class="date subtext"><?php print $date; ?></div>
      <div class="name subtext"><?php print $name; ?></div>
      <div class="address subtext"><?php print $address; ?></div>
      <div class="city subtext"><?php print $city; ?></div>
      <div class="zip subtext"><?php print $zip; ?></div>
      <!-- <div class="phone subtext"><?php print $phone; ?></div> -->
      <!-- <div class="email subtext"><?php print $email; ?></div> -->
      <div class="date-2 subtext"><?php print $date; ?></div>
    </div>
    <div id="agreement-image-2"><img src="<?php print $directory . '/' . $path; ?>/agreement-pdf-2.jpg" width="801px" height="1034px" /></div>
  </div>
</div>