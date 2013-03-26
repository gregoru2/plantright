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
<body>
<a name="target"></a><h2 class="pageTitle">Choose Your Role</h2>

<p>Please select the option that best describes your role at the nursery where you work.</p>

<ul class="grid-trio">
  <a href="#" class="fold btn-primary">I'm a Nursery Manager or Owner</a>
  <div class="folded">
    <li><a href="/manager-buyer/register" target="_blank">I <strong><u>am authorized</u></strong> to order plants for the nursery</a></li>
    <li><a href="/retail-manager/register" target="_blank">I am <strong><u>not authorized</u></strong> to order plants for the nursery</a></l$
  </div>
</ul>

<ul class="grid-trio">
  <a href="#" class="fold btn-primary">I'm a Nursery Employee</a>
  <div class="folded">
    <li><a href="/employee-buyer/register" target="_blank">I <strong><u>am authorized</u></strong> to order plants for the nursery</a></li>
    <li><a href="/retail-employee/register" target="_blank">I am <strong><u>not authorized</u></strong> to order plants for the nursery</a></$
  </div>
</ul>
</body>
