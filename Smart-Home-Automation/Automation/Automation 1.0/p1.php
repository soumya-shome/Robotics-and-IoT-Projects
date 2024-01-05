<?php
/*require("connectDB.php");
if(isset($_GET['id'])){
	$led=$_GET['id'];
	$r=mysqli_query($con,"SELECT `status` FROM `table1` WHERE `no`='".$led."'");
	$a=mysqli_fetch_array($r);
	echo $a[0];
}*/
?>
<?php
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");


//Creating Array for JSON response
$response = array();
 
require 'connectDB.php';

if(isset($_GET['id'])){
	$id=$_GET['id'];
	$result=mysqli_query($con,"SELECT * FROM `table1` WHERE `no`= ".$id.";");
	if(!empty($result)){
		if (mysqli_num_rows($result) > 0) {
			$result=mysqli_fetch_array($result);
			
			
       		$led = array();
       		$led["id"] = $result["no"];
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