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
				<li class="active"><a href="Home.php">Home</a></li>
				<li><a href="#">Attendance Log</a></li>
				<li ><a href="Register.php">Register</a></li>
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



<div class="row" style="padding-left: 8px">
		<div class="col-md-8">
			<h1 class="page-header">Company Name</h1>
				<h1 class=" text-danger">Bootstrap</h1>
					<p class="text-justify text-capitalize">Build responsive, mobile-first projects on the web with the world’s most popular front-end component library. 
					Bootstrap is an open source toolkit for developing with HTML, CSS, and JS. Quickly prototype your ideas or build your entire app with our Sass variables and mixins, responsive grid system, extensive prebuilt components, and powerful plugins built on jQuery.
					Build responsive, mobile-first projects on the web with the world’s most popular front-end component library. 
					Bootstrap is an open source toolkit for developing with HTML, CSS, and JS. Quickly prototype your ideas or build your entire app with our Sass variables and mixins, responsive grid system, extensive prebuilt components, and powerful plugins built on jQuery. 
					</p>
		</div>
		<div class="col-md-4">
			<div class="panel-group">
				<div class="panel panel-default">
					<div class="panel-heading">
						<div class="panel-title">Gallery</div>
					</div>
					<div class="panel-body">
						<div id="myslide" class="carousel slide" data-ride="carousel">
						<ul class="carousel-indicators">
						<li class="active" data-target="#myslide" data-slide-to="0"></li>
							<li  data-target="#myslide" data-slide-to="1"></li>
							<li  data-target="#myslide" data-slide-to="2"></li>
								<li  data-target="#myslide" data-slide-to="3"></li>
				</ul>
		<div class="carousel-inner" >
			<div class="item active">
			<img src="Images/img2.jpg" class="img-responsive">
		</div>
		<div class="item ">
				<img src="Images/img2.jpg" class="img-responsive">
		</div>
		<div class="item ">
				<img src="Images/img2.jpg" class="img-responsive">
		</div>
		<div class="item ">
				<img src="Images/img2.jpg" class="img-responsive">
		</div>
	</div>
		 <!-- Left and right controls -->   
		<a class="left carousel-control" href="#myslide" data-slide="prev">     
			<span class="glyphicon glyphicon-chevron-left"></span>     
			  </a>   
		<a class="right carousel-control" href="#myslide" data-slide="next">     
			<span class="glyphicon glyphicon-chevron-right"></span> 
		</a>
	</div>
					</div>
					<div class="panel-footer">		
						<h3>More...</h3>
					</div>
					</div>
			</div>
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