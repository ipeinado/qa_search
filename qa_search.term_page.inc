<?php

function qa_term_page($term) {
	$current_term = taxonomy_term_load($term);
	$current_term_id = $current_term->tid;
	$question = $current_term->field_qasearch_question['und'][0]['value'];
	$subterms = taxonomy_get_tree(11, $current_term_id, 1, TRUE);

	drupal_set_title($current_term->name);

	$content = array();

	$link = '<a href="' . _get_recursive_url($current_term) . '">' . t('Show me everything below') . '</a>';
	$link .= ' (' . _count_nodes_by_term($current_term->tid) . ')';

	$breadcrumb_array = _build_breadcrumb($current_term);

	$content['breadcrumb'] = array(
		'#theme' => 'item_list', 
		'#items' => $breadcrumb_array,
		'#type' => 'ol',
		'#attributes' => array(
			'class' => 'breadcrumb',
		),
	);

	$content['question'] = array(
		'#type' => 'markup',
		'#markup' => $question,
		'#prefix' => '<div>',
		'#suffix' => '</div>',
	);

	$content['show_everything'] = array(
		'#type' =>'markup',
		'#markup' => $link,
		'#prefix' => '<p>',
		'#suffix' => '</p>',  
	);

	$categories = array();
	
	foreach($subterms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$content['categories_list'] = array(
		'#theme' => 'item_list',
		'#items' => $categories,
	);

	return $content;
}

function _build_breadcrumb($term) {
	$parents = taxonomy_get_parents_all($term->tid);
	$breadcrumb_array = array();
	$first_term = TRUE;

	foreach($parents as $parent) {
		$term_url = '/mytest/qa_search/' . $parent->tid;

		if ($first_term) {
			array_unshift($breadcrumb_array, $parent->name);
			$first_term = FALSE;
		} else {
			array_unshift($breadcrumb_array, l($parent->name, $term_url));
		}
		
	}
	array_unshift($breadcrumb_array, l('Question & Answer Search', '/mytest/qa_search'));

	return $breadcrumb_array;
}