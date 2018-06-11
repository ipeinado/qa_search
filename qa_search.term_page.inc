<?php

function qa_term_page($term) {
	$current_term = taxonomy_term_load($term);
	$current_term_id = $current_term->tid;
	$question = $current_term->field_qasearch_question['und'][0]['value'];
	$subterms = taxonomy_get_tree(11, $current_term_id, 1, TRUE);

	drupal_set_title($current_term->name);

	$total_url = _get_recursive_url($current_term);
	$total_nodes = _count_nodes_by_term($current_term->tid);

	$categories = array();
	
	foreach($subterms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content = array();

	$content['breadcrumb'] = $breadcrumb;

	$content['main_content'] = array(
		'#theme' => 'qa_search_term_page',
		'#total_url' => $total_url,
		'#total_nodes' => $total_nodes,
		'#question' => $question,
		'#categories' => $categories,
	);

	return $content;
}

function _build_breadcrumb($term) {
	$parents = taxonomy_get_parents_all($term->tid);
	$breadcrumb_array = array();
	$first_term = TRUE;

	foreach($parents as $parent) {
		$term_url = '/qa_search/' . $parent->tid;

		if ($first_term) {
			array_unshift($breadcrumb_array, $parent->name);
			$first_term = FALSE;
		} else {
			array_unshift($breadcrumb_array, l($parent->name, $term_url));
		}
		
	}
	array_unshift($breadcrumb_array, l('Question & Answer Search', '/qa_search'));

	return $breadcrumb_array;
}