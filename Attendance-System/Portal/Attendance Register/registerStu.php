<?php 
	require("connectDB.php");

	$fname=$_REQUEST['fname'];
	$lname=$_REQUEST['lname'];
	$gender=$_REQUEST['gender'];
	$email=$_REQUEST['email1'];
	$pass=$_REQUEST['pass'];
	$date=$_REQUEST['date1'];
	$course=$_REQUEST['course'];
	$phone=$_REQUEST['phone'];
	$phone2=$_REQUEST['phone2'];
	$cardno=$_REQUEST['cardno'];
	
	$q="INSERT INTO `studentlog` (`fname`, `lname`, `gender`, `email`, `password`, `date`, `course`, `phone1`, `phone2`, `cardid`) VALUES ('".$fname."', '".$lname."', '".$gender."', '".$email."', '".$pass."' , '2019-09-03','".$course."' , ".$phone." , ".$phone2." , ".$cardno.");";
	$r=mysqli_query($con,$q);
header("Refresh:2,URL=Information.php");
			echo "Inserted Successfully wait 2 secs..";
	if(!$r){
		echo("data insertion failed");
		die(mysqli_error());
	}
	

?>