<?php if (empty($hide)): ?>

<?php if (!empty($pre_object)) print $pre_object ?>

<div <?php if (!empty($attr)) print drupal_attributes($attr) ?>>
  <?php if (!empty($title) && !$page): ?>
    <h2 class='<?php print $hook ?>-title'>
      <?php if (!empty($new)): ?><a id='new' class='new'><?php print('New') ?></a><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php elseif (!empty($title)): ?>
    <h2 class='<?php print $hook ?>-title'>
      <?php print $title ?>
    </h2>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <div class='<?php print $hook ?>-submitted clear-block'><?php print $submitted ?></div>
  <?php endif; ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clear-block <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php
      if (module_exists('imagecache') && ($field = variable_get('uc_image_' . $node->type, '')) && isset($node->$field) && file_exists($node->{$field}[0]['filepath'])) {
        print theme('uc_product_image', $node->$field, $teaser, $page);
      }
      ?>
      <?php print theme('uc_product_add_to_cart', $node, $teaser, $page); ?>
      <?php print $node->content['body']['#value']; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='<?php print $hook ?>-links clear-block'><?php print $links ?></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print $post_object ?>

<?php endif; ?>
