<?php
$invites_count = count($content['invites']);
?>
<div id="block-<?php print $block->module . '-' . $block->delta; ?>" class="block block-<?php print $block->module ?><?php print $classes; ?>">
  <?php if ($block->subject): ?>
    <h2><?php print $block->subject ?></h2>
  <?php endif; ?>
  <div id="progress-block-complete" class="content">
    <h2 id="the-checklist">Your Progress: Complete</h2>
    <p><strong>Congratulations,</strong> you've completed all the steps to becoming a PlantRight Partner nursery.</p>
    <ul>
      <li>
        <a href="#" class="dropdown-toggle">See the partnership steps</a>
        <div class="dropdown" style="display:none;" id="pr-retailer-progress-partnership-steps">
        </div>
      </li>
      <?php if ($content['liaison']): ?>
      <li>
        <a href="#" class="dropdown-toggle">Manage employee invitations</a>
        <div class="dropdown" style="display:none;">
          <ul>
            <li><a href="/invite">Invite your staff</a></li>
            <?php if ($invites_count): ?>
            <li><a href="/invites/user/<?php print $content['account']->uid; ?>">Invitation statuses</a></li>
            <?php endif; ?>
          </ul>
        </div>
      </li>
      <?php endif; ?>
    </ul>
    
    <p>Now that you're an official PlantRight partner, be sure to check out your <a href="/partner-resources">Partner Resources page</a></p>
  </div>
</div>