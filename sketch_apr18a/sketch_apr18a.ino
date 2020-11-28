#include <Servo.h>
Servo myservo;

int pos;  
const int trig = 5;
const int echoPin = 6;
const int echo = 9;
long duration;
int distance;
long dur;
int dist;

void setup() {
  pinMode(echoPin, INPUT); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(8);
  Serial.begin(9600); 
  pinMode(12,OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  dist= dur*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" Distance2: ");
  Serial.println(dist);
  if(dist>=4)
  {
    if(distance<=12)
    {
      Serial.println("Open");
      sweep();
      
    }
  }
  else
  {
    Serial.println("Full");
    buzz();
  }
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
  for (pos = 150; pos >= 0; pos -= 1)
      { 
        myservo.write(pos);
        delay(5);
       }
       delay(2000);
      for (pos = 0; pos <= 150; pos += 1) 
      { 
        myservo.write(pos);
        delay(5);
      }
}
