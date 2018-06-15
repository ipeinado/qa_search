<p><?php print $intro_text; ?></p>

<ul class="categories-list">
	<?php foreach($categories as $category): ?>
		<li>
			<?php print $category; ?>
		</li>
	<?php endforeach; ?>
</ul>