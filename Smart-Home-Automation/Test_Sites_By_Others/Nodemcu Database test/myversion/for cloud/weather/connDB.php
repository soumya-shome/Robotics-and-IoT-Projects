<?php 
	$con =  new mysqli('localhost','id10804942_techie','xyz123');
	global $con;
	if(!$con){
		die ("Couldn't connect ".mysql_error());
	}
	mysqli_select_db($con,"id10804942_techie");
?>