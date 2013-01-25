<?php
/*
 * account: user account object
 * quiz: quiz object
 * title : the quiz title
 * name : the username
 * download_url : url to pdf
 * download_link : full link to pdf
 */

?>
<div id="quiz-certificate-download"><?php print $download_link; ?></div>
<div id="quiz-certificate">
  <div class="certificate-text">This certifies that</div>
  <div class="certificate-name"><?php print $name; ?></div>
  <div class="certificate-text-2">completed</div>
  <div class="certificate-quiz"><?php print $title; ?></div>
  <div class="certificate-date"><?php print $date; ?></div>
</div>
