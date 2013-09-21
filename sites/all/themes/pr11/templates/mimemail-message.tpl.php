<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[mailkey].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $subject: The message subject.
 * - $body: The message body in HTML format.
 * - $mailkey: The message identifier.
 * - $recipient: An email address or user object who is receiving the message.
 * - $css: Internal style sheets.
 *
 * @see template_preprocess_mimemail_message()
 */
$path = $GLOBALS['base_url'] . '/images';
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <?php if ($css): ?>
    <style type="text/css">
      <!--
      <?php print $css ?>
      -->
    </style>
    <?php endif; ?>
  </head>
  <body id="mimemail-body" <?php if ($mailkey): print 'class="'. $mailkey .'"'; endif; ?> style="margin: 10px auto; text-align: center;">
<table align="center" border="0" cellpadding="0" cellspacing="0" style="border: 0px; border-collapse: collapse; width: 740px; font-size: 15px; line-height: 21px;">
<tr><td align="center" style="padding: 10px;"><img src="<?php print $path; ?>/plantright_partner_logo.png" height="123" width="96" alt="PlantRight Partner logo"></td></tr></table>
<table align="center" cellpadding="0" cellspacing="0" style="border-top: 7px solid #bcd030; border-left: 2px solid #bcd030; border-right: 2px solid #bcd030; border-bottom: 12px solid #6a5834; border-collapse: collapse; width: 740px; font-size: 15px; line-height: 21px;">
<tr><td style="text-align: left; padding: 30px 53px; font-family: Helvetica, Arial, sans-serif; font-size: 15px; line-height: 21px; color: #707070;">
<?php print $body; ?>
</td></tr>
<tr style="margin: 0px; padding: 0px;"><td style="text-align: center; padding: 0px; margin: 0px; background-color: #bcd030;"><img src="<?php print $path; ?>/plantright_email_footer.png" height="95" width="736px" alt="For more information visit www.plantright.org" style=" padding: 0px; margin: 0px;" /></td></tr>

</table>
</body>
</html>
