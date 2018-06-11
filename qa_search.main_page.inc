<?php
function qa_main_page() {

	$terms = taxonomy_get_tree(11, 0, 1, TRUE);

	$content = array();

	$content['intro_text'] = array(
		'#type' => 'markup',
		'#markup' => t('The Shopping Aid can help you find a wide range of products and services. Which type of product are you looking for?'),
		'#prefix' => '<p>',
		'#suffix' => '</p>',
	);

	$categories = array();

	foreach($terms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content['categories_list'] = array(
		'#theme' => 'item_list',
		'#items' => $categories,
	);

	return $content;
}