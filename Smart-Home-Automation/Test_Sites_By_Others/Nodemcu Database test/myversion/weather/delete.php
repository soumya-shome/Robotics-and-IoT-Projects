<?php
 
header('content-type: application/json; charset=utf-8');
header("access-control-allow-origin: *");

$response = array();

if (isset($_GET['id'])) {
    $id = $_GET['id'];
	
    require("connDB.php");
 
    $result = mysqli_query($con,"DELETE FROM weather WHERE id = $id");

    if (mysqli_affected_rows($con) > 0) {

        $response["success"] = 1;
        $response["message"] = "Data successfully deleted";

        echo json_encode($response);
    } else {

        $response["success"] = 0;
        $response["message"] = "No weather data found by given id";

        echo json_encode($response);
    }
} else {
    $response["success"] = 0;
    $response["message"] = "Parameter(s) are missing. Please check the request";

    echo json_encode($response);
}
?>