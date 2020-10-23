#include<AFMotor.h>
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

String readString;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if(readString=="FORWARD")
    {
      forward();
    }
    if(readString=="BACKWARD")
    {
      backward();
    }
    if(readString=="LEFT")
    {
      left();
    }
    if(readString=="RIGHT");
    {
      right();
    }
    if(readString=="STOP")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
    readString="";
   }
}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void left()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(10);
}

void right()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(10);
}
