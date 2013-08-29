<?php
// $Id: content_profile-display-view.tpl.php,v 1.1.2.2 2009/01/04 11:46:29 fago Exp $

/**
 * @file content-profile-display-view.tpl.php
 *
 * Theme implementation to display a content-profile.
 */
global $user;
//dpm($user);
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
    <?php //dpm($node); ?>
    <h2 class="pageTitle">Your PlantRight <?php //print $node->readable_type; ?> Account</h2>
	<div class="account-greeting">Hello, !<div>
	<?php if ((in_array(11, array_keys($user->roles))) || in_array(13, array_keys($user->roles))): // User has passed the quiz ?>
	  <div class="partner-benefit-links"><h2>Your Partner Benefits</h2>
    <?php endif; ?>
	
	<?php if(in_array(11, array_keys($user->roles))): // User has passed the quiz ?>
      <a href="/node/1421/certificate">Your Certificate of Achievement</a>
    <?php endif; ?>
    <?php if (in_array(13, array_keys($user->roles))): // User's store is partner ?>
      <a href="/partner-resources">Partner Resources</a>
    <?php endif; ?>
	<?php if ((in_array(11, array_keys($user->roles))) || in_array(13, array_keys($user->roles))): // User has passed the quiz ?>
     </div><!-- end partner benefits div -->
    <?php endif; ?>
	
	<div class="partner-account-data">
	  <h2>Your Account Information</h2>
      <?php foreach ($node->profile_items as $profile_item): ?>
      <div class="profile-item">
        <div class="label"><?php print $profile_item['label']; ?></div>
        <div class="value"><?php print $profile_item['value'] ?></div>
      </div>
      <?php endforeach; ?>
	</div>
	</div>
  <?php endif; ?>
  <?php if ($node->type == 'retail_member'): ?>
    <h3>Retailer</h3>
    <?php if ($node->retailer): ?>
      <p>You are affiliated with <strong><?php print $node->retailer->title ?></strong></p>
    <?php elseif((in_array(7, array_keys($user->roles)) || in_array(8, array_keys($user->roles)))
                  && !$node->retailer): ?>
      <p>No affiliated nursery. <a href="/node/add/business">Register yours here.</a></p>
    <?php else: ?>
      <p>Edit your profile to choose an affiliated retailer.</p>
    <?php endif; ?>
    
  <?php endif; ?>
  <?php if ($node->type == 'continuing_education_member'): ?>
    <?php if(in_array(16, array_keys($user->roles))): // User has passed the quiz ?>
      <a class="btn-primary" href="/node/2949/certificate">Your Certificate of Achievement</a>
      <a class="btn-primary" href="/continuing-education-resources">Partner Resources</a>
    <?php endif; ?>
  <?php endif; ?>

  <?php global $user; if ($user->uid == $node->uid): ?>
    <span class="edit-account-instructions">Edit your profile information or change your password:</span>
    <a class="btn-primary" href="/node/<?php print $node->nid ?>/edit">Edit your account</a>
  <?php endif; ?>
</div>
