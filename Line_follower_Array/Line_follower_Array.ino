#include<AFMotor.h>

AF_DCMotor m1(2);
AF_DCMotor m2(3);

int s1,s2,s3,s4,s5,s6,s7,s8;
int a=0;


void setup() {
  Serial.begin(9600);  
  m1.setSpeed(60);
m2.setSpeed(60);
  m1.run(RELEASE);
  m2.run(RELEASE);
}

void loop() {
  s1=digitalRead(A0);
  s2=digitalRead(A1);
  s3=digitalRead(A2);
  s4=digitalRead(A3);
  s5=digitalRead(A4);
  s6=digitalRead(A5);
  s7=digitalRead(9);
  s8=digitalRead(10);
  Serial.print(s1);
  Serial.print("-");
  Serial.print(s2);
  Serial.print("-");
  Serial.print(s3);
  Serial.print("-");
  Serial.print(s4);
  Serial.print("-");
  Serial.print(s5);
  Serial.print("-");
  Serial.print(s6);
  Serial.print("-");
  Serial.print(s7);
  Serial.print("-");
  Serial.println(s8);
  if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))
  {
    if(a==0)
    {
      Serial.println("Start");
    }
    m1.run(RELEASE);
    m2.run(RELEASE);
  } 
  else if((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))
  {
    // m1.setSpeed(50);
  //m2.setSpeed(50);
    Serial.println("Straight");
    m1.run(FORWARD);
    m2.run(FORWARD);
  }
  else if((s1==1)&&(s2==1)&&(s3==1)&&((s4==0)||(s5==0)||(s6==0)||(s7==0)||(s8==0)))
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
    Serial.println("Right");
    
  }
  else if(((s1==0)||(s2==0)||(s3==0)||(s4==0)||(s5==0))&&(s6==1)&&(s7==1)&&(s8==1))
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
    Serial.println("Left");
  }
  else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
  { 
    Serial.println("Stop");
    m1.run(RELEASE);
    m2.run(RELEASE);
  }
  
}
