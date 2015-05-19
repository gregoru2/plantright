<?php

// $Id$

/**
 * @file
 * Views 2 support for Location website.
 */

/**
 * Implementation of hook_views_data().
 */
function location_website_views_data() {
  // ----------------------------------------------------------------
  // location_website table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.

  $data['location_website']['table']['group'] = t('Location');

  // Join location_website to all the tables that would be useful
  $data['location_website']['table']['join'] = array(
    // location_website links to location via lid.
    'location' => array(
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_website links to node through location_instance via lid.
    'node' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_website links to node_revisions through location_instance via lid.
    'node_revisions' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_website links to users through location_instance via lid.
    'users' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
  );

  // ----------------------------------------------------------------
  // location_website table -- fields

  $data['location_website']['website'] = array(
    'title' => t('Website'),
    'help' => t('The website of the selected location.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'empty field name' => t('None'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
  );

  return $data;
}
