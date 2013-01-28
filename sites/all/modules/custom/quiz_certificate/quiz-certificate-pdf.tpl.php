<?php
/*
 * certificate : content of certificate
 * any CSS can be customized here to the PDF
 */

?>

<html>
  <head>
    <link type="text/css" rel="stylesheet" media="all" href="<?php print $directory; ?>/quiz-certificate-pdf.css" />
  </head>
  <body>
<div id="quiz-certificate-image"><img src="<?php print $directory . '/' . $img; ?>" width="1054px" height="812px" /></div>
<?php //image has to be inline not background to control DPI ?>
<?php print $certificate; ?>
  </body>
</html>