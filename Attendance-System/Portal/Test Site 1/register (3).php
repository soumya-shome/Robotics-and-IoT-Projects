<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Untitled Document</title>

<link href="CSS/1.css" rel="stylesheet" type="text/css">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<script src="JavaScript/1.js"></script>
</head>

<body>

<div class="row">
	<div class="col-2"></div>
    <div class="col-10 title">Attendance Register</div>
</div>

<div class="row">
	<a href="home.php"><div class="col-3 menu-items">Home</div></a>
    <a href="Log.php"><div class="col-3 menu-items">Attendance Log</div></a>
	<a href="register.php"><div class="col-3 menu-items">Register</div></a>
	<a href="Login.php"><div class="col-3 menu-items">Admin Login</div></a>
</div>

<div class="row">
	<div class="col-6" align="center"><br></div>
    <div class="col-6">
    <fieldset class="register">
    <legend align="center">Register</legend>

   	<form name="r1" method="post" onSubmit="validate()">
		<p>First Name</p>
		<input type="text" name="nam" placeholder="Enter First Name">
		<p>Last Name</p>
		<input type="text" name="nam" placeholder="Enter Last Name" >
		<p>Gender</p>
		<input type="radio" name="r1">Male <input type="radio" name="r1">Female <input type="radio" name="r1">Others
		<p>Date of Birth</p>
		<input type="date" name="dob" >
		<p>Address</p>
		<textarea rows="3" name="address" placeholder="Enter Address"></textarea>
		<p>Email-ID</p>
		<input type="email" name="mail" placeholder="Enter Email" >
		<p>Phone-No</p>
		<input type="number" maxlength="10" placeholder="Enter Phone number">
		<p>Secondary Phone-No (optional)</p>
		<input type="number" maxlength="10" placeholder="Enter Phone number">
		<p>Card ID</p>
		<input type="text" placeholder="Enter Card ID"><input type="button" name="uid" value="Get U">
		<p>Course</p>
		<select name="course" >
			<option value="0">---Select Course---</option>
				<optgroup label="School">
					<option value="1">Class 8</option>
					<option value="2">Class 9</option>
					<option value="3">Class 10</option>
					<option value="4">Class 11</option>
					<option value="5">Class 12</option>
				</optgroup>
				<optgroup label="Professional">
					<option value="6">Web Designing</option>
					<option value="7">Data base</option>
					<option value="8">MultiMedia</option>
				</optgroup>
		</select>
		
		<br><br><input type="submit" name="b1">
		<input type="reset" value="Clear">
		</form>
</fieldset>
</div>
</div>
</body>
</html>
