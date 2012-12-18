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
//dpm($block->content);
$content = $block->content;
$total_invites = $content['total_invites'];
$ignored_invites = $content['ignored_invites'];
$accepted_invites = $content['accepted_invites'];
$invite_percentage = ($accepted_invites / $total_invites) * 100;
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div id="progress-block" class="content">
    <h2>Becoming a PlantRight Partner</h2>
    <h3>The Checklist</h3>
    <p>This checklist shows your completed steps and what's still required to becomea certified PlantRight Partner nursery.</p>
    
    <div id="store-registered" class="<?php print $content['store_registered'] ?>">
      <p>Register a store account for your nursery</p>
      <?php if ($content['store_registered'] == 'registered'): ?>
        <p class="status">Completed</p>
      <?php else : ?>
        <p class="status"><a href="/node/add/business">Register your nursery now</a></p>
      <?php endif; ?>
    </div>

    <div id="invite-staff" class="<?php if ($content['invites']) { print("completed")} ?>">
      <p>Invite your staff to join.</p>
      <?php if ($content['invites']): ?>
        <p class="status">Completed but, <a href="/invite">feel free to invite more</a></p>
      <?php else : ?>
        <p class="status"><a href="/invite">Invite Staff</a></p>
      <?php endif; ?>
    </div>

    <div id="invite-status" class="<?php if ($invite_percentage == 100) { print("completed")} ?>">
      <p>All staff members register at PlantRight.org</p>
      <?php if ($total_invites == $accepted_invites): ?>
        <p class="status">Completed</p>
      <?php else : ?>
      <div class="action">
        <h4><?php print $accepted_invites ?> of <?php print $total_invites ?> staff members have registered</h4>
        <div class="progress-bar" style="background-position: <?php print $invite_percentage ?>% center"></div>
        <p>We're still waiting for:</p>
        <ul>
        <?php foreach($ignored_invites as $invite): ?>
          <li><?php print $invite->email ?> - <a href="/invite/resend/<?php print $invite->reg_code ?>">resend invite</a></li>
        <?php endforeach; ?>
        </ul>
      </div>
      <?php endif; ?>
    </div>

    <div id="review-material">

    </div>

  </div>
</div>
