<?php

// User Migration class
class dnUserMigration extends Migration {
  // class constructor
  public function __construct() {
    parent::__construct(MigrateGroup::getInstance('default'));
    $this->description = t('Migrate Drupal 6 users');
    $source_fields = array(
      'uid' => t('User ID'),
      'roles' => t('The set of roles assigned to a user.'),
    );

    // only import active users from the old db
    $query = Database::getConnection('default', 'migrate')
      ->select('users', 'u')
      ->fields('u', array('uid', 'name', 'pass', 'mail', 'created', 'access', 'login', 'status', 'init', 'signature'))
      ->condition('u.status', 1, '=')
      ->condition('u.uid', 1, '>')
      ->orderBy('u.uid', 'ASC');
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique User ID',
          'alias' => 'u',
        )
      ),
      MigrateDestinationUser::getKeySchema()
    );
    // Create the field mappings
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('pass', 'pass');
    $this->addFieldMapping('mail', 'mail')->dedupe('users', 'mail');
    $this->addFieldMapping('language')->defaultValue('');
    $this->addFieldMapping('theme')->defaultValue('');
    $this->addFieldMapping('signature', 'signature');
    $this->addFieldMapping('signature_format')->defaultValue('filtered_html');
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('access', 'access');
    $this->addFieldMapping('login', 'login');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('picture', 'user_picture');
    $this->addFieldMapping('init', 'init');
    $this->addFieldMapping('roles', 'roles');
  }

  /**
   * .forEach(function(n){});
   */
  public function prepareRow($current_row) {
    $source_id = $current_row->uid;
    $query = Database::getConnection('default', 'migrate')
      ->select('users_roles', 'r')
      ->fields('r', array('uid', 'rid'))
      ->condition('r.uid', $source_id, '=');
    $results = $query->execute();
    // add the Authenticated role for everyone
    $roles = array('2' => '2');
    foreach ($results as $row) {
      // administrasjon	is the same.
      if ($row->rid == 3) {
        $roles['3'] = '3';
      }
    }
    // Be a little lazy, and just switch db and do some queries.
    try {
      $current_file = $this->makeUserPicture($source_id);
      $current_row->user_picture = isset($current_file->fid) ? $current_file->fid : '';
    }
    catch (Exception $e) {
      // Oh well...
    }
    $current_row->roles = $roles;
    return TRUE;
  }

  private function makeUserPicture($uid) {
    $filequery = Database::getConnection('default', 'migrate')
        ->select('users', 'u')
        ->fields('u', array('picture'))
        ->condition('uid', $uid,'=')
        ->execute()
        ->fetchAssoc();
    if (empty($filequery['picture'])) {
      return FALSE;
    }
    $filename = $filequery['picture'];
    $file = new stdClass();
    $file->filename  = str_replace('sites/all/files/pictures/', '', $filename);
    $newfile = system_retrieve_file('http://www.drupalnorge.no/sites/all/files/pictures/' . $file->filename, 'public://pictures');
    $file->uri  = $newfile;
    $file->filemime = mime_content_type(drupal_realpath($file->uri));
    $file->filesize = filesize(drupal_realpath($file->uri));
    $file->uid = $uid;
    $file->type = 'user';
    $file->status = 1;

    $file = file_save($file);
    return $file;
  }

  private function get_array_for_pfield($fid, $uid) {
    $return = Database::getConnection('default', 'migrate')
          ->select('profile_values', 'p')
          ->fields('p', array('value'))
          ->condition('uid', $uid,'=')
          ->condition('fid', $fid,'=')
          ->execute()
          ->fetchAssoc();
    return is_array($return) ? $return['value'] : '';
  }
}
