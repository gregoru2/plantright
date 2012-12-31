<?php
// $Id: content_profile-display-view.tpl.php,v 1.1.2.2 2009/01/04 11:46:29 fago Exp $

/**
 * @file content-profile-display-view.tpl.php
 *
 * Theme implementation to display a content-profile.
 */
?>
<div class="content-profile-display" id="content-profile-display-<?php print $type; ?>">
  <?php if (isset($tabs)) : ?>
    <ul class="tabs content-profile">
      <?php foreach ($tabs as $tab) : ?>
        <?php if ($tab): ?>
          <li><?php print $tab; ?></li>
        <?php endif; ?>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
  <?php if (isset($node->nid) && isset($content)): ?>
    <?php dpm($node); ?>
    <h2>Your PlantRight <?php print $node->readable_type; ?> Account</h2>
    <?php foreach ($node->profile_items as $profile_item): ?>
    <div class="profile-item">
      <div class="label"><?php print $profile_item['label']; ?></div>
      <div class="value"><?php print $profile_item['value'] ?></div>
    </div>
    <?php endforeach; ?>
  <?php endif; ?>
  <?php if ($node->type == 'retail_member'): ?>
    <h3>Retailer</h3>
    <p>You are affiliated with <strong><?php print $node->retailer->title ?></strong></p>
  <?php endif; ?>
  <?php global $user; if ($user->uid == $node->uid): ?>
    <a class="btn-primary" href="/node/<?php print $node->nid ?>/edit">Edit Profile</a>
  <?php endif; ?>
</div>
