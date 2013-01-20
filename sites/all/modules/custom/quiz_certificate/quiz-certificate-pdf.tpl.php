<?php
/*
 * certificate : content of certificate
 * any CSS can be customized here to the PDF
 */

?>

<html>
  <head>
    <style type="text/css">
      #quiz-certificate {
        background:#eee;
        height:945px;
        width:725px;
        text-align: center;
      }
      .certificate-text {
        margin-top:250px;
      }
      .certificate-name {
        font-size:2em;
        font-weight:bold;
        margin:1em auto;
      }
      .certificate-quiz {
        font-size:2em;
        font-weight:bold;
        margin:1em auto;
      }
      #quiz-certificate-download {
        display:none;
      }
    </style>
  </head>
  <body>
<?php print $certificate; ?>
  </body>
</html>