<?php
/**
 * Progress complete box.
 */
$invites_count = count($content['invites']);

$total_buyers_count = $content['total_buyers_count'];

$certified_buyers = $content['certified_buyers'];
$certified_buyers_count = count($certified_buyers);

$slacker_buyers = $content['slacker_buyers'];
$uncertified_buyers_count = $total_buyers_count - $certified_buyers_count;
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
        <?php if ($total_buyers_count > 0 && $uncertified_buyers_count > 0): ?>
          <li>
            <a href="#" class="dropdown-toggle" style="color: red;">Your nursery has <?php print format_plural($uncertified_buyers_count, '1 new buyer who has', '@count new buyers who have'); ?> not passed <br/>the PlantRight 101 training</a>
            <div class="dropdown" style="display:none;">
              <p>Buyers who have not passed PlantRight 101 training:</p>
              <ul>
                <?php foreach ($slacker_buyers as $u): ?>
                  <?php $profile = node_load(array('uid' => $u->uid, 'type' => 'retail_member')); ?>
                  <?php if ($profile) : ?>
                    <li><?php print t('@fname @lname', array('@fname' => $profile->field_fname[0]['value'], '@lname' => $profile->field_lname[0]['value'])); ?> </li>
                  <?php else : ?>
                    <li><?php print $u->mail; ?> </li>
                  <?php endif; ?>
                <?php endforeach; ?>
              </ul>
            </div>
          </li>
        <?php endif; ?>
      <?php endif; ?>
    </ul>

    <p>Now that you're an official PlantRight partner, be sure to check out your <a href="/partner-resources">Partner Resources page</a></p>
  </div>
</div>