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
$total_invites = $content['total_invites'];
$ignored_invites = $content['ignored_invites'];
$accepted_invites = $content['accepted_invites'];
$invite_percentage = ($accepted_invites / $total_invites) * 100;
//dpm($user);
$invites_sent = $content['invites'] ? "complete" : "incomplete";
$invite_progress = ($invite_percentage == 100) ? "complete" : "incomplete";
$user_quiz_progress = in_array(11, array_keys($user->roles)) ? "complete" : "incomplete" ;
$group_quiz_progress = (count($content['certified_buyers']) >= $content['total_buyers']) ? "complete" : "incomplete";
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div id="progress-block" class="content">
    <h2>Becoming a PlantRight Partner</h2>
    <h3 id="the-checklist">The Checklist</h3>
    <p>This checklist shows your completed steps and what's still required to become a certified PlantRight Partner nursery.</p>
    
    <div id="store-registered" class="item <?php print $content['store_registered'] ?>">
      <p class="desc">Register a store account for your nursery</p>
      <?php if ($content['store_registered'] == 'complete'): ?>
        <p class="status">Completed</p>
      <?php else : ?>
        <p class="status"><a href="/node/add/business">Register your nursery now</a></p>
      <?php endif; ?>
    </div>

    <div id="invite-staff" class="item <?php print $invites_sent ?>">
      <p class="desc">Invite your staff to join.</p>
      <?php if ($content['invites']): ?>
        <p class="status">Completed but, <a href="/invite">feel free to invite more</a></p>
      <?php else : ?>
        <p class="status"><a href="/invite">Invite Staff</a></p>
      <?php endif; ?>
    </div>

    <div id="invite-status" class="item <?php print $invite_progress ?>">
      <p class="desc">All staff members register at PlantRight.org</p>
      <?php if ($total_invites > 0 && $total_invites == $accepted_invites): ?>
        <p class="status">Completed</p>
      <?php else : ?>
      <a href="#" class="dropdown-toggle">Your progress details</a>
      <div class="dropdown">
        <h4><?php print $accepted_invites ?> of <?php print $total_invites ?> staff members have registered</h4>
        <progress value="<?php print $invite_percentage ?>" max="100" style="width:100%" ></progress>
        <p>We're still waiting for:</p>
        <ul>
        <?php foreach($ignored_invites as $invite): ?>
          <li><?php print $invite->email ?> - <a href="/invite/resend/<?php print $invite->reg_code ?>">resend invite</a></li>
        <?php endforeach; ?>
        </ul>
      </div>
      <?php endif; ?>
    </div>

    <div id="review-material" class="item <?php print $user_quiz_progress ?>">
      <p class="desc">Review the PlantRight 101 training materials</p>
      <?php if (in_array(11, array_keys($user->roles))): ?>
        <p class="status">Complete</p>
      <?php else : ?>
        <p class="status"><a href="/plantright-101-training">PlantRight 101 training page</a></p>
      <?php endif; ?>
    </div>

    <div id="pass-quiz" class="item <?php print $group_quiz_progress ?>">
      <p class="desc">All plant buyers pass our 10 question quiz</p>
      <?php if ($content['total_buyers'] >= count($certified_buyers)): ?>
        <p class="status">Complete</p>
      <?php else : ?>
        <a href="#" class="dropdown-toggle">Your progress details</a>
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
