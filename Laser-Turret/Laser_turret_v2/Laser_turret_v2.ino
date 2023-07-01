#include <Servo.h>
  
Servo servo1;
Servo servo2;
int joyX = A0;
int joyY = A1;
int button=A3;
int x, ax, y, ay, servoVal1=90, servoVal2=25, sped=1, mode=1, but1=2, but2=7, but3=8;

void setup() {
  
  pinMode(joyX,INPUT);
  pinMode(4,OUTPUT);
  pinMode(joyY,INPUT);
  pinMode(button,INPUT);
  servo1.attach(3);
  servo2.attach(5);
  Serial.begin(9600);
  x=analogRead(joyX);
  y=analogRead(joyY);
  pinMode(but1,INPUT_PULLUP);
  pinMode(but2,INPUT_PULLUP);
  pinMode(but3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(but1)==LOW)
  {
    if(mode==1)
    {
      mode=2;
    }
    else
    {
      mode=1;
    }
    delay(200);
  }
  speedchange();
  movem();
  Serial.println(mode);
  if(mode==1){
    digitalWrite(4,1);
  }
  else{
    if(analogRead(button)==0)
    {
      digitalWrite(4,1);
    }
    else
    {
      digitalWrite(4,0);
    }
  }
  Serial.print("button: ");
  Serial.println(analogRead(button));
}

void speedchange(){
  if(digitalRead(but3)==LOW)
  {
    if(sped<5){
      sped++;
    }
    Serial.println(sped);
    delay(200);
  }
  if(digitalRead(but2)==LOW)
  {
    if(sped>1){
      sped--;
    }
    Serial.println(sped);
    delay(200);
  }
}

void movem(){
  ax=analogRead(joyX);
  if(ax>x && (ax-x)>=30 )
  {
    if(servoVal1<180)
    {
      servoVal1+=sped;
    }
  }
  else if(ax<x && (x-ax)>=30)
  {
    if(servoVal1>0)
    {
      servoVal1-=sped;
    }
  }
  ay=analogRead(joyY);
  if(ay>y && (ay-y)>=30)
  {
    if(servoVal2<125)
    {
      servoVal2+=sped;
    }
  }
  else if(ay<y && (y-ay)>=30)
  {
    if(servoVal2>0)
    {
      servoVal2-=sped;
    }
  }
  servo1.write(servoVal1);
  servo2.write(servoVal2);
  Serial.print(servoVal1);
  Serial.print(" ");
  Serial.print(servoVal2);
  Serial.println();
  delay(50);
}
