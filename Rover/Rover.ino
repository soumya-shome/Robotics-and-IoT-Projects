#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Servo.h> // servo library 
// int motorPin1  = 3;
// int motorPin2  = 4;
// int motorPin3  = 7;
// int motorPin4  = 8;
Servo myservo1, myservo2, myservo3, myservo4; // servo name
int bluetoothTx = A1; 
int bluetoothRx = A0;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// String readString;


// void setup(){
//    pinMode(motorPin1, OUTPUT);
//    pinMode(motorPin2, OUTPUT);
//    pinMode(motorPin3, OUTPUT);
//    pinMode(motorPin4, OUTPUT);
//    Serial.begin(9600);
//    bluetooth.begin(9600);
// }

// void loop(){
//   while(bluetooth.available()){
//     delay(50);
//     char c=bluetooth.read();
//     readString+=c;
//   }
//   if(readString.length()>0){
//     Serial.println(readString);
//     if(readString=="FORWARD")
//     {
//       front();
//     }
//     else if(readString=="BACKWARD")
//     {
//       back();
//     }
//     else if(readString=="LEFT")
//     {
//       left();
//       Stop();
//     }
//     else if(readString=="RIGHT")
//     {
//       right();
//       Stop();
//     }
//     else if(readString=="STOP")
//       Stop();
//     readString="";
//    }
// }

// void front(){
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, HIGH);
//   delay(200);
// }

// void back(){
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin4, LOW);
//   digitalWrite(motorPin3, HIGH);
//   delay(200);
// }

// void left(){
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, LOW);
//   delay(200);
// }

// void right(){
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, HIGH);
//   delay(200);
// }

// void Stop(){
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, LOW);
// }



void setup()
{
  myservo1.attach(5); // attach servo signal wire to pin 9
  myservo2.attach(6);
  myservo3.attach(9);
  myservo4.attach(10);
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 180, 0);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(10);
    }
  }
}
