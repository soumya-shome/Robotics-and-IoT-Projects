<?php
if(isset($_REQUEST['b'])){
	require("connectDB.php");
	$q="CREATE TABLE IF NOT EXISTS `stuDetails` (`FName` varchar(50) NOT NULL,`LName` varchar(50) NOT NULL,`CardNo` varchar(50) NOT NULL,`Email` varchar(80) NOT NULL,`Password` varchar(50) NOT NULL,`Course` varchar(50) NOT NULL,`DOB` date NOT NULL,`Phone1` varchar(50) NOT NULL,`Phone2` varchar(50) NOT NULL , PRIMARY KEY (`CardNo`));";
	mysqli_query($con,$q);
	$d=date("M");
	$y=date("y");
	$card=$_REQUEST['card'];
	$fname=$_REQUEST['nam1'];
	$lname=$_REQUEST['nam2'];
	$course=$_REQUEST['cour'];
	$email=$_REQUEST['emai'];
	$dob=$_REQUEST['dat'];
	$pass=$_REQUEST['pass'];
	$phone1=$_REQUEST['pno1'];
	$phone2=$_REQUEST['pno2'];
	$result = mysqli_query($con,"INSERT INTO `stuDetails` (`FName`,`LName`,`CardNo`,`Email`,`Password`,`Course`,`DOB`,`Phone1`,`Phone2`) VALUES ('".$fname."','".$lname."','".$card."','".$email."','".$pass."','".$course."','".$dob."','".$phone1."','".$phone2."');");
}
?>