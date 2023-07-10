// JavaScript Document
function validate(){
	var mail=document.r1.mail.value;
	var at=mail.indexOf("@");// first index number
	var dot=mail.lastIndexOf(".");// last index no
	if(at<=0 ||( dot - at <=2)){
		alert("Please enter proper email with @ & .");
		document.f1.email.focus();
		return false;		
	}
	
	
	
}