<?php
/**
 * Retailer partner resources
 */
$user_roles = $content['user_roles'];
?>

<h2 class="pageTitle">Your PlantRight Account</h2>

<?php if (in_array(13, $user_roles) || in_array(11, $user_roles)) : ?>
<!-- <div class="partner-benefit-links"> -->
<div class="horizontal-box">
  <div class="left-vertical">
    <?php if (in_array(13, $user_roles)): // User's store is partner ?>
    <h3>For Partners Only</h3>
    <p>You have have earned the right to use our PlantRight <a href="/partner-resources">Partner Resources</a>, including materials for:</p>
    <ul>
      <li>Store Promotion</li>
      <li>Education</li>
      <li>Industry Best Practices</li>
    </ul>
    <?php else: ?>
    <p>Partner benefits will become available when all plant buyers complete the quiz</p>
    <?php endif; ?>
  </div>
  <div class="right-vertical partner-benefit-links">
    <?php if (in_array(13, $user_roles)): // User's store is partner ?>
    <a href="/partner-resources" class="partner_resources_large_link">Click here for your exclusive <strong>Partner Resources</strong></a>
    <?php endif; ?>
    <?php if (in_array(11, $user_roles)): // User has passed the quiz  ?>
    <a href="/node/1421/certificate">Download your Certificate of Achievement</a>
    <?php endif; ?>
  </div>
</div>
<?php endif; ?>