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

<div id="pdf-pledge">
  <div id="pledge-image"><img src="<?php print $directory . '/' . $path . '/' . $img_file; ?>" width="<?php print $page_width; ?>" height="<?php print $page_height; ?>" /></div>
  <div id="pledge-text">
    <?php //image has to be inline not background to control DPI  ?>

    <div class="download-name"><?php print $name; ?></div>
    <div class="download-name-2"><?php print $name; ?></div>
    <div class="download-date"><?php print $date; ?></div>
  </div>
</div>