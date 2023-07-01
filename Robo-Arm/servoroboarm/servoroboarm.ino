#include <AFMotor.h>
#include <Servo.h>              
Servo myservoG,myservoJ,myservoB,myservoR;              

int servo_position = 0 ;
int t=0;

void setup() {
  Serial.begin(9600);
myservoR.attach (10);
myservoB.attach (9); 
myservoJ.attach (A0);
myservoG.attach (A1);  
}

void loop() {
while(Serial.available()){
    delay(50);
    int c=Serial.read();
    t=t*10 + c;
  }
if(t>1000 && t<1999)
{
  myservoR.write(t);
}
else if(t>2000 && t<2999)
{
  myservoB.write(t);
}
else if(t>3000 && t<3999)
{
  myservoJ.write(t);
}
else if(t>0 && t<200)
{
  myservoG.write(t);
}
t=0;
}

