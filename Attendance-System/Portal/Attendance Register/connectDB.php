<?php 
	$con =  new mysqli('localhost','root','');
	global $con;
	if(!$con){
		die ("Couldn't connect ".mysql_error());
	}
	mysqli_select_db($con,"register");
	mysqli_query($con,"CREATE TABLE IF NOT EXISTS `studentlog`(`fname` varchar(40) NOT NULL,`lname` varchar(40) NOT NULL,`gender` char(1) NOT NULL,`email` varchar(45) NOT NULL,`password` varchar(20) NOT NULL,`date` date NOT NULL,`course` varchar(30) NOT NULL,`phone1` int(40) NOT NULL,`phone2` int(40) NOT NULL,`cardid` int(30) NOT NULL,PRIMARY KEY (`cardid`)) ENGINE=MyISAM DEFAULT CHARSET=latin1;");
?>