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
$classes = '';

$account = $content['account'];
$content = $block->content;

$invites_count = count($content['invites']);
$invites_sent = $invites_count ? "complete" : "incomplete";
$ignored_invites = $content['ignored_invites'];

$registered_staff_count = $content['registered_staff_count'];
$total_buyers_count = $content['total_buyers_count'];

$registered_buyers = $content['registered_buyers'];
$registered_buyers_count = count($registered_buyers);
$register_percentage = $total_buyers_count > 0 ? ($registered_buyers_count / $total_buyers_count) * 100 : 'n/a';
$register_progress = ($register_percentage == 100) ? "complete" : "incomplete";

$registered_nonbuyers = $content['registered_nonbuyers'];
$registered_nonbuyers_count = count($registered_nonbuyers);

$certified_buyers = $content['certified_buyers'];
$certified_buyers_count = count($certified_buyers);
$slacker_buyers = $content['slacker_buyers'];
$uncertified_buyers_count = $total_buyers_count - $certified_buyers_count;

$certified_nonbuyers = $content['certified_nonbuyers'];
$certified_nonbuyers_count = count($certified_nonbuyers);
$slacker_nonbuyers = $content['slacker_nonbuyers'];

$user_quiz_status = $content['account_quiz_status'];
$user_quiz_progress = $user_quiz_status ? "complete" : "incomplete";
$group_quiz_progress = ($total_buyers_count > 0 && $certified_buyers_count >= $total_buyers_count) ? "complete" : "incomplete";

if ($content['progress_complete']) {
  $classes .= ' progress-complete';
}
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?><?php print $classes; ?>">
<?php if ($block->subject): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div id="progress-block" class="content">
	<h2 id="the-checklist">Your Progress</h2>
    <h3>Steps to Becoming a PlantRight Partner</h3>
    <p>This checklist shows your completed steps and what's still required to become a PlantRight Retail Nursery Partner.</p>

   <div id="register-account" class="item complete">
      <p class="desc">You've created an account at PlantRight.org</p>
    </div>

    <div id="store-registered" class="item <?php print $content['store_registered'] ?>">
       <?php if ($content['retailer_nid']): ?>
        <p class="desc">You've chosen your nursery. <span class="progress_option"><a href="/node/<?php print $content['profile_nid']; ?>/edit">Edit profile</a></span></p>
      <?php elseif ($content['profile_nid']): ?>
        <p class="desc"><a href="/node/<?php print $profile_nid; ?>/edit">Choose your nursery.</a></p>
      <?php else : ?>
	      <p class="desc"><a href="/node/add/retail-member">Choose your nursery</a></p>
      <?php endif; ?>
    </div>

    <div id="review-material" class="item <?php print $user_quiz_progress ?>">
      <?php if ($user_quiz_status): ?>
       <p class="desc">You've reviewed the training materials and passed the quiz. <span class="progress_option"><a href="/plantright-101-training">Revisit study materials</a></span></p>
      <?php else : ?>
        <p class="desc"><a href="/plantright-101-training">Review the PlantRight 101 training materials and take the 10-question quiz.</a></p>
		<span class="checklist_fineprint">This step is required for plant buyers, recommended for all.</span>
      <?php endif; ?>
    </div>

    <div id="pass-quiz" class="item <?php print $group_quiz_progress ?>">
      <?php if ($total_buyers_count > 0 && $uncertified_buyers_count <= 0): ?>
        <p class="desc">All plant buyers at your nursery have completed the PlantRight 101 training.</p>
        <p class="status">Congratulations!  Visit PlantRight's <a href="/partner-resources">Partner Resources</a>.</p>
      <?php else : ?>
	      <p class="desc">All plant buyers must complete the PlantRight 101 training</p>
      <?php endif; ?>
      <a href="#" class="dropdown-toggle">Your progress details</a>
      <div class="dropdown">
        <h4><?php print $certified_buyers_count ?> of <?php print $total_buyers_count ?> buyers and <?php print $certified_nonbuyers_count ?> non-buyer staff are PlantRight Graduates</h4>
      </div>
    </div>

  </div>
</div>
