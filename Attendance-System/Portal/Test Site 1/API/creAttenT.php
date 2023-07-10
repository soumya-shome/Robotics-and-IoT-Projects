<?php
require("connectDB.php");
function isLeap($year)  
{  
    return (date('L', mktime(0, 0, 0, 1, 1, $year))==1);  
}
$date=date("M");
$m=date("m");
if($m==1 ||$m==3 ||$m==5 ||$m==7 ||$m==8 ||$m==10 ||$m==12){
	$days=31;
} else if($m==4 ||$m==6 ||$m==9 ||$m==11){
	$days=30;
} else if($m==2){
	if(isLeap(date("Y"))){
		$days=29;
	}
	else{
		$days=28;
	}
}
$q="CREATE TABLE IF NOT EXISTS `attend".$date.date("y")."` (`Name` varchar(50) NOT NULL,`CardNo` varchar(50) NOT NULL,";
for ($i=1;$i<=$days;$i++){
	$q=$q."`".$i."` varchar(5) NOT NULL,";
}
$q=$q."PRIMARY KEY (`CardNo`));";
mysqli_query($con,$q);
?>