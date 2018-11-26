<p><?php echo $edit_link; ?></p>

<?php if(isset($question)): ?>
	<div class="question"><?php echo $question; ?></div>
<?php endif; ?>

<p><strong><a href="<?php echo $total_url; ?>"><?php print t('Show me everything below'); ?></a></strong> (<?php echo $total_nodes; ?>)</p>

<ul class="categories-list">
	<?php foreach($categories as $category): ?>
		<?php print $category; ?>
	<?php endforeach; ?>
</ul>