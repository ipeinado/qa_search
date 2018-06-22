<?php

function qa_term_page($term) {

	$current_term = taxonomy_term_load($term);
	$current_term_id = $current_term->tid;
	$question = $current_term->field_qasearch_question['und'][0]['value'];
	$subterms = taxonomy_get_tree(11, $current_term_id, 1, TRUE);

	$nids = taxonomy_select_nodes($current_term_id, FALSE);

	foreach($subterms as $term) {
		$subnids = taxonomy_select_nodes($term->tid, FALSE);
		$nids = array_diff($nids, $subnids);
	}

	drupal_set_title($current_term->name);

	$total_url = _get_recursive_url($current_term);
	$total_nodes = _count_nodes_by_term($current_term->tid);

	$categories = array();
	
	foreach($subterms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content = array();

	$breadcrumb = _build_breadcrumb($current_term);
	$content['breadcrumb'] = $breadcrumb;

	if (user_access('administer taxonomy')) {
		$edit_link = l(t('Edit term'), '/taxonomy/term/' . $current_term->tid . '/edit', array('attributes' => array('class' => 'btn btn-default',), 'query' => array('destination' => '/qasearch/' . $current_term->tid,)));
	}

	$content['main_content'] = array(
		'#theme' => 'qa_search_term_page',
		'#edit_link' => $edit_link,
		'#total_url' => $total_url,
		'#total_nodes' => $total_nodes,
		'#question' => $question,
		'#categories' => $categories,
	);

	$nodes_count = count($nids);
	$nodes = node_load_multiple($nids);
	$others_title = t($nodes_count . ' products tagged only with "' . $current_term->name . '"');

	$content['nodes'] = array(
		'#theme' => 'qa_search_nodes',
		'#title' => $others_title,
		'#nodes' => $nodes,
	);

	return $content;
}

function _build_breadcrumb($term) {
	$parents = taxonomy_get_parents_all($term->tid);
	$breadcrumb_array = array();
	$first_term = TRUE;

	foreach($parents as $parent) {
		$term_url = '/qasearch/' . $parent->tid;

		if ($first_term) {
			array_unshift($breadcrumb_array, $parent->name);
			$first_term = FALSE;
		} else {
			array_unshift($breadcrumb_array, l($parent->name, $term_url));
		}
		
	}
	array_unshift($breadcrumb_array, l('Question & Answer Search', '/qasearch'));

	return $breadcrumb_array;
}