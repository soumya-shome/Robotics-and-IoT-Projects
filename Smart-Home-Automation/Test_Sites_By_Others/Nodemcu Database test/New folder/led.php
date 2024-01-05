<!doctype html>
<html>
<head>
	<meta charset="utf-8">
	<title>ESP8266</title>
</head>

<body>
	
	<button id="l1" class="led">LED 1</button>
	<button id="l2" class="led">LED 2</button>
	<button id="l3" class="led">LED 3</button>
	
	<script src="jquery.min.js"></script>
	<script type="text/javascript">
		$(document).ready(function(){
			$(".led").click(function(){
				var p=$(this).attr('id');
				$.get("http//192.168.4.1:80/",(pin:p));
				<?php
				echo ?>(pin:p)<?php;
				?>
			});
		});
	</script>
</body>
</html>