<?php

/**
 * Implementation of hook_node_info().
 */
function anaheimoc_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'module' => 'features',
      'description' => t('The <em><strong>Article</strong></em> content type is a child of the <em><strong>Feature Article</strong></em> content type.  Articles are directly attached to Feature Article nodes. The Article content type provides supplemental information and enhances the depth of information of a Feature Article.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
