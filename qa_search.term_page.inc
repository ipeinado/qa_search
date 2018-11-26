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

	$total_url = _get_recursive_url($current_term);
	$total_nodes = _count_nodes_by_term($current_term->tid);

	$categories = array();
	
	foreach($subterms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	// Add page breadcrumb
	// $breadcrumb = _build_breadcrumb($current_term);
	// $breadcrumb = array('something', 'other thing');
	// $content['breadcrumb'] = $breadcrumb;

	// Add page title
	drupal_set_title($current_term->name);

	// Add edit link if user can administer taxonomy
	if (user_access('administer taxonomy')) {
		$edit_link = l(t('Edit term'), '/taxonomy/term/' . $current_term->tid . '/edit', array('attributes' => array('class' => 'btn btn-success',), 'query' => array('destination' => '/qasearch/' . $current_term->tid,)));
	}

	// Add content
	$content['main_content'] = array(
		'#theme' => 'qa_search_term_page',
		'#edit_link' => $edit_link,
		'#total_url' => $total_url,
		'#total_nodes' => $total_nodes,
		'#question' => $question,
		'#categories' => $categories,
	);

	$node_count = count($nids);
	$nodes = node_load_multiple($nids);
	$others_title = t($node_count . ' products tagged only with "' . $current_term->name . '"');

	$content['nodes'] = array(
		'#theme' => 'qa_search_nodes',
		'#title' => $others_title,
		'#nodes' => $nodes,
	);

	return $content;
}