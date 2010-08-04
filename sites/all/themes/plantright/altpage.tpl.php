<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
</head>
<body>
<div id="wrapper">
	<div id="header">
 
	 <a href="<?php print $front_page; ?>"><img id="logo" src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
 
		<div id="header-wrap">
			<p class="newsletter"><a href="#" onclick="window.open('http://unitedpalaceconcerts.wufoo.com/forms/z7x4a9/',  null, 'height=485, width=680, toolbar=0, location=0, status=1, scrollbars=1,resizable=1'); return false" title="United Palace Concerts eNewsletter signup">Sign up for our <span class="yellow">E-Newsletter</span></a></p>
			<ul class="topnav">
			<?php print theme('links', $primary_links, array('class' => 'links primary-links')); ?>
			</ul>
		</div>
	</div><!--header-->
	<div id="content-wrapper">
	 <div id="banner">
	 <object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" 
codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,29,0" width="850" 
height="298"> 
<param name="movie" value="images/UPCbanner.swf"> 
<param name="quality" value="high"> 
<embed src="images/UPCbanner.swf" quality="high" 
pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash" width="850" 
height="298"></embed> 
</object> 
	 </div>
	 <div id="content-area">
	  <?php if (!empty($title)): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
      <?php if (!empty($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
      <?php if (!empty($messages)): print $messages; endif; ?>
      <?php if (!empty($help)): print $help; endif; ?>
      </div>
	 <div id="footer">
	 <ul class="bottom-nav">
	<?php print theme('links', $secondary_links, array('class' => 'links secondary-links')); ?>
	 </ul>
	 <p class="copyright">&copy; Copyright 2010 <strong>United Palace Concerts</strong>. All rights reserved.  All trademarks and names mentioned herein are the property of their respective owners.</p>
	 <p class="us"><a target="_blank" href="http://almondtreemarketing.com">Powered by <strong class="yellow">Almond Tree Marketing</strong></a></p>
	 </div>
	</div><!--content wrapper, stretched over footer to keep off-centered-->
</div><!--wrapper-->
<script type="text/javascript"> 
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script> 
<script type="text/javascript"> 
try {
var pageTracker = _gat._getTracker("UA-12578534-5");
pageTracker._trackPageview();
} catch(err) {}</script>
</body><!--Grubb was here-->
</html>
