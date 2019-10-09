<?php
function qa_main_page() {

	$terms = taxonomy_get_tree(11, 0, 1, TRUE);

	$content = array();

	$categories = array();

	foreach($terms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content[] = array(
		'#theme' => 'qa_search_main_page',
		'#categories' => $categories,
	);

	return $content;
}