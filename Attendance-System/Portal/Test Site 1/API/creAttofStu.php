<?php
require("connectDB.php");
require("creAttenT.php");
$result2=mysqli_query($con,"SELECT `FName`,`CardNo` FROM `stuDetails`;");
$row3=mysqli_num_rows($result2);
echo $row3;

	while($row2=mysqli_fetch_array($result2)){
		$q2="INSERT INTO `attend".date("M").date("y")."` (`Name`, `CardNo`,";
		for($i=1;$i<$days;$i++){
			$q2=$q2."`".$i."`,";
		}
		$q2=$q2."`".$days."`) VALUES ('".$row2[0]."', '".$row2[1]."',";
		for($i=1;$i<$days;$i++){
			$q2=$q2."'N',";
		}
		$q2=$q2."'N');";
		mysqli_query($con,$q2);
	}

?>