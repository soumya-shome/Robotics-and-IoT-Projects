<?php
	require 'API/connectDB.php';
	$result=mysqli_query($con,"SELECT * FROM `stuDetails`");
$count=mysqli_num_rows($result);
echo $count;
?>
<table border="1">
	<tr>
		<th>FName</th>
		<th>LRoll</th>
		<th>CardNO</th>
		<th>email</th>
		<th>Password</th>
		<th>Course</th>
		<th>DOB</th>
		<th>Phone1</th>
		<th>Phone2</th>
	</tr>
	<?php
		while($row=mysqli_fetch_array($result)){
			$fname=$row[0];
			$lname=$row[1];
			$card=$row[2];
			$email=$row[3];
			$pass=$row[4];
			$course=$row[5];
			$dob=$row[6];
			$phone=$row[7];
			$phone1=$row[8];
	?>
	<tr>
		<td><?php echo $fname?></td>
		<td><?php echo $lname?></td>
		<td><?php echo $card?></td>
		<td><?php echo $email?></td>
		<td><?php echo $pass?></td>
		<td><?php echo $course?></td>
		<td><?php echo $dob?></td>
		<td><?php echo $phone?></td>
		<td><?php echo $phone1?></td>
	</tr>
	<?php
		}
	?>
</table>