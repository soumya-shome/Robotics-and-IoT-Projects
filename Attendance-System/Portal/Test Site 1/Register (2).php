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
				<li><a href="Home.php">Home</a></li>
				<li><a href="#">Attendance Log</a></li>
				<li class="active"><a href="Register.php">Register</a></li>
				<li><a href="#">Information</a></li>
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
	
	<div class="row" style="padding-left: 2%">
		<div class="col-md-5">
			<h1 class="page-header">Registration</h1>
			<form>
				<div class="form-group row">
				<label for="Name1" class="col-sm-2 col-form-label">First Name</label>
				<div class="col-sm-10">
					<input type="text" class="form-control" id="Name1" placeholder="First Name">
				</div>
			</div>
				<div class="form-group row">
				<label for="Name2" class="col-sm-2 col-form-label">Last Name</label>
				<div class="col-sm-10">
					<input type="text" class="form-control" id="Name2" placeholder="Last Name">
				</div>
			</div>
			
			<fieldset class="form-group">
			<div class="row">
				<label for="inputEmail3" class="col-sm-2 col-form-label">Gender</label>
				<div class="col-sm-2">
					<div class="form-check">
						<input class="form-check-input" type="radio" name="gridRadios" id="male" value="option1">
						<label class="form-check-label" for="male">Male</label>
					</div>
				</div>
				<div class="col-sm-2">
					<div class="form-check">
						<input class="form-check-input" type="radio" name="gridRadios" id="female" value="option2">
						<label class="form-check-label" for="female">Female</label>
					</div>
				</div>
				<div class="col-sm-2">
					<div class="form-check">
						<input class="form-check-input" type="radio" name="gridRadios" id="others" value="option2">
						<label class="form-check-label" for="others">Others</label>
					</div>
				</div>
			</div>
			</fieldset>
				
			<div class="form-group row">
				<label for="Email1" class="col-sm-2 col-form-label">Email</label>
				<div class="col-sm-10">
					<input type="email" class="form-control" id="Email1" placeholder="Email">
				</div>
			</div>
			<div class="form-group row">
				<label for="pass" class="col-sm-2 col-form-label">Password</label>
				<div class="col-sm-10">
					<input type="password" class="form-control" id="pass" placeholder="Password">
				</div>
			</div>
			<div class="form-group row" style="padding-left: 20%">
        		<input class="form-check-input" type="checkbox" id="gridCheck1">
        		<label class="form-check-label" for="gridCheck1">
          			Show Password
        		</label>
      		</div>
				
			<div class="form-group row">
  				<label for="date1" class="col-sm-2 col-form-label">Date</label>
				<div class="col-sm-10">
    				<input class="form-control" type="date" value="yyyy-mm-dd" id="date1">
  				</div>
			</div>
			
			<div class="form-group row">
  				<label for="course" class="col-sm-2 col-form-label">Course</label>
				<div class="col-sm-10">
    				<select id="course" class="form-control">
        			<option selected>Choose...</option>
        			<option>...</option>
      				</select>
  				</div>
			</div>
      				
			
			<div class="form-group row">
  				<label for="phone" class="col-sm-2 col-form-label">Phone No.</label>
				<div class="col-sm-10">
    				<input class="form-control" type="tel" value="Phone Number" id="phone">
  				</div>
			</div>
			
			<div class="form-group row">
  				<label for="phone2" class="col-sm-2 col-form-label">Phone No. (Secondary)</label>
				<div class="col-sm-10">
    				<input class="form-control" type="tel" value="Phone Number" id="phone2">
  				</div>
			</div>
			<div class="form-group row">
  				<label for="card" class="col-sm-2 col-form-label" disabled>Card No.</label>
				<div class="col-sm-8">
    				<input class="form-control" type="text" value="Card No." id="cardno">
				</div>
				<div class="col-sm-2">
					<button class="btn btn-default" id="getcard">Get ID</button>
				</div>
			</div>
				
 			<div class="form-group row">
    			<div class="col-sm-10">
      			<button type="submit" class="btn btn-primary">Register</button>
    		</div>
  </div>
</form>
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