<div class="question"><?php echo $question; ?></div>

<p><a href="<?php echo $total_url; ?>"><?php print t('Show me everything below'); ?></a> (<?php echo $total_nodes; ?>)</p>

<ul class="categories-list">
	<?php foreach($categories as $category): ?>
		<li><?php print $category; ?></li>
	<?php endforeach; ?>
</ul>