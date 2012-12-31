<?php if (empty($hide)): ?>

<?php if (!empty($pre_object)) print $pre_object ?>

<div <?php if (!empty($attr)) print drupal_attributes($attr) ?>>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clear-block <?php if (!empty($is_prose)) print 'prose' ?>'>
      <?php print $content ?>
    </div>
  <?php endif; ?>
  <?php global $user; if ($node->uid === $user->uid): ?>
    <a href="/node/<?php print $node->nid ?>/edit" class="btn-primary">Edit Profile</a>
  <?php endif; ?>
  <?php// dpm($node); ?>
</div>

<?php if (!empty($post_object)) print $post_object ?>

<?php endif; ?>
