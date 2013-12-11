<?php
$user_roles = $content['user_roles'];

if (in_array(16, $user_roles)):
// User has passed the Continuing Education quiz
  ?>

  <div class="horizontal-box">
    <div class="left-vertical">
	<h3>Continuing Education Status:  Complete</h3>
    <p>Congratulations!  Visit the <a href="/continuing-education-resources">Education Resources page</a> to access exclusive materials and to take the PlantRight Ambassador Pledge.</p>
    
    </div>
    <div class="right-vertical partner-benefit-links">

      <div class="partner-benefit-links cont-ed-benefits">
        <a href="/continuing-education-resources" class="partner_resources_large_link">Click here for <strong>Education Resources</strong></a>
        <a href="/node/2949/certificate">Download your Certificate of Achievement</a>
      </div>
    </div>
  </div>
<?php endif; ?>
