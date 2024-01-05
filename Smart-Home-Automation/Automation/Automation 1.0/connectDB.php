<?php
	$db_name="automation1";
	$db_user="root";
	$db_password="";
	$con = mysqli_connect('localhost',$db_user,$db_password);
	global $con;
	if(!$con){
		die ("Couldn't connect ".mysql_error());
	}
	
	mysqli_select_db($con,$db_name);
?>
