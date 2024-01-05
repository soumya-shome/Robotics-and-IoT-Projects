<style>
.button {
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 150px 150px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
}

</style>
<?php
require 'connectDB.php';

if(isset($_REQUEST['b1'])){
	$id=$_REQUEST['b1'];
	$r1=mysqli_query($con,"SELECT * FROM `table1` WHERE `no`='".$id."'");
	$row1=mysqli_fetch_array($r1);
	if($row1[1]==1){
		mysqli_query($con,"UPDATE `table1` SET `status`=0 WHERE `no`='".$id."'");
	}
	else{
		mysqli_query($con,"UPDATE `table1` SET `status`=1 WHERE `no`='".$id."'");
	}
}




$r=mysqli_query($con,"SELECT * FROM `table1`");
?>
<form method="get" action="">
<?php
while($row=mysqli_fetch_array($r)){
	echo "No : ".$row[0]."<br>";
	$status=$row[1];
?>
	<button class="button" name="b1" value="<?php echo $row[0] ?>" type="submit"><?php echo $status ?></button><br>
<?php
}
?>
</form>