<?php if ($node_count > 0): ?>
<li>
<a href="<?php echo $url; ?>">
<?php echo $term_name; ?></a> 
(<?php echo $node_count; ?>)
<?php if (!empty($short_description)): ?>
	- <?php echo $short_description; ?>
<?php endif; ?>
<?php if (isset($edit_term_link)): ?>
	<?php print $edit_term_link; ?>
<?php endif; ?> 
</li>
<?php endif; ?> 