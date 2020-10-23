#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <AFMotor.h>

String readString;
int bluetoothTx = A1; 
int bluetoothRx = A0; 
AF_DCMotor m1(1, MOTOR12_8KHZ);
AF_DCMotor m2(2, MOTOR12_8KHZ);

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600);
 bluetooth.begin(9600);
 m1.setSpeed(60);
 m2.setSpeed(60);
  m1.run (RELEASE);
     m2.run (RELEASE);
}

void loop()
{
   while(bluetooth.available()){
    delay(50);
    char c=bluetooth.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      m1.run (FORWARD);
     m2.run (FORWARD);
      delay(200);
    }
    if (readString =="BACKWARD"){
      m1.run (BACKWARD);
     m2.run (BACKWARD);
      delay(200);
    }
    if (readString =="LEFT"){
      m1.run (RELEASE);
     m2.run (FORWARD);
      delay(100);
      
    }
    if (readString =="RIGHT"){
      m1.run (FORWARD);
     m2.run (RELEASE);
      delay(100);
    }
    if (readString =="STOP"){
      m1.run (RELEASE);
     m2.run (RELEASE);
      delay(500);
    }

    readString="";
  }
}
