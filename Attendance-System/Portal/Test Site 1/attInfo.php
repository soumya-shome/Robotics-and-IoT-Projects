<?php
require 'API/connectDB.php';
$result=mysqli_query($con,"SELECT * FROM `attend".date("M").date("y")."`");
$c=array();
while($row=mysqli_fetch_array($result)){
//$row=mysqli_fetch_array($result);
	for($i=0;$i<32;$i++){
		$c[$i]=$row[$i];
		echo $c[$i];
	}
	
	for($i=0;$i<32;$i++){
		//echo $i.$c[$i]."<br>";
	}
}
?>