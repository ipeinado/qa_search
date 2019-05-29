<?php
function qa_term_page($term) {

	$current_term = taxonomy_term_load($term);
	$current_term_id = $current_term->tid;
	$question = $current_term->field_qasearch_question['und'][0]['value'];
	$question .= '<h2 class="question">' . $current_term->field_question_head['und'][0]['value'] . '</h2>';

	$subterms = taxonomy_get_tree(11, $current_term_id, 1, TRUE);

	$nids = taxonomy_select_nodes($current_term_id, FALSE);

	$exclude_terms = '';
	foreach($subterms as $term) {
		$subnids = taxonomy_select_nodes($term->tid, FALSE);
		$nids = array_diff($nids, $subnids);
		$exclude_terms .= '&field_product_categories1_1[]=' . $term->tid;
	}

	$total_url = '/guided-shopping-search?search_api_views_fulltext=&f[0]=field_product_categories1:' . $current_term->tid . '&field_product_categories1[]=' . $current_term->tid;
	$total_nodes = _count_nodes_by_term($current_term->tid);

	$categories = array();
	
	foreach($subterms as $term) {
		$categories[] = theme('category', array('term' => $term));
	}

	$node_count = count($nids);
	if ($node_count > 0) {
		$other = t('<li> <a href="/guided-shopping-search?search_api_views_fulltext=&f[0]=field_product_categories1:' . $current_term->tid . '&field_product_categories1[]=' . $current_term->tid . '&field_product_categories1[]=' . $current_term->tid . $exclude_terms . '">Other</a> (' . $node_count . ') - Products in the  "' . $current_term->name . '" category that do not fit into one or more of the categories above</li>');
	}
	

	// Add page title
	drupal_set_title($current_term->name);

	// Add edit link if user can administer taxonomy
	if (user_access('administer taxonomy')) {
		$edit_link = l(t('Edit term'), '/taxonomy/term/' . $current_term->tid . '/edit', array('attributes' => array('class' => 'btn btn-success',), 'query' => array('destination' => '/guided-shopping/' . $current_term->tid,)));
	}

	// // this is kludgy, but we failed to get the markup right in the data entry phase 
	// // @@ Propose a cleanup pass to strip these variations (what kind, what sort, accommodation vs. accommodations)
	
	// // find the last paragraph in the field
	// preg_match_all('#<p>.*</p>#',$question,$results);
	// $found_question = array_pop($results[0]);
	// // transform the paragraph into an h2
	// $orig = array('<p>', '</p>');
	// $new = array('<h2 class="guided">', '</h2>');
	// $formatted_question = str_replace($orig, $new, $found_question);

	// // swap the new h2 back into the field
	// $question = str_replace($found_question, $formatted_question, $question);

	// Add content
	$content['main_content'] = array(
		'#theme' => 'qa_search_term_page',
		'#edit_link' => $edit_link,
		'#total_url' => $total_url,
		'#total_nodes' => $total_nodes,
		'#question' => $question,
		'#categories' => $categories,
		'#other' => $other,
		'#term_name' => $current_term->name,
	);

	return $content;
}