
DESCRIPTION
------------------------------------------------
The dompdf module allows other modules to utilize the dompdf library, written
by Benj Carson, and maintained at http://www.digitaljunkies.ca/dompdf.  The
module is currently just a *very* lightweight implementation, containing just
one method that allows other modules to stream a PDF to the browser.


REQUIREMENTS
------------------------------------------------
Due to the requirements in the dompdf library, this module requires:
http://www.digitaljunkies.ca/dompdf/install.php#requirements 


IMPORTANT SECURITY NOTICE
------------------------------------------------
dompdf version 0.5.1 and lower has a major security flaw in a file that is 
*not* used by this module.  Be sure to follow the final steps of the 
installation instructions below to avoid leaving your site in an insecure
state.


INSTALLATION
------------------------------------------------
Download dompdf library from http://www.digitaljunkies.ca/dompdf and unpack 
its contents to the this module's dompdf folder, so that dompdf_config.inc.php 
is located at /path/to/drupal/sites/all/modules/dompdf/dompdf/dompdf_config.inc.php

***IMPORTANT SECURITY NOTICE***
If you are using dompdf version 0.5.1 or lower, remove the file dompdf.php
from the dompdf library folder.  This file contains a major security flaw,
as noted in http://drupal.org/node/218334

Ensure that /path/to/drupal/.../modules/dompdf/dompdf/lib/fonts is writable as
required by the dompdf library (see INSTALL in dompdf library).

As of Drupal 6, the dompdf module integrates with Views Bonus Exports (part
of the Views Bonus Pack http://drupal.org/project/views_bonus) to provide PDF
exports.

Enable this module and use a module that takes advantage of it! 

USAGE WITH VIEWS 2
------------------------------------------------
Add a "feed" display to a view and select the "PDF" style in the basic
settings. In the Feed Settings, choose a path for the export to PDF URL and
attach the feed to another display. The display you attach to will now how a 
PDF feed icon linking to your PDF export.

MODULES KNOWN TO HAVE DOMPDF SUPPORT
------------------------------------------------
Signup Status
