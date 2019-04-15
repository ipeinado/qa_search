<p><?php echo $edit_link; ?></p>

<?php if(isset($question)): ?>
	<div class="question"><?php echo $question; ?></div>
<?php endif; ?>

<p class="showall"><strong><a href="<?php echo $total_url; ?>"><?php print t('Show all products in the ' . $term_name . ' category'); ?></a></strong> (<?php print $total_nodes ?>)</p>

<ul class="categories-list">
	<?php foreach($categories as $category): ?>
		<?php print $category; ?>
	<?php endforeach; ?>
	<?php print $other; ?>
</ul>