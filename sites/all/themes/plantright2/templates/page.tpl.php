<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head ?>
    <?php print $styles ?>
    <title><?php print $head_title ?></title>
  </head>
  <body <?php print drupal_attributes($attr) ?>>
  <?php print $skipnav ?>

  <div id="header-bg">
    <div class="wrapper">
    <?php if ($help || ($show_messages && $messages)): ?>
      <div id='console'><div class='limiter clear-block wrapper'>
        <?php print $help; ?>
        <?php if ($show_messages && $messages): print $messages; endif; ?>
      </div></div>
    <?php endif; ?>

    <div id='branding'><div class='limiter clear-block'>
      <?php if($logo): ?>
      <a href="<?php print $root_path ?>"><img src="<?php print $logo;?>" /></a>
      <?php endif; ?>
    </div></div>
  
    <?php if ($header): ?>
      <div id='header'><div class='limiter clear-block'>
        <?php print $header; ?>
      </div></div>
    <?php endif; ?>
    </div>
    <div class="clear-block"></div>
  </div>

  <div id='page'><div class='limiter clear-block wrapper'>

    <?php if ($left): ?>
      <div id='left' class='clear-block'><?php print $left ?></div>
    <?php endif; ?>

    <div id='main' class='clear-block'>
        <?php if ($breadcrumb) print $breadcrumb; ?>
        <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
        <?php if ($title): ?><h1 class='page-title'><?php print $title ?></h1><?php endif; ?>
        <?php if ($tabs) print $tabs ?>
        <?php if ($tabs2) print $tabs2 ?>
        <div id='content' class='clear-block'><?php print $content ?></div>
    </div>

    <?php if ($right): ?>
      <div id='right' class='clear-block'><?php print $right ?></div>
    <?php endif; ?>

  </div></div>

  <div id="footer"><div class='limiter clear-block wrapper'>
    <?php print $feed_icons ?>
    <?php print $footer ?>
    <?php print $footer_message ?>
  </div></div>

  <?php print $scripts ?>
  <?php print $closure ?>
  </body>
</html>
