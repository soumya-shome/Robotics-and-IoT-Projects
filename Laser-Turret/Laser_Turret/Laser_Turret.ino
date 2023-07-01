

#include <Servo.h>
  
Servo servo1;
Servo servo2;
int joyX = A0;
int joyY = A1;
int button=A2;
  int x,ax,y,ay;
int servoVal1=90,servoVal2=25;
  
void setup() 
{
  pinMode(joyX,INPUT);
  pinMode(2,OUTPUT);
  pinMode(joyY,INPUT);
  pinMode(button,INPUT);
  servo1.attach(3);
  servo2.attach(6);
  Serial.begin(9600);
  x=analogRead(joyX);
  y=analogRead(joyY);
  
}
  
void loop()
{
  if(analogRead(button)==0)
  {
    digitalWrite(2,1);
    delay(150);
  }
  else
  {
    digitalWrite(2,0);
  }
  ax=analogRead(joyX);
  if(ax>x && (ax-x)>=30 )
  {
    if(servoVal1<180)
    {
      servoVal1++;
    }
  }
  else if(ax<x && (x-ax)>=30)
  {
    if(servoVal1>0)
    {
      servoVal1--;
    }
  }
  ay=analogRead(joyY);
  if(ay>y && (ay-y)>=30)
  {
    if(servoVal2<125)
    {
      servoVal2++;
    }
  }
  else if(ay<y && (y-ay)>=30)
  {
    if(servoVal2>0)
    {
      servoVal2--;
    }
  }
  servo1.write(servoVal1);
  servo2.write(servoVal2);
  Serial.print(servoVal1);
  Serial.print(" ");
  Serial.print(servoVal2);
  Serial.print(" ");
  Serial.println(analogRead(button));
  delay(50);
}
