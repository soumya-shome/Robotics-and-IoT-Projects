#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo myServoBa,myServoGr,myServoJ,myServoP;               // Define any servo name

int servo_position = 0 ;

void setup() {
  
myServoBa.attach (9);          // Define the servo signal pins
myServoGr.attach (10); 
myServoJ.attach(A0);
myServoP.attach (A1);
 Serial.begin (9600);
}

void loop() {
myServoBa.write(125);
myServoGr.write(130);
myServoJ.write(120);
delay(1000);
down(0);
/*Serial.println("Catching");
grab(0);
Serial.println("Rotating");
rot(1);
Serial.println("downining");
down(0);
Serial.println("Releasing");
grab(1);


rot(2);*/
down(1);
}


void down(int j)
{
  if(j==0)
  {
    for(int i=75;i<=120;i++){  
    myServoBa.write(i);
    delay(15);
    }
  }

  else if(j==1)
  {
    for(int i=120;i>=75;i--){  
    myServoBa.write(i);
    delay(30);
    }
  }
}
/*
void grab(int k)
{
    for(int i=30;i>=0;i--){  
    myServoA.write(i);
    Serial.println(i);
    delay(30);
    }
  if(k==0)
  {
    myServoP.write(50);
  }
  else if(k==1)
  {
    myServoP.write(0);
  }
    for(int i=0;i<=30;i++){  
    myServoA.write(i);
    Serial.println(i);
    delay(30);
    }
}

void rot(int i)
{
  if(i==1)
  {
    for(int i=180;i>=90;i--){  
    myServoBASE.write(i);
    delay(30);
    }
  }
  else if(i==2)
  {
    for(int i=90;i<=180;i++){  
    myServoBASE.write(i);
    Serial.println(i);
    delay(30);
    }
  }
  */



  

