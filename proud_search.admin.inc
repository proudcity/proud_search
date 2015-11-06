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

  $form['proud_map_lat'] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Latitude'),
    '#default_value' => variable_get('proud_map_lat', 34.738228),
  );
  $form['proud_map_lng'] = array(
    '#type' => 'textfield',
    '#size' => 5,
    '#title' => t('Longitude'),
    '#default_value' => variable_get('proud_map_lng', -86.601791),
  );

  $form['mapbox'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mapbox settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['mapbox']['proud_map_mapbox_map'] = array(
    '#type' => 'textfield',
    '#title' => t('Mapbox map id'),
    //'#description' => t('This should return a large body of text, such as //body.'),
    '#default_value' => variable_get('proud_map_mapbox_map', 'albatrossdigital.lpkdpcjb'), // @todo: no default
  );
  $form['mapbox']['proud_map_mapbox_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access token'),
    //'#description' => t('This should return a large body of text, such as //body.'),
    '#default_value' => variable_get('proud_map_mapbox_access_token', 'pk.eyJ1IjoiYWxiYXRyb3NzZGlnaXRhbCIsImEiOiI1cVUxbUxVIn0.SqKOVeohLfY0vfShalVDUw'), // @todo: no default
  );

  return system_settings_form($form);
}
