122#include <AFMotor.h>

int a[8]={A0,A1,A2,A3,A4,A5,9,10};
AF_DCMotor m1(1);
AF_DCMotor m2(2); 

String s="";
void setup() {
  Serial.begin(9600);
  m1.run(RELEASE);
  m2.run(RELEASE);
  for(int i=0;i<8;i++)
  {
    pinMode(a[i],INPUT);
  }
}

void loop() {
  m1.setSpeed(180);
  m2.setSpeed(180);
  for(int i=0;i<8;i++)
  {
    s=s+digitalRead(a[i]);
    if(a[i]==1)
    {
      Serial.print("1-");
    }
    else
    {
      Serial.print("0-");
    }
  }
  Serial.println(s);
  delay(500);
//  mov();
  s="";
    Serial.println();
}



void mov()
{
  if(s=="11111111") 
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
    Serial.println("stop");
  }
  else if(s=="11100111")
  {
    m1.run(FORWARD);
    m2.run(FORWARD);
    Serial.println("Straight");
  }
  else if(s=="11101111" || s=="11001111" || s=="10011111" || s=="00111111" || s=="11000111" || s=="10001111" || s=="00011111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="11110111" || s=="11110011" || s=="11111001" || s=="11111100" || s=="11100011" || s=="11110001" || s=="11111000") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
}

void oneinch()
{
  m1.run(FORWARD);
  m2.run(FORWARD);
  delay(500);
}

void turnr()
{

  
}
