<?php
if(isset($_REQUEST['b1'])){
	require("connectDB.php");
	mysqli_query($con,"DROP TABLE IF EXISTS `tempcd`;");
	mysqli_query($con,"CREATE TABLE IF NOT EXISTS `tempcd` (`CardNo` varchar(50) NOT NULL);");
	$card=$_REQUEST['cd'];
	$result = mysqli_query($con,"INSERT INTO `tempcd` (`CardNo`) VALUES ('".$card."');");
}
?>