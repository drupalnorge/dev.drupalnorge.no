<?php
/**
 * @file
 * commons_activity_streams.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commons_activity_streams_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commons_activity_streams_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function commons_activity_streams_default_message_type() {
  $items = array();
  $items['commons_activity_streams_comment_created'] = entity_import('message_type', '{
    "name" : "commons_activity_streams_comment_created",
    "description" : "commons_activity_streams_comment_created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "nb",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan\\u003E[message:user:picture:35x35]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E kommenterte \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E kommenterte \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "nb" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan\\u003E[message:user:picture:35x35]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E kommenterte \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E kommenterte \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022background-color:rgb(255, 255, 255); color:rgb(51, 51, 51); font-family:sans-serif,arial,verdana,trebuchet ms; font-size:13px\\u0022\\u003E[commons-groups:in-groups-text]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022background-color:rgb(255, 255, 255); color:rgb(51, 51, 51); font-family:sans-serif,arial,verdana,trebuchet ms; font-size:13px\\u0022\\u003E[commons-groups:in-groups-text]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture:35x35]",
          "format" : "filtered_html",
          "safe_value" : "[message:user:picture:35x35]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E commented on \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E commented on \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E"
        },
        {
          "value" : "[commons-groups:in-groups-text]",
          "format" : "full_html",
          "safe_value" : "[commons-groups:in-groups-text]"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['commons_activity_streams_node_created'] = entity_import('message_type', '{
    "name" : "commons_activity_streams_node_created",
    "description" : "commons_activity_streams_node_created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "nb",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan\\u003E[message:user:picture:35x35]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E opprettet \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E\\u0026lt;p\\u0026gt;\\u0026lt;a href=\\u0026quot;[message:user:url:absolute]\\u0026quot;\\u0026gt;[message:user:name]\\u0026lt;\\/a\\u0026gt; opprettet \\u0026lt;a href=\\u0026quot;[message:field-target-nodes:0:url]\\u0026quot;\\u0026gt;[message:field-target-nodes:0:title]\\u0026lt;\\/a\\u0026gt;\\u0026lt;\\/p\\u0026gt;\\u003C\\/p\\u003E\\n"
        }
      ],
      "nb" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan\\u003E[message:user:picture:35x35]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E opprettet \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E opprettet \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022background-color:rgb(255, 255, 255); color:rgb(51, 51, 51); font-family:sans-serif,arial,verdana,trebuchet ms; font-size:13px\\u0022\\u003E[commons-groups:in-groups-text]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022background-color:rgb(255, 255, 255); color:rgb(51, 51, 51); font-family:sans-serif,arial,verdana,trebuchet ms; font-size:13px\\u0022\\u003E[commons-groups:in-groups-text]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture:35x35]",
          "format" : "filtered_html",
          "safe_value" : "[message:user:picture:35x35]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E"
        },
        {
          "value" : "[commons-groups:in-groups-text]",
          "format" : "full_html",
          "safe_value" : "[commons-groups:in-groups-text]"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['commons_activity_streams_user_profile_updated'] = entity_import('message_type', '{
    "name" : "commons_activity_streams_user_profile_updated",
    "description" : "commons_activity_streams_user_profile_updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "nb",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E har en oppdatert profil\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E har en oppdatert profil\\u003C\\/p\\u003E"
        }
      ],
      "nb" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan\\u003E[message:user:picture:35x35]\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture:35x35]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E har en oppdatert profil\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E har en oppdatert profil\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture:35x35]",
          "format" : "filtered_html",
          "safe_value" : "[message:user:picture:35x35]"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has an updated profile",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E has an updated profile"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
