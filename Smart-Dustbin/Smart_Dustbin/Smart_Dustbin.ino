#include <Servo.h>
Servo myservo;

#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5

long duration, distance, RS,LS;

void setup()
{
Serial.begin (9600);
myservo.attach(8);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(12, OUTPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
RS = distance;
SonarSensor(trigPin2, echoPin2);
LS = distance;
if(LS>=4)
{
  if(RS<=13)
  {
    sweep();
    Serial.println("Open");
  }
}
else
{
  buzz();
  Serial.println("Full");
}
Serial.print(LS);
Serial.print(" - ");
Serial.println(RS);

}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}

void buzz()
{
    digitalWrite(12,1);
    delay(2000);
    digitalWrite(12,0);
    delay(1000);    
}

void sweep()
{
  for (int pos = 150; pos >= 0; pos -= 1)
  { 
    myservo.write(pos);
    delay(5);
  }
  delay(2000);
  for (int pos = 0; pos <= 150; pos += 1) 
  { 
    myservo.write(pos);
    delay(5);
  }
}
