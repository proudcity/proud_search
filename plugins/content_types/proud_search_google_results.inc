<?php


$plugin = array(
  'single' => TRUE,  
  'title' => t('Google search results'),
  'description' => t('Search results from Google'),
  'category' => t('Blocks'),
  'render callback' => 'proud_search_google_results_render', 
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function proud_search_google_results_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('proud_search_google_results');
  return $block;
}
