<p><?php echo $edit_link; ?></p>

<?php if(isset($question)): ?>
	<div class="question"><?php echo $question; ?></div>
<?php endif; ?>

<p><a href="<?php echo $total_url; ?>"><?php print t('Show me everything below'); ?></a> (<?php echo $total_nodes; ?>)</p>

<ul class="categories-list">
	<?php foreach($categories as $category): ?>
		<li>
			<?php print $category; ?>
		</li>
	<?php endforeach; ?>
</ul>