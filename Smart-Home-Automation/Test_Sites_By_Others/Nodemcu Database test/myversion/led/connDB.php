<?php 
	$con =  new mysqli('localhost','root','');
	global $con;
	if(!$con){
		die ("Couldn't connect ".mysql_error());
	}
	mysqli_select_db($con,"phpnodemcu");
?>