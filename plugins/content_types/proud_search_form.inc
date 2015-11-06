<?php


$plugin = array(
  'single' => TRUE,  
  'title' => t('Search form'),
  'description' => t('Search autocomplete form'),
  'category' => t('Blocks'),
  'render callback' => 'proud_search_form_render', 
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function proud_search_form_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = '';
  // Rendered here, so don't render in overlay
  $GLOBALS['PROUD_SEARCH_RENDERED'] = TRUE;
  $block->content = theme('proud_search_form');
  return $block;
}
