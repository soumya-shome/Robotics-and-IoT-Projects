
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
const int ir1=A0;

void setup() {
  pinMode(ir1,INPUT);
  Serial.begin(9600); 
  motor1.setSpeed(90);
  motor1.run(RELEASE);
  motor2.setSpeed(90);
  motor2.run(RELEASE);
}

void loop() {
int a=digitalRead(ir1);
Serial.print(a);
Serial.print(" ");
if(a==0)
{
 motor1.run(FORWARD);
 motor2.run(FORWARD);
}
else
{
  motor2.run(FORWARD);
  motor1.run(RELEASE);
}
}
