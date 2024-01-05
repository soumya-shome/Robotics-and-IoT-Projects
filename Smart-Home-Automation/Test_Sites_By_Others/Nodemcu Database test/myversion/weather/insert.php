<?php

header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");

//Creating Array for JSON response
$response = array();
 
// Check if we got the field from the user
if (isset($_REQUEST['temp']) & isset($_REQUEST['hum'])) {
 
    $temp = $_GET['temp'];
    $hum = $_GET['hum'];
	require 'connDB.php';
 
    // Fire SQL query to insert data in weather
    $result = mysqli_query($con,"INSERT INTO weather(temp,hum) VALUES('$temp','$hum')");
 
    if ($result) {
        $response["success"] = 1;
        $response["message"] = "Weather successfully created.";
		
        echo json_encode($response);
    } else {
        $response["success"] = 0;
        $response["message"] = "Something has been wrong";
 
        echo json_encode($response);
    }
}else {
    // If required parameter is missing
    $response["success"] = 0;
    $response["message"] = "Parameter(s) are missing. Please check the request";
 
    // Show JSON response
    echo json_encode($response);
}
?>
