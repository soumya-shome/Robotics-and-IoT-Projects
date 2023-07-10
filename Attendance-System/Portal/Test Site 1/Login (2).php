<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Register</title>
<link href="CSS/1.css" rel="stylesheet" type="text/css">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<script src="JavaScript/2.js"></script>
</head>

<body>
<div class="row">
	<div class="col-2"></div>
    <div class="col-10 title">Attendance Register</div>
</div>

<div class="row">
	<a href="home.php"><div class="col-3 menu-items">Home</div></a>
    <div class="col-3 menu-items">Attendance Log</div>
	<a href="register.php"><div class="col-3 menu-items">Register</div></a>
	<a href="Login.php"><div class="col-3 menu-items">Admin Login</div></a>
</div>

<div class="row">
	<div class="col-6">
		<fieldset class="register">
			<legend align="center">Admin/Student</legend>
				<form name="f1" method="post" onSubmit="check()">
					<p>Admin</p>
					<input type="radio" name="r1" value="a">
					<p>Student</p>
					<input type="radio" name="r1" value="s">
					<input type="submit">
				</form>
		</fieldset> 
		<form name="f3" method="post" >
		
		</form>
	</div>
	<div class="col-6">
		<fieldset class="register">
    		<legend align="center">Log-In</legend>
    			<form name="f2" method="post" onSubmit="validate()">
    				<p>UserName</p>
    				<input type="text" name="usr">
    				<p>Password</p>
    				<input type="password" name="passwd">
    				<br><br>
    				<input type="submit"> <input type="reset" value="Clear">
    			</form>
		</fieldset>
	</div>
</div>
</body>
</html>