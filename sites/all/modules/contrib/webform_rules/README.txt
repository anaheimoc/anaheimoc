/* $Id: README.txt,v 1.1.2.5 2010/12/18 10:50:12 stborchert Exp $ */

This module provides basic rules integration for webform.


-- REQUIREMENTS --

You need the following modules for a working feature:

 * Webform (http://drupal.org/project/webform)
 * Rules (http://drupal.org/project/rules)

optional:
 * Token (http://drupal.org/project/token)


-- INSTALLATION --

Copy the module files to you module directory and then enable it on the admin
modules page. After that you'll see two new events in the listing while creating
a new rule.


-- USAGE --

Using the submitted data in a rule is easy, as you can access it either via PHP
or using tokens (after installing the Token-module).

PHP:
 Each rule reacting on an event thrown by "Webform Rules" gets 3 arguments to
 work with:
  * $user
     The user object of the acting user (the one, who submitted the webform).
  * $node
     The webform itself.
  * $data
     The submitted webform data and the submission id.
     To get the submission id, use <code><?php print $data['sid']; ?></code>.
     The components of the webform are stored using this structure:
     <code>array(
       '{form_key}' => array(
         'value' => {submitted value},
         'component' => {webform component},
       ),
     )</code>
     Given this structure, you can access the value of a component called
     "email" with
     <code><?php print $data['components']['email']['value']; ?></code>.
    
     Warning:
      This is raw user input! Make sure to run this through check_plain() before
      using it.
    
     Note:
      Some components (for example "grid") return arrays, so 'value' isn't a
      simple string always.

     Modifying submitted data:
      $data is capable of "intelligent saving" meaning you can modify the
      submitted webform data with a rule and save it back to the submission.
      To do so you'll need to assign the new value to the component and return
      the data with <code>return array('data' => $data);</code>
      Example (guessing you have components called "email" and "workdays"):
       <code>
       // Set email to "info@example.com" by default.
       $data['components']['email']['value'] = 'info@example.com';
       // Set workdays from Tuesday to Thursday by default.
       // Component "workdays" is a set of checkboxes in this example.
       $data['components']['workdays']['value'] = array(
         'tuesday', 'wednesday', 'thursday',
       );
       </code>

Token:
 There are 8 pre-defined tokens for the webform data:
  * [data:data]
    This one prints out all data submitted by the webform in the following
    format:
    {form_key}: {label}: {value}
  * [data:data-raw]
    This one does exactly the same as [data:data] with the difference to not
    clean up the values using check_plain().
  * [data:{component}-title]
    This is a dynamic token. "{component}" is a placeholder for the components
    form key (machine readable name). Example: your webform has a component with
    the form key "email". So you would write [data:email-title] to use the title 
    (label) of this field.
  * [data:{component}-value]
    Same as [data:{component}-title], but it returns the value instead of the
    title.
  * [data:{component}-value-html]
    This one does exactly the same as [data:{component}-value] with the 
    difference that its output will be rendered as html.
  * [data:{component}-value-raw]
    This one does exactly the same as [data:{component}-value] with the 
    difference to not clean up the value using check_plain(). This is raw user
    input so take care if you use this somewhere else.
  * [data:{component}-display]
    Returns a combination of [data:{component}-title] and 
    [data:{component}-value] (done by module Webform).
  * [data:{component}-display-html]
    This one does exactly the same as [data:{component}-display] with the 
    difference that its output will be rendered as html.

Condition:
 Webform Rules adds a new condition to the rules configuration. With this
 condition you can tell rules to react only on one specific webform by selecting
 its title.


-- AUTHOR --

Stefan Borchert
http://drupal.org/user/36942
http://www.undpaul.de
