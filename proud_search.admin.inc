<?php

/**
 * @file
 * Administration functions for the proud_search module.
 */

/**
 * Menu callback: map settings
 */
function proud_search_admin_form() {
  $form = array();

  $form['proud_search_provider'] = array(
    '#type' => 'radios',
    '#title' => t('Search provider'),
    '#options' => array(
      'google' => t('Google'),
      'serach_api' => t('Internal site search'),
    ),
    '#default_value' => variable_get('proud_search_provider', 'google'),
  );

  $form['proud_search_placeholder'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Search placeholder text'),
    '#default_value' => variable_get('proud_search_placeholder', t('How may we help you?')),
  );

  $form['proud_search_google_cx'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Google Custom Search Engine CX key'),
    '#description' => t('You will need to create a new !cse.  After you have configured your search engine, copy the CX key into this box.', array('!cse' => l('Google Custom Search engine', 'https://cse.google.com/cse/'))),  //@todo: link to search engine setup documentation
    '#default_value' => variable_get('proud_search_google_cx', ''),
    // @todo: make states work here...
    '#states' => array(
      'checked' => array(
        'input[value=google]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['advanced']['proud_search_key'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Querystring parameter'),
    '#description' => variable_get('proud_search_provider', 'google') == 'google' ? t('You will need to enter this when you create your Google Custom Search Engine') : NULL,
    '#default_value' => variable_get('proud_search_key', 'term'),
  );

  $form['advanced']['proud_search_url'] = array(
    '#type' => 'textfield',
    '#size' => 20,
    '#title' => t('Advanced search url'),
    '#default_value' => variable_get('proud_search_url', 'search'),
  );

  // @todo: clear theme cache on submit? 

  return system_settings_form($form);
}
