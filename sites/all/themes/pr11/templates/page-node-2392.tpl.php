<?php ?>
<head>
    <?php print $head ?>
    <?php print $styles ?>
    <title><?php print $head_title ?></title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
<link href='http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,600,700,800' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=PT+Sans+Narrow:400,700' rel='stylesheet' type='text/css'>
<?php if ($is_front):?><link rel="stylesheet" href="/sites/default/files/agile_carousel/agile_carousel.css"><?php endif; ?>
<!--[if lte IE 7]>
    <style type="text/css" media="all">@import "<?php print base_path() . path_to_theme() ?>/lte_ie7.css";</style>
  <![endif]-->
<script type="text/javascript">

  var _gaq = _gaq || [];
    _gaq.push(['_setAccount', 'UA-23178332-1']);
    _gaq.push(['_trackPageview']);
      (function() {
            var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
              ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
              var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
        })();

</script>
</head>
<body style="background: #fff; font-size: 1.05em;">
<div id="content" style="margin-left: 20px;">
<img src="/images/logo_no_tagline.png" height="100px" width="auto" style="float: right; margin: 0 20px;" />
<a name="target"></a><h2 class="pageTitle">Nursery Contact Registration</h2>

<p>Please select the option that best describes your role<br>at the nursery where you work.</p>
<p>&nbsp;</p>

<ul class="grid-duo">
  <div class="btn-primary" style="margin-bottom:10px; font-size: 1.1em;">I'm the PRIMARY contact</div>
    <li><a href="/manager-buyer/register" target="_blank" onclick="parent.window.location='/manager-buyer/register'; parent.Lightbox.end();">I <strong>am authorized</strong> to order plants for the nursery</a></li>
    <li><a href="/retail-manager/register" target="_blank" onclick="parent.window.location='/retail-manager/register'; parent.Lightbox.end();">I am <strong>not authorized</strong> to order plants for the nursery</a></li>
</ul>
<ul class="grid-duo">
  <div class="btn-primary" style="margin-bottom:10px; font-size: 1.1em;">I am an ADDITIONAL contact</div>
    <li><a href="/employee-buyer/register" target="_blank" onclick="parent.window.location='/employee-buyer/register'; parent.Lightbox.end();">I <strong>am authorized</strong> to order plants for the nursery</a></li>
    <li><a href="/retail-employee/register" target="_blank" onclick="parent.window.location='/retail-employee/register'; parent.Lightbox.end();">I am <strong>not authorized</strong> to order plants for the nursery</a></li>
</ul>
</div>
</body>

