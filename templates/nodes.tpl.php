<h2 style="font-size: 1rem;"><?php echo $title; ?></h2>
<ul>
<?php foreach($nodes as $node): ?>
	<li>
		<a href="/node/<?php echo $node->nid; ?>"><?php echo $node->title; ?></a>
	</li>
<?php endforeach; ?>
</ul>