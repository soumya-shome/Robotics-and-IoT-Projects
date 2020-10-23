#include <AFMotor.h>
AF_DCMotor front_motor(1, MOTOR12_8KHZ);
AF_DCMotor aft_motor(2, MOTOR12_8KHZ);

String readString;

void setup() {
  Serial.begin(9600);
  front_motor.setSpeed(250);
  aft_motor.setSpeed(250);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      aft_motor.run (FORWARD);
      front_motor.run (RELEASE);
      delay(500);
    }
    if (readString =="BACKWARD"){
      aft_motor.run (BACKWARD);
      front_motor.run (RELEASE);
      delay(500);
    }
    if (readString =="LEFT"){
      front_motor.run (FORWARD);
      aft_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="RIGHT"){
      front_motor.run (BACKWARD);
      aft_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP"){
      front_motor.run (RELEASE);
      aft_motor.run (RELEASE);
      delay(500);
    }

    readString="";
  }
}

