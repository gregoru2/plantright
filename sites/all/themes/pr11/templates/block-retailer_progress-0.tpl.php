<?php

/**
 * @file block.tpl.php
 *
 * Theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $block->content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: This is a numeric id connected to each module.
 * - $block->region: The block region embedding the current block.
 *
 * Helper variables:
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 */
global $user;

$content = $block->content;
dpm($content);
$total_invites = $content['total_invites'];
$ignored_invites = $content['ignored_invites'];
$accepted_invites = $content['accepted_invites'];
if ($total_invites = 0) {
  $invite_percentage = "n/a";
}
else {
  if ($total_invites > 0) {
    $invite_percentage = ($accepted_invites / $total_invites) * 100;
  }
}
//dpm($user);
$invites_sent = $content['invites'] ? "complete" : "incomplete";
$invite_progress = ($invite_percentage == 100) ? "complete" : "incomplete";
$user_quiz_progress = in_array(11, array_keys($user->roles)) ? "complete" : "incomplete" ;
$group_quiz_progress = (!empty($content['certified_buyers']) && count($content['certified_buyers']) >= $content['total_buyers']) ? "complete" : "incomplete";
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div id="progress-block" class="content">
	<h2 id="the-checklist">Your Progress</h2>
    <h3>Steps to Becoming a PlantRight Partner</h3>
    
    <p>This checklist shows your completed steps and what's still required to become a certified PlantRight Partner nursery.</p>
    
    <div id="store-registered" class="item <?php print $content['store_registered'] ?>">
       <?php if ($content['store_registered'] == 'complete'): ?>
        <p class="desc">You've registered your nursery.</p>
      <?php else : ?>
        <p class="desc"><a href="/node/add/business">Register your nursery.</a></p>
      <?php endif; ?>
    </div> 
	

    <div id="invite-staff" class="item <?php print $invites_sent ?>">
      <?php if ($content['invites']): ?>
        <p class="desc">You've invited your staff to join. <span class="progress_option"><a href="/invite">Manage invitations</a></span></p>
      <?php else : ?>
        <p class="desc"><a href="/invite">Invite your staff to join.</a></p>
      <?php endif; ?>
    </div>

    <div id="invite-status" class="item <?php print $invite_progress ?>">
      <?php if ($total_invites > 0 && $total_invites == $accepted_invites): ?>
      <p class="desc">All plant buyers are register at PlantRight.org.</p>
      <?php else : ?>
      <p class="desc">All plant buyers need to register at PlantRight.org.</p>
      <a href="#" class="dropdown-toggle">Staff progress details</a>
      <div class="dropdown">
        <h4><?php print $accepted_invites ?> of <?php print $total_invites ?> staff members have registered</h4>
        <progress value="<?php print $invite_percentage ?>" max="100" style="width:100%" ></progress>
        <p>We're still waiting for:</p>
        <ul>
        <?php foreach($ignored_invites as $invite): ?>
          <li><?php print $invite->email ?> - <a href="/invite/resend/<?php print $invite->reg_code ?>">resend invitation</a></li>
        <?php endforeach; ?>
        </ul>
      </div>
      <?php endif; ?>
    </div>

    <div id="review-material" class="item <?php print $user_quiz_progress ?>">
      <?php if (in_array(11, array_keys($user->roles))): ?>
        <p class="desc">You've reviewed the training materials and passed the quiz. <span class="progress_option"><a href="/plantright-101-training">Revisit study materials</a></span></p>
      <?php else : ?>
        <p class="desc"><a href="/plantright-101-training">Review the PlantRight 101 training materials and take the 10-question quiz.</a></p>
      <?php endif; ?>
    </div>

    <div id="pass-quiz" class="item <?php print $group_quiz_progress ?>">
      <?php if (!empty($content['certified_buyers']) && $content['total_buyers'] <= count($content['certified_buyers'])): ?>
        <p class="desc">Congratulations! All plant buyers at your nursery have passed our 10 question quiz.</p>
      <?php else : ?>
        <p class="desc">All plant buyers must pass our 10 question quiz.</p>
        <a href="#" class="dropdown-toggle">Plant buyer progress details</a>
        <div class="dropdown">
          <h4><?php print count($content['certified_buyers']) ?> of <?php print $content['total_buyers'] ?> are certified</h4>
          <p>We're still waiting for:</p>
          <ul>
            <?php if ($slackers): ?>
              <?php foreach ($slackers as $slacker): ?>
                <li><?php print $slacker->email ?></li>
              <?php endforeach; ?>
            <?php else: ?>
              <li>Some folks who haven't registered yet.</li>
            <?php endif; ?>
          </ul>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
