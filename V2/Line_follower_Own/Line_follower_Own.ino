#include <AFMotor.h>

int a[8]={9,10,A0,A1,A2,A3,A4,A5};
//int r[8]={0,0,0,0,0,0,0,0};
AF_DCMotor m1(1);
AF_DCMotor m2(2); 

String s="";
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  m1.setSpeed(90);
  m2.setSpeed(90);
  m1.run(RELEASE);
  m2.run(RELEASE);
  for(int i=0;i<8;i++)
  {
    pinMode(a[i],INPUT);
  }
    
}

void loop() {

  for(int i=0;i<8;i++)
  {
    int b=digitalRead(a[i]);
    if(b==1)
    {
      s=s+"1";
      Serial.print("1-");
    }
    else
    {
      s=s+"0";
      Serial.print("0-");
    }
  }
  Serial.println(s);
  //delay(500);
  mov();
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
  else if(s=="11000011") 
  {
    m1.run(FORWARD);
    m2.run(FORWARD);
    Serial.println("Straight");
  }
  
  else if(s=="11001111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="10011111")
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="00111111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="11101111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="11110011") 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if(s=="11111001") 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if(s=="11111100") 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if(s=="11110111") 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if (s=="11000111")
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="10001111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if(s=="00011111") 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if (s=="11100011")
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if(s=="11110001") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if(s=="11111000") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if(s=="11110000") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if(s=="11100001") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if(s=="11111000") 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
  }
}
