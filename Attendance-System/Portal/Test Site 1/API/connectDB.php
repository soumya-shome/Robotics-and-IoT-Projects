<?php
	$db_name="attendance_log";
	$db_user="root";
	$db_password="";
	$con =  new mysqli('localhost',$db_user,$db_password);
	global $con;
	if(!$con){
		die ("Couldn't connect ".mysql_error());
	}
	mysqli_select_db($con,$db_name);
?>