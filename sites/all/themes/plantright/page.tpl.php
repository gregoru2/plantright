<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
<link type="text/css" rel="stylesheet" href="http://plantright.org/inc/faq.css" />
  <?php print $scripts; ?>
  <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
</head>
<body id="homepage">
<div id="container">
	<div id="left">
		<div id="logo"> 
				<a href="http://plantright.org"><img alt="Plantrightlogo" src="<?php
global $base_url;
print $base_url;
?>/images/PlantRightLogo.gif" /></a> 
				</div> 
		<div id="leftnav"> 
			<ul> 
				<li><a href="http://plantright.org/definitions">What are invasive plants?</a> 
				<li><a href="http://plantright.org/plants">Regional invasive and alternative plants</a></li> 
				<li><a href="http://plantright.org/whattodo">What you can do</a></li> 
				<li><a href="http://plantright.org/benefits">Benefits of Planting Right</a></li> 
				<li><a href="http://plantright.org/questions">FAQ</a></li> 
				<li><a href="http://plantright.org/testimonials">Testimonials</a></li> 
				<li><a href="http://plantright.org/watergardens">Water gardens</a></li> 
				<li><a href="http://plantright.org/research">Research</a></li> 
				<li><a href="http://plantright.org/library">Library</a></li> 
				<li><a href="http://plantright.org/news">News</a></li> 
				<li><a href="http://plantright.org/about">About us</a></li> 
				<li><a href="http://springsurvey.plantright.org">Spring Nursery Survey</a></li>
			</ul> 
			
			
		
 
			<div id="spreadTheWordButton"> 
			<a href="http://plantright.org/materials/"><img src="<?php
global $base_url;
print $base_url;
?>/images/spreadTheWord.gif" /></a> 
			</div> 
		</div>
	</div> 
		<div id="right"> 
			<div id="pullquote"><img src="<?php
global $base_url;
print $base_url;
?>/images/butterfly_banner.jpg" height="187" width="622" alt="PlantRight spring nursery survey" /></div> 
			<div id="content">
				<div class="breadcrumbs"><?php print $breadcrumb; ?></div> 
					<div id="sidebar">	
						<h3 class="bold">Spring Survey Links</h3>
				<?php
  					global $user;
// Check to see if $user has the ________ role.
  if (in_array('member', array_values($user->roles))) {
    print theme('links', $secondary_links, array('class' => 'links survey-nav'));}
  elseif (in_array('anonymous user', array_values($user->roles))) {
					  // Not logged in
    print theme('links', $primary_links, array('class' => 'links survey-nav'));}
  else {
	echo '<ul class="survey-nav"><li><a href="plantright-spring-nursery-survey-quiz">Quiz</a></li>';
	echo '<li><a href="webinar">Webinar</a></li>';
	echo '<li><a href="logout">Log Out</a></li>';
	}
				 ?>
					</div>
				<?php print $content ?>
			</div><!--end content--> 
		</div><!--end right--> 
	<div id="footer"> 
	
	<p id="copyright">&copy; Copyright 2007-2010 California Horticultural Invasives Prevention (Cal-HIP)<br /> 
 
Design &amp; code by <a href="http://www.filadesign.com/" target="_new">Fila Design</a> <br /><br /> 
Spring survey application built by <a href="http://ignoredbydinosaurs.com">iBD</a> 
 
	</p> 
 
	<p id="address"> 
 
PlantRight Project Manager<br />c/o Sustainable Conservation<br /> 
98 Battery Street Suite 302, San Francisco CA 94111<br /> 
ph: 415.977.0380  ext. 312
 
</p> 
 
		<div id="clear2">&nbsp;</div> 
 
</div> 
 
	
<!-- Google Analytics code -->	
	
<script type="text/javascript">  
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E")); 
</script> 
 
<script type="text/javascript"> 
try {
var pageTracker = _gat._getTracker("UA-6235735-1");
pageTracker._trackPageview(); 
} catch(err) {}</script> 
</body> 
</html> 
	