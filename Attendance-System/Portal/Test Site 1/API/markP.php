<?php
if(isset($_REQUEST['b1'])){
	require("connectDB.php");
	require("creAttenT.php");
	$card=$_REQUEST['cd'];
	$result = mysqli_query($con,"SELECT `FName` FROM `stuDetails` WHERE `CardNo` = '".$card."'");
	$response["details"]=array();
	$row=mysqli_fetch_array($result);
	$det=array();
	$det["name"]=$row[0];
	if(mysqli_num_rows($result)>0){
		$det["name"]=$row[0];
		array_push($response["details"],$det);
		//table name=attendance<month>
		$result = mysqli_query($con,"UPDATE `attend".date("M").date("y")."` SET `CardNo` = '.$card.', `".date("j")."` = 'P' WHERE `attend".date("M").date("y")."`.`CardNo` = '".$card."'");
		if(!$result){
			echo "Failed";
		}
		$response["success"]=1;
		echo json_encode($response);
	}elseif(mysqli_num_rows($result)==0){
		
	}
	else{
		$response["success"] = 0;
		$response["message"] = "Card Not Found";
   		echo json_encode($response);
	}	
}
?>