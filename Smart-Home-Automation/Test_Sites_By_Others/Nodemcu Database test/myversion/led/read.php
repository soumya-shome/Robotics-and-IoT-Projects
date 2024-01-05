<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");


//Creating Array for JSON response
$response = array();
 
require 'connDB.php';

if(isset($_GET['id'])){
	$id=$_GET['id'];
	
	$result=mysqli_query($con,"SELECT * FROM led WHERE id= ".$id.";");
	if(!empty($result)){
		if (mysqli_num_rows($result) > 0) {
			$result=mysqli_fetch_array($result);
			
			
       		$led = array();
       		$led["id"] = $result["id"];
       		$led["status"] = $result["status"];
			
			$response["success"]=1;
			
			$response["led"]=array();
			
			array_push($response["led"], $led);
			
   			echo json_encode($response);
		}else {
			$response["success"] = 0;
    		$response["message"] = "No data on LED found";
			echo json_encode($response);
		}
	}
}
?>