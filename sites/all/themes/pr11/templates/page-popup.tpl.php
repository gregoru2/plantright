<?php
// Load regular page template on edit page.
if (arg(2) == 'edit') :
  include 'page.tpl.php';
else:
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
<?php print $head ?>
<?php print $styles ?>
<title><?php print $head_title ?></title>
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1"/>
<link href="http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,600,700,800" rel="stylesheet" type="text/css"/>
<link href="http://fonts.googleapis.com/css?family=PT+Sans+Narrow:400,700" rel="stylesheet" type="text/css"/>
<?php if ($is_front):?><link rel="stylesheet" href="/sites/default/files/agile_carousel/agile_carousel.css"/><?php endif; ?>
<!--[if lte IE 7]>
    <style type="text/css" media="all">@import "<?php print base_path() . path_to_theme() ?>/lte_ie7.css";</style>
  <![endif]-->
<?php if (!user_access('administer nodes')) : ?>
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
<script type="text/javascript" src="/<?php print drupal_get_path('theme', 'pr11') ?>/js/ga-events.js"></script>
<?php endif; ?>
</head>
<body class="popup">
<div id="content">
  <?php if (user_access('administer nodes')) : ?>
    <a href="/node/2392/edit">edit</a>
  <?php endif; ?>
  <?php print $content ?>
</div>
  <?php print $scripts ?>
</body>
</html>
<?php
endif;
?>