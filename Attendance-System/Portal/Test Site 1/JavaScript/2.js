// JavaScript Document
function validate(){
	var usern=document.f2.usr.value;
	var pass=document.f2.passwd.value;
	var choice=document.f1.r1.value;
	if(choice==="a"){
		if(usern!=="admin" && pass!=="12345"){
			alert("Login Successful");
		}	
		else{
			alert("Login Failed");
		}
	}
	if(choice==="s"){
		if(usern==="student" && pass==="123"){
			alert("Login Succesful");
		}
		else{
			alert("Login Failed");
		}
	}
}

function check() {
                var genders = document.getElementsByName("r1");
                if (r1[0].checked === true) {
                    alert("Admin");
                } else if (r1[1].checked === true) {
                    alert("Student");
                } else {
                    var msg = '<span style="color:red;">You have to Select a Option</span><br /><br />';
                    document.getElementById('msg').innerHTML = msg;
                    return false;
                }
                return true;
            }