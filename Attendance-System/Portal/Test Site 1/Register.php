<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Untitled Document</title>
</head>
<?php
$card=NULL;
if(isset($_REQUEST['b2'])){
	require("API/connectDB.php");
	$res=mysqli_query($con,"SELECT * FROM `tempcd`;");
	if($res){
		if($row=mysqli_fetch_array($res))
			$card=$row[0];
	}
	else{
		echo "Place card";
	}
}
if(isset($_REQUEST['b'])){
	require("API/connectDB.php");
	$q="CREATE TABLE IF NOT EXISTS `stuDetails` (`StuID` varchar(50) NOT NULL,`FName` varchar(50) NOT NULL,`LName` varchar(50) NOT NULL,`CardNo` varchar(50) NOT NULL,`Email` varchar(80) NOT NULL,`Password` varchar(50) NOT NULL,`Course` varchar(50) NOT NULL,`DOB` date NOT NULL,`Phone1` varchar(50) NOT NULL,`Phone2` varchar(50) NOT NULL , PRIMARY KEY (`CardNo`));";
	mysqli_query($con,$q);
	$resul=mysqli_query($con,"SELECT * FROM `stuDetails`;");
	$d=date("M");
	$y=date("y");
	$count=mysqli_num_rows($resul);
	$uid=1000+$count;
	$card=$_REQUEST['card'];
	$fname=$_REQUEST['nam1'];
	$lname=$_REQUEST['nam2'];
	$course=$_REQUEST['cour'];
	$email=$_REQUEST['emai'];
	$dob=$_REQUEST['dat'];
	$pass=$_REQUEST['pass'];
	$phone1=$_REQUEST['pno1'];
	$phone2=$_REQUEST['pno2'];
	echo $uid.",".$fname.",".$lname.",".$card.",".$email.",".$pass.",".$course.",".$dob.",".$phone1.",".$phone2;
	$result = mysqli_query($con,"INSERT INTO `stuDetails` (`StuID`,`FName`,`LName`,`CardNo`,`Email`,`Password`,`Course`,`DOB`,`Phone1`,`Phone2`) VALUES ('".$uid."','".$fname."','".$lname."','".$card."','".$email."','".$pass."','".$course."','".$dob."','".$phone1."','".$phone2."');"); 
	if(!$result){
		die (mysqli_error());
	}
	mysqli_query($con,"DROP TABLE IF EXISTS `tempcd`;");
}
?>
	
	
<body>
	<form method="post" name="f1" action="">
		<p>First Name<input type="text" name="nam1"></p>
		<p>Last Name<input type="text" name="nam2"></p>
		<p>Card Name<textarea name="card"><?php echo $card?></textarea><input type="SUBMIT" value="get card" name='b2'></p>
			
			<!--<input type="text" name="card" <div name="car" >
						</div><input type="button" value="get card" name='b2'>></p>
		--><p>Course<input type="text" name="cour"></p>
		<p>Email<input type="email" name="emai"></p>
		<p>Date of Birth<input type="date" name=dat></p>
		<p>Password<input type="password" name="pass"></p>
		<p>Phone no.<input type="number" name="pno1"></p>
		<p>Phone No 2<input type="number" name="pno2"></p>
		<p><input type="submit" name="b"> </p>
	</form>
</body>
</html>