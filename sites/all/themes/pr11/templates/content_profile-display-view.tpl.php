<?php
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
    <div class="partner-account-data">
      <h2>Account Information</h2>
      <div class="profile-item">
        <div class="label">Name</div>
        <div class="value"><?php print $node->profile_items['first_name']['value'] . ' ' . $node->profile_items['last_name']['value']; ?></div>
      </div>

      <?php if ($node->type == 'retail_member'): ?>
        <div class="profile-item">
          <div class="label">Account type</div>
          <div class="value">Retail nursery partner</div>
        </div>
        <div class="profile-item">
          <div class="label">Retailer</div>
          <div class="value">
            <?php if ($node->retailer): ?>
              <?php print $node->retailer->title ?>
            <?php elseif ((in_array(7, $user_roles) || in_array(8, $user_roles)) && !$node->retailer): ?>
              <p>No affiliated retailer. <a href="/node/add/business">Register yours here.</a></p>
            <?php else: ?>
              <p><a href="/node/<?php print $node->nid ?>/edit">Edit your profile</a> to choose an affiliated retailer.</p>
            <?php endif; ?>
          </div>
        </div>
        <div class="profile-item">
          <div class="label">Nursery role</div>
          <div class="value">
            <?php if (in_array(9, $user_roles)): ?>
              Retail employee involved in plant purchasing
            <?php elseif (in_array(10, $user_roles)): ?>
              Retail employee not involved in plant purchasing
            <?php elseif (in_array(7, $user_roles)): ?>
              Manager involved in plant purchasing
            <?php elseif (in_array(8, $user_roles)): ?>
              Manager not involved in plant purchasing
            <?php endif; ?>
          </div>
        </div>
      <?php elseif ($node->type == 'continuing_education_member'): ?>

      <?php endif; ?>
      <div class="profile-item">
          <div class="label">Member since</div>
          <div class="value"><?php print date('n/j/Y', $user->created); ?></div>
      </div>

      <?php /* foreach ($node->profile_items as $key => $profile_item): ?>
        <div class="profile-item">
        <div class="label"><?php print $profile_item['label']; ?></div>
        <div class="value"><?php print $profile_item['value'] ?></div>
        </div>
        <?php endforeach; */ ?>
    </div>
  <?php endif; ?>
</div>
