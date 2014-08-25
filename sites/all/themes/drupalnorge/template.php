<?php

/**
 * Theme callback to display that a user is attending an event.
 */
function drupalnorge_commons_events_attending_event($variables = array()) {
  global $user;
  $event = $variables['event'];
  if (!$event->nid) {
    return '';
  }

  $attendee_count = isset($variables['attendee_count']) ? $variables['attendee_count'] : 0;

  $registration_type = registration_get_entity_registration_type('node', $event);
  $registration = entity_get_controller('registration')->create(array(
    'entity_type' => 'node',
    'entity_id' => $event->nid,
    'type' => $registration_type,
    'author_uid' => $user->uid,
  ));

  if (!function_exists('commons_events_attend_event_form')
    || !function_exists('commons_events_cancel_event_form')) {
    module_load_include('inc', 'commons_events', 'includes/commons_events.forms');
  }
  if (!registration_is_registered($registration, NULL, $user->uid)
    && registration_access('create', $registration, $user, $registration->type)
    && registration_status('node', $event->nid, TRUE)) {
    return drupal_get_form('commons_events_attend_event_form_' . $event->nid, $event, $registration, $attendee_count);
  }
  return "";
}
