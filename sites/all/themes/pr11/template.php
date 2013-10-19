<?php

/**
 * Implementation of hook_theme().
 */
function pr11_theme() {
  $items = array();
  // Consolidate a variety of theme functions under a single template type.
  $items['block'] = array(
    'arguments' => array('block' => NULL),
    'template' => 'object',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );
  $items['box'] = array(
    'arguments' => array('title' => NULL, 'content' => NULL, 'region' => 'main'),
    'template' => 'object',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );
  $items['comment'] = array(
    'arguments' => array('comment' => NULL, 'node' => NULL, 'links' => array()),
    'template' => 'object',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );
  $items['node'] = array(
    'arguments' => array('node' => NULL, 'teaser' => FALSE, 'page' => FALSE),
    'template' => 'node',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );
  $items['fieldset'] = array(
    'arguments' => array('element' => array()),
    'template' => 'fieldset',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );

  // Use a template for form elements
  $items['form_element'] = array(
    'arguments' => array('element' => array(), 'value' => NULL),
    'template' => 'form-item',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );

  // Print friendly page headers.
  $items['print_header'] = array(
    'arguments' => array(),
    'template' => 'print-header',
    'path' => drupal_get_path('theme', 'pr11') . '/templates',
  );

  // Split out pager list into separate theme function.
  $items['pager_list'] = array('arguments' => array(
      'tags' => array(),
      'limit' => 10,
      'element' => 0,
      'parameters' => array(),
      'quantity' => 9,
      ));

  return $items;
}

/**
 * DEPRECATED. CSS exclusion is better handled with positive (yet omitted)
 * entries in your .info file.
 *
 * Strips CSS files from a Drupal CSS array whose filenames start with
 * prefixes provided in the $match argument.
 */
function pr11_css_stripped($match = array('modules/*'), $exceptions = NULL) {
  // Set default exceptions
  if (!is_array($exceptions)) {
    $exceptions = array(
      'modules/color/color.css',
      'modules/locale/locale.css',
      'modules/system/system.css',
      'modules/update/update.css',
      'modules/openid/openid.css',
      'modules/acquia/*',
    );
  }
  $css = drupal_add_css();
  $match = implode("\n", $match);
  $exceptions = implode("\n", $exceptions);
  foreach (array_keys($css['all']['module']) as $filename) {
    if (drupal_match_path($filename, $match) && !drupal_match_path($filename, $exceptions)) {
      unset($css['all']['module'][$filename]);
    }
  }

  // This servers to move the "all" CSS key to the front of the stack.
  // Mainly useful because modules register their CSS as 'all', while
  // pr11 has a more media handling.
  ksort($css);
  return $css;
}

/**
 * Print all child pages of a book.
 */
function pr11_print_book_children($node) {
  // We use a semaphore here since this function calls and is called by the
  // node_view() stack so that it may be called multiple times for a single book tree.
  static $semaphore;

  if (module_exists('book') && book_type_is_allowed($node->type)) {
    if (isset($_GET['print']) && isset($_GET['book_recurse']) && !isset($semaphore)) {
      $semaphore = TRUE;

      $child_pages = '';
      $zomglimit = 0;
      $tree = array_shift(book_menu_subtree_data($node->book));
      if (!empty($tree['below'])) {
        foreach ($tree['below'] as $link) {
          _pr11_print_book_children($link, $child_pages, $zomglimit);
        }
      }

      unset($semaphore);

      return $child_pages;
    }
  }

  return '';
}

/**
 * Book printing recursion.
 */
function _pr11_print_book_children($link, &$content, &$zomglimit, $limit = 500) {
  if ($zomglimit < $limit) {
    $zomglimit++;
    if (!empty($link['link']['nid'])) {
      $node = node_load($link['link']['nid']);
      if ($node) {
        $content .= node_view($node);
      }
      if (!empty($link['below'])) {
        foreach ($link['below'] as $child) {
          _pr11_print_book_children($child, $content);
        }
      }
    }
  }
}

/**
 * Preprocess functions ===============================================
 */
//function pr11_preprocess_views_view__nursery_list__page_1(&$vars) {
//  $results = $vars['view']->result;
//  foreach($results as $key => $result) {
//    if($result->flag_counts_node_count && $result->users_node_data_field_surveying_user_profile_values_profile_survey_w_others_value == 'No') {
//      unset($results[$key]);
//    }
//  }
//  $vars['view']->result = $results;
//  return $vars;
//}
//
//function pr11_preprocess_views_view_field__nursery_list__ops(&$vars) {
//
//}

/**
 * Implementation of preprocess_page().
 */
function pr11_preprocess_page(&$vars) {
  $nodes = array(2392);
  if (isset($_REQUEST['popup']) && in_array($vars['node']->nid, $nodes)) {
    $vars['template_files'][] = 'page-popup';
  }
  
  $attr = array();
  $attr['class'] = trim($vars['body_classes']);
  $attr['class'] .= ' pr11'; // Add the pr11 class so that we can avoid using the 'body' selector
  if (arg(0) == 'node' && arg(2) == 'edit') {
    $attr['class'] .= ' node-edit';
  }
  else if (arg(0) == 'user' && arg(2) == 'edit') {
    $attr['class'] .= ' user-edit';
  }

  // Replace screen/all stylesheets with print
  // We want a minimal print representation here for full control.
  if (isset($_GET['print'])) {
    $css = drupal_add_css();
    unset($css['all']);
    unset($css['screen']);
    $css['all'] = $css['print'];
    $vars['styles'] = drupal_get_css($css);

    // Add print header
    $vars['print_header'] = theme('print_header');

    // Replace all body classes
    $attr['class'] = 'print';

    // Use print template
    $vars['template_file'] = 'print-page';

    // Suppress devel output
    $GLOBALS['devel_shutdown'] = FALSE;
  }

  // Split primary and secondary local tasks
  $vars['tabs'] = theme('menu_local_tasks', 'primary');
  $vars['tabs2'] = theme('menu_local_tasks', 'secondary');

  // Link site name to frontpage
  $vars['site_name'] = l($vars['site_name'], '<front>');

  $vars['attr'] = $attr;
  $vars['body_classes'] = $attr['class'];

  // Skip navigation links (508).
  $vars['skipnav'] = "<a id='skipnav' href='#content'>" . t('Skip navigation') . "</a>";
}

/**
 * Implementation of preprocess_block().
 */
function pr11_preprocess_block(&$vars) {
  // Hide blocks with no content.
  $vars['hide'] = empty($vars['block']->content);

  $attr = array();
  $attr['id'] = "block-{$vars['block']->module}-{$vars['block']->delta}";
  $attr['class'] = "block block-{$vars['block']->module}";
  $vars['attr'] = $attr;

  $vars['hook'] = 'block';
  $vars['title'] = !empty($vars['block']->subject) ? $vars['block']->subject : '';
  $vars['content'] = $vars['block']->content;
  $vars['is_prose'] = ($vars['block']->module == 'block') ? TRUE : FALSE;
}

/**
 * Implementation of preprocess_box().
 */
function pr11_preprocess_box(&$vars) {
  $attr = array();
  $attr['class'] = "box";
  $vars['attr'] = $attr;
  $vars['hook'] = 'box';
}

/**
 * Implementation of preprocess_node().
 */
function pr11_preprocess_node(&$vars) {
  $attr = array();
  $attr['id'] = "node-{$vars['node']->nid}";
  $attr['class'] = "node node-{$vars['node']->type}";
  $attr['class'] .= $vars['node']->sticky ? ' sticky' : '';
  $vars['attr'] = $attr;
  $vars['hook'] = 'node';
  $vars['is_prose'] = TRUE;

  // Add print customizations
  if (isset($_GET['print'])) {
    $vars['post_object'] = pr11_print_book_children($vars['node']);
  }
  if ($vars['type'] == 'retail_member' || $vars['type'] == 'survey_profile' || $vars['type'] == 'continuing_education_member') {
    $user = user_load($vars['uid']);
    $type = ucwords(preg_replace('/_/', ' ', $vars['node']->type));
    $vars['node']->readable_type = $type;
    $vars['node']->profile_items['first_name']['label'] = "First Name:";
    $vars['node']->profile_items['first_name']['value'] = $vars['field_fname'][0]['value'];
    $vars['node']->profile_items['last_name']['label'] = "Last Name:";
    $vars['node']->profile_items['last_name']['value'] = $vars['field_lname'][0]['value'];
    $vars['node']->profile_items['email']['label'] = "Email:";
    $vars['node']->profile_items['email']['value'] = $user->mail;
    if ($vars['node']->type == 'retail_member') {
      $vars['node']->retailer = node_load($vars['node']->field_retailer[0][nid]);
    }
    $user_roles = $user->roles;
    if (($key = array_search('authenticated user', $user_roles)) !== false) {
      unset($user_roles[$key]);
    }
    $vars['node']->user_roles = $user_roles;
  }

  // Node 2392 is the registration popup node and has its own template.
  // Add JS specific to it.
  if ($vars['node']->nid == '2392') {
    drupal_add_js(drupal_get_path('theme', 'pr11') . '/js/plantright-registration.js');
  }
}

/**
 * Implementation of preprocess_comment().
 */
function pr11_preprocess_comment(&$vars) {
  $attr = array();
  $attr['id'] = "comment-{$vars['comment']->cid}";
  $attr['class'] = "comment {$vars['status']}";
  $vars['attr'] = $attr;

  $vars['hook'] = 'comment';
  $vars['is_prose'] = TRUE;
}

/**
 * Implementation of preprocess_fieldset().
 */
function pr11_preprocess_fieldset(&$vars) {
  $element = $vars['element'];
  $attr = isset($element['#attributes']) ? $element['#attributes'] : array();
  $attr['class'] = !empty($attr['class']) ? $attr['class'] : '';
  $attr['class'] .= " fieldset ";
  $attr['class'] .= $vars['id'];
  $attr['class'] .=!empty($element['#title']) ? ' titled' : '';
  $attr['class'] .=!empty($element['#collapsible']) ? ' collapsible' : '';
  $attr['class'] .=!empty($element['#collapsible']) && !empty($element['#collapsed']) ? ' collapsed' : '';
  $vars['attr'] = $attr;

  $description = !empty($element['#description']) ? "<div class='description'>{$element['#description']}</div>" : '';
  $children = !empty($element['#children']) ? $element['#children'] : '';
  $value = !empty($element['#value']) ? $element['#value'] : '';
  $vars['content'] = $description . $children . $value;
  $vars['title'] = !empty($element['#title']) ? $element['#title'] : '';
  if (!empty($element['#collapsible'])) {
    $vars['title'] = l(filter_xss_admin($vars['title']), $_GET['q'], array('fragment' => 'fieldset', 'html' => TRUE));
  }
  $vars['hook'] = 'fieldset';
}

/**
 * Implementation of preprocess_form_element().
 * Take a more sensitive/delineative approach toward theming form elements.
 */
function pr11_preprocess_form_element(&$vars) {
  $element = $vars['element'];

  // Main item attributes.
  $vars['attr'] = array();
  $vars['attr']['class'] = 'form-item';
  $vars['attr']['id'] = !empty($element['#id']) ? "{$element['#id']}-wrapper" : NULL;
  if (!empty($element['#type']) && in_array($element['#type'], array('checkbox', 'radio'))) {
    $vars['attr']['class'] .= ' form-option';
  }
  $vars['description'] = isset($element['#description']) ? $element['#description'] : '';

  // Generate label markup
  if (!empty($element['#title'])) {
    $t = get_t();
    $required_title = $t('This field is required.');
    $required = !empty($element['#required']) ? "<span class='form-required' title='{$required_title}'>*</span>" : '';
    $vars['label_title'] = $t('!title: !required', array('!title' => filter_xss_admin($element['#title']), '!required' => $required));
    $vars['label_attr'] = array();
    if (!empty($element['#id'])) {
      $vars['label_attr']['for'] = $element['#id'];
    }

    // Indicate that this form item is labeled
    $vars['attr']['class'] .= ' form-item-labeled';
  }
}

/**
 * Preprocessor for theme_print_header().
 */
function pr11_preprocess_print_header(&$vars) {
  $vars = array(
    'base_path' => base_path(),
    'theme_path' => base_path() . '/' . path_to_theme(),
    'site_name' => variable_get('site_name', 'Drupal'),
  );
  $count++;
}

/**
 * Function overrides =================================================
 */

/**
 * Override of theme_menu_local_tasks().
 * Add argument to allow primary/secondary local tasks to be printed
 * separately. Use theme_links() markup to consolidate.
 */
function pr11_menu_local_tasks($type = '') {
  if ($primary = menu_primary_local_tasks()) {
    $primary = "<ul class='links primary-tabs'>{$primary}</ul>";
  }
  if ($secondary = menu_secondary_local_tasks()) {
    $secondary = "<ul class='links secondary-tabs'>$secondary</ul>";
  }
  switch ($type) {
    case 'primary':
      return $primary;
    case 'secondary':
      return $secondary;
    default:
      return $primary . $secondary;
  }
}

/**
 * Override of theme_file().
 * Reduces the size of upload fields which are by default far too long.
 */
function pr11_file($element) {
  _form_set_class($element, array('form-file'));
  $attr = $element['#attributes'] ? ' ' . drupal_attributes($element['#attributes']) : '';
  return theme('form_element', $element, "<input type='file' name='{$element['#name']}' id='{$element['#id']}' size='15' {$attr} />");
}

/**
 * Override of theme_blocks().
 * Allows additional theme functions to be defined per region to
 * control block display on a per-region basis. Falls back to default
 * block region handling if no region-specific overrides are found.
 */
function pr11_blocks($region) {
  // Allow theme functions some additional control over regions.
  $registry = theme_get_registry();
  if (isset($registry['blocks_' . $region])) {
    return theme('blocks_' . $region);
  }
  return module_exists('context') && function_exists('context_blocks') ? context_blocks($region) : theme_blocks($region);
}

/**
 * Override of theme_username().
 */
function pr11_username($object) {
  if (!empty($object->name)) {
    // Shorten the name when it is too long or it will break many tables.
    $name = drupal_strlen($object->name) > 20 ? drupal_substr($object->name, 0, 15) . '...' : $object->name;
    $name = check_plain($name);

    // Default case -- we have a real Drupal user here.
    if ($object->uid && user_access('access user profiles')) {
      return l($name, 'user/' . $object->uid, array('attributes' => array('class' => 'username', 'title' => t('View user profile.'))));
    }
    // Handle cases where user is not registered but has a link or name available.
    else if (!empty($object->homepage)) {
      return l($name, $object->homepage, array('attributes' => array('class' => 'username', 'rel' => 'nofollow')));
    }
    // Produce an unlinked username.
    else {
      return "<span class='username'>{$name}</span>";
    }
  }
  return "<span class='username'>" . variable_get('anonymous', t('Anonymous')) . "</span>";
}

/**
 * Override of theme_pager().
 * Easily one of the most obnoxious theming jobs in Drupal core.
 * Goals: consolidate functionality into less than 5 functions and
 * ensure the markup will not conflict with major other styles
 * (theme_item_list() in particular).
 */
function pr11_pager($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  $pager_list = theme('pager_list', $tags, $limit, $element, $parameters, $quantity);

  $links = array();
  $links['pager-first'] = theme('pager_first', ($tags[0] ? $tags[0] : t('First')), $limit, $element, $parameters);
  $links['pager-previous'] = theme('pager_previous', ($tags[1] ? $tags[1] : t('Prev')), $limit, $element, 1, $parameters);
  $links['pager-next'] = theme('pager_next', ($tags[3] ? $tags[3] : t('Next')), $limit, $element, 1, $parameters);
  $links['pager-last'] = theme('pager_last', ($tags[4] ? $tags[4] : t('Last')), $limit, $element, $parameters);
  $links = array_filter($links);
  $pager_links = theme('links', $links, array('class' => 'links pager pager-links'));

  if ($pager_list) {
    return "<div class='pager clear-block'>$pager_list $pager_links</div>";
  }
}

/**
 * Split out page list generation into its own function.
 */
function pr11_pager_list($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  global $pager_page_array, $pager_total, $theme_key;
  if ($pager_total[$element] > 1) {
    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.
    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $links = array();

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for ($i; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $links["$i pager-item"] = theme('pager_previous', $i, $limit, $element, ($pager_current - $i), $parameters);
        }
        if ($i == $pager_current) {
          $links["$i pager-current"] = array('title' => $i);
        }
        if ($i > $pager_current) {
          $links["$i pager-item"] = theme('pager_next', $i, $limit, $element, ($i - $pager_current), $parameters);
        }
      }
      return theme('links', $links, array('class' => 'links pager pager-list'));
    }
  }
  return '';
}

/**
 * Return an array suitable for theme_links() rather than marked up HTML link.
 */
function pr11_pager_link($text, $page_new, $element, $parameters = array(), $attributes = array()) {
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query[] = drupal_query_string_encode($parameters, array());
  }
  $querystring = pager_get_querystring();
  if ($querystring != '') {
    $query[] = $querystring;
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    } else if (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  return array(
    'title' => $text,
    'href' => $_GET['q'],
    'attributes' => $attributes,
    'query' => count($query) ? implode('&', $query) : NULL,
  );
}

/**
 * Override of theme_views_mini_pager().
 */
function pr11_views_mini_pager($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.


  $links = array();
  if ($pager_total[$element] > 1) {
    $links['pager-previous'] = theme('pager_previous', (isset($tags[1]) ? $tags[1] : t('‹‹')), $limit, $element, 1, $parameters);
    $links['pager-current'] = array('title' => t('@current of @max', array('@current' => $pager_current, '@max' => $pager_max)));
    $links['pager-next'] = theme('pager_next', (isset($tags[3]) ? $tags[3] : t('››')), $limit, $element, 1, $parameters);
    return theme('links', $links, array('class' => 'links pager views-mini-pager'));
  }
}

/**
 * Override of theme_views_mini_pager for the trivia view.
 */
function pr11_views_mini_pager__trivia($tags = array(), $limit = 10, $element = 0, $parameters = array(), $quantity = 9) {
  global $pager_page_array, $pager_total;
  $pager_prev = $_SESSION['pr_trivia_pager_previous_page'];
  $pager_current = $pager_page_array[$element] + 1;
  $_SESSION['pr_trivia_pager_previous_page'] = $pager_current;
  
  $text = t('Give me another!');
  $links = array();
  if ($pager_total[$element] > 1) {
    // If going forward & there is a next page, show next link.
    if ($pager_current == 1 || $pager_current > $pager_prev) {
      $links['pager-next'] = theme('pager_next', $text, $limit, $element, 1, $parameters);
    }
    // Otherwise, show previous link
    if (empty($links['pager-next'])) {
      $links['pager-previous'] = theme('pager_previous', $text, $limit, $element, 1, $parameters);
    }

    return theme('links', $links, array('class' => 'links pager views-mini-pager'));
  }
}

/**
 * Sets the body tag class and id attributes.
 *
 * From the Theme Developer's Guide, http://drupal.org/node/32077
 *
 * @param $is_front
 *   boolean Whether or not the current page is the front page.
 * @param $layout
 *   string Which sidebars are being displayed.
 * @return
 *   string The rendered id and class attributes.
 */
function phptemplate_body_attributes($is_front = false, $layout = 'none', $attr = array()) {

  if ($is_front) {
    $body_id = $body_class = 'homepage';
  } else {
    // Remove base path and any query string.
    global $base_path;
    list(, $path) = explode($base_path, $_SERVER['REQUEST_URI'], 2);
    list($path, ) = explode('?', $path, 2);
    $path = rtrim($path, '/');
    // Construct the id name from the path, replacing slashes with dashes.
    $body_id = str_replace('/', '-', $path);
    // Construct the class name from the first part of the path only.
    list($body_class, ) = explode('/', $path, 2);
  }
  $body_id = 'page-' . $body_id;
  $body_class = 'section-' . $body_class;

  // Use the same sidebar classes as Garland.
  //$sidebar_class = ($layout == 'both') ? 'sidebars' : "sidebar-$layout";
  
  foreach($attr as $key => $val) {
    switch ($key) {
      case 'class':
        $body_class .= ' ' . $val;
        break;
      case 'id':
        $body_id = $val;
        break;
      default:
        break;
    }
  }

  return " id=\"$body_id\" class=\"$body_class $sidebar_class\"";
}

/**
 * Theme function for the invite form.
 *
 * @ingroup themeable
 */
function pr11_invite_form($form) {
  $output = '';
  $op = $form['#parameters'][2];

  if ($op == 'page') {
    // Show form elements.
    $output .= drupal_render($form['remaining_invites_markup']);
    $output .= drupal_render($form['remaining_invites']);
    $output .= drupal_render($form['from']);
    if (isset($form['email_markup'])) {
      $output .= drupal_render($form['email_markup']);
    }
    $output .= drupal_render($form['email']);
    $output .= drupal_render($form['subject']);

    // Show complete invitation message.
    $output .= drupal_render($form['body']);
    $output .= '<div class="invite-message"><div class="opening">';

    // Prepare invitation message.
    $message_form = "</p></div>\n" . drupal_render($form['message']) . "\n" . '<div class="closing"><p>';
    $body = _filter_autop(t(_invite_get_mail_template()));

    // Perform token replacement on message body.
    $types = _invite_token_types(array('data' => array('message' => $message_form)));
    $output .= token_replace_multiple($body, $types);

    $output .= "</div></div>\n";
  }

  // Render all missing form elements.
  $output .= drupal_render($form);

  $output .= '<br /><a href="/plantright-101-training">Skip this step (I\'m the only buyer)</a>';

  return $output;
}

/**
 * Implementation of hook_preprocess_location().
 */
function pr11_preprocess_location($vars) {
  // Change the format of the map link.
  $vars['map_link'] = str_replace(array('See map:', 'Google Maps'), array('', 'map'), $vars['map_link']);

  // Format the phone number.
  // Takes numbers entered as either 5551234567 or 555-123-4567 and formats
  // as (555) 123-4567.
  $vars['phone'] = preg_replace('/(\d{3})-?(\d{3})-?(\d{4})$/', '($1) $2-$3', $vars['phone']);

  // Country name is set to hidden in settings, but still showing.
  // Remove below to show again.
  $vars['country_name'] = '';
}

/**
 * Implementation of theme_mimemail_message().
 */
function pr11_preprocess_mimemail_message(&$vars) {
  $vars['body'] = str_replace('<br />', '', $vars['body']);
  $vars['body'] = str_replace('•', '<br />' . '•', $vars['body']);
}

/**
 * Preprocess the content profile display view.
 */
function pr11_preprocess_user_profile($vars) {
  $account = user_load(arg(1));
  $vars['name'] = plantright_get_user_profile_name($account);
  $vars['node'] = plantright_get_user_profile($account);
  $vars['user_roles'] = array_keys($account->roles);
}

/**
 * Preprocess the content profile display view.
 */
function pr11_preprocess_content_profile_display_view($vars) {
  $vars['user'] = user_load($vars['uid']);
  $vars['name'] = $vars['node']->profile_items['first_name']['value'] . ' ' . $vars['node']->profile_items['first_name']['value'];
  $vars['user_roles'] = array_keys($vars['user']->roles);
}
