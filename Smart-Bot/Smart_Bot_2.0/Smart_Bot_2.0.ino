#include <SoftwareSerial.h>
#include<Servo.h>
#define ledon 12
#define ledoff 13
#define button 11
int r1 = 9;
int r2 = 10;
int l1 = 6;
int l2 = 5;
const int trigPin = 7;
const int echoPin = 8;
int bluetoothTx = 0;
int bluetoothRx = 1;
int s1,s2,s3,s4,s5,s6,s7,s8;
int error=0;

Servo s;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
long duration;
int distance;
String readString;
int a = 1, b = 0, o, d1, d2;

void setup() {
  s.attach(3);
  pinMode(button, INPUT_PULLUP);
  pinMode(ledon, OUTPUT);
  pinMode(ledoff, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void readsensors()
{
  s1=digitalRead(A5);
  s2=digitalRead(A4);
  s3=digitalRead(A3);
  s4=digitalRead(A2);
  s5=digitalRead(A1);
  s6=digitalRead(A0);
  s7=digitalRead(6);
  s8=digitalRead(7);
}

void forward() {
  digitalWrite(r1, 1);
  digitalWrite(r2, 0);
  digitalWrite(l1, 1);
  digitalWrite(l2, 0);
}
void backward() {
  digitalWrite(r1, 0);
  digitalWrite(r2, 1);
  digitalWrite(l1, 0);
  digitalWrite(l2, 1);
}

void left() {
  digitalWrite(r1, 1);
  digitalWrite(r2, 0);
  digitalWrite(l1, 0);
  digitalWrite(l2, 0);
}

void right() {
  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(l1, 1);
  digitalWrite(l2, 0);
}

void brake() {
  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(l1, 0);
  digitalWrite(l2, 0);
}

void dist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}

int clearance() {
  delay(250);
  s.write(145);
  delay(200);
  dist();
  d1 = distance;
  delay(250);
  s.write(45);
  delay(200);
  dist();
  d2 = distance;
  Serial.println(d2);
  delay(500);
  if (d1 > d2)
    return 1;
  else
    return 2;
}

int obstacle() {
  dist();
  if (distance <= 20)
  {
    brake();
    delay(250);
    backward();
    delay(500);
    brake();
    delay(200);
    int y = clearance();
    if (y == 1)
      right();
    else
      left();
    delay(500);
    brake();
    return 0;
  }
  else {
    return 1;
  }
}

void movem() {
  if (b == 0)
    brake();
  else if (b == 1) {
    o = obstacle();
    if (o == 1)
      forward();
  }
  else if (b == 2) {
    o = obstacle();
    if (o == 1)
      forward();
  }
  else if (b == 3)
    backward();
  else if (b == 4)
    left();
  else if (b == 5)
    right();
}

void bluetooth2()
{
  while (bluetooth.available()) {
    delay(50);
    char c = bluetooth.read();
    readString += c;
  }
  if (readString.length() > 0)
  {
    if (readString == "F") {
      b = 2;
    }
    else if (readString == "B") {
      b = 3;
    }
    else if (readString == "L") {
      b = 4;
    }
    else  if (readString == "R") {
      b = 5;
    }
    else if (readString == "S") {
      b = 0;
    }
    else if (readString == "ultra") {
      b = 1;
    }
    Serial.println(readString);
    readString = "";
  }
}

void loop() {
  s.write(90);

  while (bluetooth.available()) {
    delay(50);
    char c = bluetooth.read();
    readString += c;
  }
  if (readString.length() > 0)
  {
    if(readString=="ON")
      a=1;
    else if(readString=="OFF")
      a=2;
  }
  Serial.println(readString);
  readString = "";
  if (digitalRead(button) == LOW)
  {
    a++;
    Serial.println(a);
    delay(200);
  }
  mode();
}
void mode(){
  if (a == 1) {
    digitalWrite(ledoff, HIGH);
    digitalWrite(ledon, LOW);
    brake();
  }
  else if (a == 2) {
    digitalWrite(ledoff, LOW);
    digitalWrite(ledon, HIGH);
    bluetooth2();
    movem();
  }
  else {
    brake();
    a = 1;
  }
}
