#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);

int bluetoothTx = A1; 
int bluetoothRx = A0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

String readString;

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  
  motor1.run (RELEASE);
  motor2.run (RELEASE);
}

void loop(){
  while(bluetooth.available()){
    delay(50);
    char c=bluetooth.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD")
      forward();
    if (readString =="BACKWARD")
      back();
    if (readString =="LEFT")
      left();
    if (readString =="RIGHT")
      right();
    if (readString =="STOP")
      Stop();
    readString="";
  }
}

void forward(){
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}
void back(){
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}
void left(){
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}
void right(){
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}
void Stop(){
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}
