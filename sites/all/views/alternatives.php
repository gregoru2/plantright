$view = new view;
$view->name = 'region_invasives_list';
$view->description = 'Region Invasives List';
$view->tag = 'invasives list';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'field_plant_photo_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'label_type' => 'none',
    'format' => 'thumb_60_default',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '1',
      'multiple_from' => '0',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_plant_photo_fid',
    'table' => 'node_data_field_plant_photo',
    'field' => 'field_plant_photo_fid',
    'relationship' => 'none',
  ),
  'field_common_name_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 1,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_common_name_value',
    'table' => 'node_data_field_common_name',
    'field' => 'field_common_name_value',
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 0,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_node' => 0,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'name' => array(
    'default_action' => 'summary asc',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => 0,
      'override' => 0,
      'items_per_page' => '25',
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => 'Invasives of the %1 region',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'summary asc',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'lower',
    'transform_dash' => 1,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'business' => 0,
      'page' => 0,
      'species' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '1' => 1,
      '2' => 0,
    ),
    'validate_argument_type' => 'convert',
    'validate_argument_transform' => 1,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Override',
    ),
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'species' => 'species',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
  'tid' => array(
    'operator' => 'or',
    'value' => array(
      '1' => '1',
      '2' => '2',
      '3' => '3',
      '4' => '4',
      '5' => '5',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'type' => 'select',
    'limit' => TRUE,
    'vid' => '1',
    'id' => 'tid',
    'table' => 'term_node',
    'field' => 'tid',
    'hierarchy' => 0,
    'relationship' => 'none',
    'reduce_duplicates' => 0,
  ),
  'tid_1' => array(
    'operator' => 'or',
    'value' => array(
      '6' => '6',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'type' => 'select',
    'limit' => TRUE,
    'vid' => '2',
    'id' => 'tid_1',
    'table' => 'term_node',
    'field' => 'tid',
    'hierarchy' => 0,
    'relationship' => 'none',
    'reduce_duplicates' => 0,
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('items_per_page', 0);
$handler->override_option('distinct', 1);
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('arguments', array(
  'name' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => 0,
      'override' => 0,
      'items_per_page' => '25',
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => 'Invasives of the %1 region',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'summary asc',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'lower',
    'transform_dash' => 1,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => 'all',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'business' => 0,
      'page' => 0,
      'species' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '1' => 1,
      '2' => 0,
    ),
    'validate_argument_type' => 'convert',
    'validate_argument_transform' => 1,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('header', '<div class="big brown upcase float-left">Invasive plants in your region</div>

The following plants are invasive in your region of California. We encourage you to not buy, sell, plant, or promote the following species. Click on the plant name for more details, including links to photos of that plant and their invasion of natural areas. Use the "recommended alternatives" link to learn about the beautiful, non-invasive plants that we suggest for your gardening and landscaping needs that will not endanger California\'s wildlands.');
$handler->override_option('header_format', '2');
$handler->override_option('header_empty', 0);
$handler->override_option('path', 'regions');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->override_option('arguments', array(
  'name' => array(
    'default_action' => 'summary asc',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => 0,
      'override' => 0,
      'items_per_page' => '25',
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => 'Invasives of the %1 region',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'summary asc',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'lower',
    'transform_dash' => 1,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'business' => 0,
      'page' => 0,
      'species' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '1' => 1,
      '2' => 0,
    ),
    'validate_argument_type' => 'convert',
    'validate_argument_transform' => 1,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('header', 'A plant\'s invasiveness is largely a matter of location and climate. California\'s regions are organized on this site according to Sunset® Western Gardening Zones. You can select your region using the map on the left, or by clicking on your zone below:');
$handler->override_option('header_format', '2');
$handler->override_option('header_empty', 0);
$handler->override_option('footer', 'Learn more with a copy of Sunset\'s Western Garden Book from <a href="http://www.amazon.com/Western-Garden-Book-Sunset-Editors/dp/0376038519">Amazon.com</a>.');
$handler->override_option('footer_format', '2');
$handler->override_option('footer_empty', 0);
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Front page block', 'block_2');
$handler->override_option('arguments', array(
  'name' => array(
    'default_action' => 'summary asc',
    'style_plugin' => 'default_summary',
    'style_options' => array(
      'count' => 0,
      'override' => 0,
      'items_per_page' => '25',
    ),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => 'Invasives of the %1 region',
    'breadcrumb' => '',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'summary asc',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'lower',
    'transform_dash' => 1,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_fixed' => '',
    'default_argument_user' => 0,
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'business' => 0,
      'page' => 0,
      'species' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '1' => 1,
      '2' => 0,
    ),
    'validate_argument_type' => 'convert',
    'validate_argument_transform' => 1,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('header', 'If you already know which California region you are in, you can go directly to your regional list:');
$handler->override_option('header_format', '2');
$handler->override_option('header_empty', 0);
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
