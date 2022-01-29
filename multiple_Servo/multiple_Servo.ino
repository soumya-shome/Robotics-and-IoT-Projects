//Robo Arm 3.0
const int p1=A0;
const int p2=A1;
const int p3=A2;
const int but1=2;
const int but2=8;
#include <Servo.h>
Servo s[4];
int a=0,b,c,d;
void setup() {
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(but1,INPUT_PULLUP);
  pinMode(but2,INPUT_PULLUP);
  s[0].attach(3);
  s[1].attach(5);
  s[2].attach(6);
  s[3].attach(9);
  Serial.begin(9600);
}

void loop() {
 Pot();
 s[0].write(a);
 s[1].write(b);
 s[2].write(c);
 if(digitalRead(but1)==LOW)
 {
    s[3].write(90);
    Serial.println("OPen");
 }
 if(digitalRead(but2)==LOW)
 {
    s[3].write(180);
    Serial.println("Closed");
 }
}

void Pot()
{
  a=analogRead(p1);
  a=map(a,0,1023,25,145);
  Serial.print(a);
  Serial.print("-----");
  
  b=analogRead(p2);
  b=map(b,0,1023,45,135);
  Serial.print(b);
  Serial.print("-----");
  
  c=analogRead(p3);
  c=map(c,0,1023,75,180);
  Serial.println(c);
  Serial.print("-----");
}
