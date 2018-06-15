<?php
function qa_main_page() {

	$terms = taxonomy_get_tree(11, 0, 1, TRUE);

	$content = array();

	$intro_text = t('The Shopping Aid can help you find a wide range of products and services. Which type of product are you looking for?');

	$categories = array();

	foreach($terms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content[] = array(
		'#theme' => 'qa_search_main_page',
		'#intro_text' => $intro_text,
		'#categories' => $categories,
	);

	return $content;
}