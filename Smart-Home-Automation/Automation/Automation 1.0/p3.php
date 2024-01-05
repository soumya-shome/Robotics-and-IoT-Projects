<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");


//Creating Array for JSON response
$response = array();
 
require 'connectDB.php';

$result=mysqli_query($con,"SELECT * FROM `table1`");
if(!empty($result)){
	if (mysqli_num_rows($result) > 0) {
		$response["success"]=1;
		$response["no"]=array();
		$response["status"]=array();
		$total=0;
		while($r=mysqli_fetch_array($result)){
			array_push($response["no"],(int)$r[0]);
			array_push($response["status"],(int)$r[1]);
			$total=$total+1;
		}
		$response["tot"]=$total;
		echo json_encode($response);
	}else {
		$response["success"] = 0;
   		$response["message"] = "No data on LED found";
		echo json_encode($response);
	}
}
?>