<?php

/**
 * Implementation of hook_default_filefield_paths().
 */
function anaheimoc_blog_article_default_filefield_paths() {
  $settings = array();

  // Exported blog_article-field_anaheimoc_page_hero_image
  $settings['blog_article-field_anaheimoc_page_hero_image'] = array(
    'type' => 'blog_article',
    'field' => 'field_anaheimoc_page_hero_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/hero',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );
  // Exported blog_article-field_article_image
  $settings['blog_article-field_article_image'] = array(
    'type' => 'blog_article',
    'field' => 'field_article_image',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/image',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );
  // Exported blog_article-field_article_image_additional
  $settings['blog_article-field_article_image_additional'] = array(
    'type' => 'blog_article',
    'field' => 'field_article_image_additional',
    'filename' => array(
      'value' => '[filefield-onlyname-original].[filefield-extension-original]',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
    'filepath' => array(
      'value' => 'assets/[type]/[nid]/images',
      'tolower' => 0,
      'pathauto' => 0,
      'transliterate' => 0,
    ),
  );

  return $settings;
}
