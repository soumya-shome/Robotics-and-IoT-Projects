#include<Servo.h>
#define trigPin 3
#define echoPin 2
#define rm1 3
#define rm2 5
#define lm1 9
#define lm2 10 
Servo s;
long duration, distance;

void setup() {
  Serial.begin(9600);
  s.attach(12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
}

void straight()
{
  analogWrite(rm1,70);
  analogWrite(rm2,0);
  analogWrite(lm1,70);
  analogWrite(lm2,0);
}

void Stop()
{
  analogWrite(rm1,0);
  analogWrite(rm2,0);
  analogWrite(lm1,0);
  analogWrite(lm2,0);
}

void right()
{
  analogWrite(rm1,0);
  analogWrite(rm2,0);
  analogWrite(lm1,70);
  analogWrite(lm2,0);
}

void left()
{
  analogWrite(rm1,70);
  analogWrite(rm2,0);
  analogWrite(lm1,0);
  analogWrite(lm2,0);
}

void SonarSensor()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}

void loop() {
  SonarSensor();
  Serial.println("Distance = "+distance);
  if(distance>=20)
  {
    straight();
  }
  else 
  {
    left();
  }
}
