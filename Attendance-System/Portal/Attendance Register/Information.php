<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Untitled Document</title>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>

<body>
<nav class="nav navbar-inverse">
	<div class="container-fluid">
		<div class="navbar-header" style="padding-top: 8px">
			<a  href="#"><img ></a>
				<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#mymenu">
			    	<span class="icon-bar"></span>         
					<span class="icon-bar"></span>     
					<span class="icon-bar"></span>    
				</button>
		</div>
		<div class="collapse navbar-collapse" id="mymenu">
			<ul class="nav navbar-nav">
				<li ><a href="index.php">Home</a></li>
				<li><a href="#">Attendance Log</a></li>
				<li ><a href="Register.php">Register</a></li>
				<li class="active"><a href="Information.php">Information</a></li>
				<li><a href="#">Settings</a></li>
			</ul>
		<div class="nav navbar-nav">
			
		</div>
		<ul class="nav navbar-nav navbar-right">
			<li>
				<form class="form-inline" style="padding-top: 8px">
				<div class="form-group">
				<input type="search" name="search" id="Search" placeholder="Search" class="form-control" s>
				<button type="submit" class="btn btn-default"><span class="glyphicon glyphicon-search"></span></button>
				</div>
				</form>
			</li>
			
			<li class="dropdown" ><a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="glyphicon glyphicon-log-in">	</span>&nbsp;Login</a>
			<ul class="dropdown-menu">
				<li ><a href="#" data-toggle="modal" data-target="#myLogin">Admin</a></li>
				<li ><a href="#" data-toggle="modal" data-target="#myLogin">Student</a></li>
			</ul>
		</li>
		</ul>
		</div>
	</div>	
</nav> 



<div class="row" style="padding-left: 8px">
		<div class="col-md-11">
			<?php
				
	require 'connectDB.php';
	$result=mysqli_query($con,"SELECT * FROM studentlog");
$count=mysqli_num_rows($result);
?>
<table border="1">
	<tr>
		<th>First Name</th>
		<th>Last Name</th>
		<th>Gender</th>
		<th>Email</th>
		<th>Password</th>
		<th>Date</th>
		<th>Course</th>
		<th>Phone Number</th>
		<th>Phone No. (P)</th>
		<th>Card Number</th>
	</tr>
	<?php
		while($row=mysqli_fetch_array($result)){
			$fname=$row[0];
	$lname=$row[1];
	$gender=$row[2];
	$email=$row[3];
	$pass=$row[4];
	$date=$row[5];
	$course=$row[6];
	$phone=$row[7];
	$phone2=$row[8];
	$cardno=$row[9];
	?>
	<tr>
		<td><?php echo $fname?></td>
		<td><?php echo $lname?></td>
		<td><?php echo $gender?></td>
		<td><?php echo $email?></td>
		<td><?php echo $pass?></td>
		<td><?php echo $date?></td>
		<td><?php echo $course?></td>
		<td><?php echo $phone?></td>
		<td><?php echo $phone2?></td>
		<td><?php echo $cardno?></td>
	</tr>
	<?php
		}
	?>
</table>
		</div>		
</div>

<div class="modal fade" role="dialog" id="myLogin">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button class="close" data-dismiss="modal">&times;</button>
				<h3 class="modal-title">Login</h3>
			</div>
			<div class="modal-body">
				<form class="form-horizontal" action="login.php">   
					<div class="form-group">     
						<label class="control-label col-sm-2" for="email">Username:</label>     
						<div class="col-sm-10">       
							<input type="text" class="form-control" id="email" placeholder="Enter Username">     
						</div>   
					</div>   
					<div class="form-group">     
						<label class="control-label col-sm-2" for="pwd">Password:</label>     
						<div class="col-sm-10">        
							<input type="password" class="form-control" id="pwd" placeholder="Enter Password">     
						</div>   
					</div>   
					<div class="form-group">      
						<div class="col-sm-offset-2 col-sm-10">       
							<div class="checkbox">         
								<label><input type="checkbox"> Remember me</label> 
							</div>     
						</div>   
					</div>   
					<div class="form-group">      
						<div class="col-sm-offset-2 col-sm-10">      
							<button type="submit" class="btn btn-default">Submit</button>    
						</div>   
					</div> 
				</form>
			</div>
		</div>
	</div>		
</div>
</body>
</html>