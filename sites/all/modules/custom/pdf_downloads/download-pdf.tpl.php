<?php
/*
 * download : content of download file
 * directory : directory to look for the files
 * css_file : CSS to render with
 * path : path to CSS file within directory
 */

?>

<html>
  <head>
    <?php if (isset($height) && $height): ?>
    <style type="text/css">
      body {
        height: <?php print $height; ?>;
        width: <?php print $page_width; ?>;
      }
    </style>
    <?php endif; ?>
    <link type="text/css" rel="stylesheet" media="all" href="<?php print $directory; ?>/<?php print $path; ?>/<?php print $css_file; ?>" />
    <link type="text/css" rel="stylesheet" media="all" href="<?php print $directory; ?>/download-pdf.css" />
  </head>
  <body>
    <div id="download">
      <?php print $download; ?>
    </div>
  </body>
</html>
