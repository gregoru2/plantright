<?php if (empty($hide)): ?>

  <?php if (!empty($pre_object)) print $pre_object ?>

  <div <?php if (!empty($attr)) print drupal_attributes($attr) ?>>
    <div class="pr-slide">

    <?php if (!empty($content)): ?>
      <div class="<?php print $hook ?>-content clear-block <?php if (!empty($is_prose)) print 'prose' ?>">
        <div class="pr-slide-image">
          <?php print theme('imagecache', 'slide', $node->field_slide_image[0]['filepath'], $node->field_slide_image[0]['data']['alt'], $node->field_slide_image[0]['data']['title']); ?>
        </div>
        <div class="pr-slide-text">
          <?php print check_markup($node->content['body']['#value'], $node->format); ?>
        </div>

      </div>

      <?php if (!$page && node_access('update', $node)): ?>
        <div class='<?php print $hook ?>-links clear-block'>
          <li><a href="/node/<?php print $nid; ?>/edit slide">edit slide</a></li>
        </div>
      <?php endif; ?>
    <?php endif; ?>
    </div>
  </div>

  <?php if (!empty($post_object)) print $post_object ?>

<?php endif; ?>

