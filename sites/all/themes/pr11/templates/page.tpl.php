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
</head>
<body <?php print phptemplate_body_attributes($is_front, $layout, $attr); ?>>

<div id="prContainer">
  <?php print $skipnav ?>

  <?php if ($header): ?>
    <div id="header"><div class="limiter clear-block">
      <?php print $header; ?>
    </div></div>
  <?php endif; ?>

  <div id="branding"><div class="limiter clear-block">
    <?php if ($site_name): ?><h1 class="site-name"><?php print $site_name ?></h1><?php endif; ?>
    <?php if ($search_box): ?><div class="block block-theme"><?php print $search_box ?></div><?php endif; ?>
  </div></div>

  <div id="navigation"><div class="limiter clear-block">
    <?php if (isset($primary_links)) : ?>
      <?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
    <?php endif; ?>
    <?php if (isset($secondary_links)) : ?>
      <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')) ?>
    <?php endif; ?>
  </div></div>

  <div id="page"><div class="limiter clear-block">

    <?php if ($left): ?>
      <div id="left" class="clear-block"><?php print $left ?></div>
    <?php endif; ?>

    <div id="main" class="clear-block">
      <?php if ($help || ($show_messages && $messages)): ?>
        <div id="console"><div class="limiter clear-block">
          <?php print $help; ?>
          <?php if ($show_messages && $messages): print $messages; endif; ?>
        </div></div>
      <?php endif; ?>
        <?php if ($breadcrumb) print $breadcrumb; ?>
        <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
        <?php if ($title): ?><h1 class="page-title"><?php print $title ?></h1><?php endif; ?>
        <?php if ($tabs) print $tabs ?>
        <?php if ($tabs2) print $tabs2 ?>
        <?php if ($content_top) print $content_top; ?>
        <div id="content"><div class="limiter clear-block"><?php print $content ?></div></div>

    <?php if ($right): ?>
      <div id="right"><div class="limiter clear-block"><?php print $right ?></div></div>
    <?php endif; ?>
	 <div id="footer"><div class="limiter clear-block">
    <?php print $feed_icons ?>
    <?php print $footer ?>
    <?php print $footer_message ?>
  </div></div>

  </div>

  </div></div>


<?php print $scripts ?>
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

<?php print $closure ?>

</div><!-- end prContainer -->

  </body>
</html>
