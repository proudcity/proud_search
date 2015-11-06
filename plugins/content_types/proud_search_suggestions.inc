<?php


$plugin = array(
  'single' => TRUE,  
  'title' => t('Search result suggestions'),
  'description' => t('Suggestions from Drupal'),
  'category' => t('Blocks'),
  'render callback' => 'proud_search_suggestions_render', 
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function proud_search_suggestions_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('proud_search_suggestions');
  return $block;
}
