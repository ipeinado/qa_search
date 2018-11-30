<li class="<?php echo ($no_children ? 'no-children' : 'children') ?>" >
<a href="<?php echo $url; ?>">
<?php if ($node_count != 0): ?>
	<?php echo $term_name; ?></a> 
	(<?php echo $node_count; ?>)
	<?php if (!empty($short_description)): ?>
		- <?php echo $short_description; ?>
	<?php endif; ?>

	<?php if (isset($edit_term_link)): ?>
		<?php print $edit_term_link; ?>
	<?php endif; ?> 
<?php endif; ?> 
</li>