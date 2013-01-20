<?php
// $Id: 
/**
 * @file views-view-table.tpl.php
 * Template.
 *
 * @ingroup views_templates
 */

//var_dump($variables['view']->name);
//var_dump(get_defined_vars());

// Send our view to DOMPDF for streaming. 
dompdf_print_view($variables['view']->name);

