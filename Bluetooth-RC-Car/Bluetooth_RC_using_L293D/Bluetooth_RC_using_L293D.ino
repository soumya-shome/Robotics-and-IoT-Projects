#include<SoftwareSerial.h>
int motorPin1  = 12;
int motorPin2  = 13;
int motorPin3  = 6;
int motorPin4  = 5;

int bluetoothTx = A1; 
int bluetoothRx = A0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

String readString;

void setup(){
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   pinMode(motorPin3, OUTPUT);
   pinMode(motorPin4, OUTPUT);
   Serial.begin(9600);
   bluetooth.begin(9600);
}

void loop(){
  while(bluetooth.available()){
    delay(50);
    char c=bluetooth.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if(readString=="FORWARD")
    {
      front();
    }
    else if(readString=="BACKWARD")
    {
      back();
    }
    else if(readString=="LEFT")
    {
      left();
      Stop();
    }
    else if(readString=="RIGHT")
    {
      right();
      Stop();
    }
    else if(readString=="STOP")
      Stop();
    readString="";
   }
}

void front(){
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(200);
}

void back(){
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, HIGH);
  delay(200);
}

void left(){
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(200);
}

void right(){
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(200);
}

void Stop(){
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
