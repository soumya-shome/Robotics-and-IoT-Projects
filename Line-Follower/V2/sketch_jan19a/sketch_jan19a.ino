#include <AFMotor.h>

int a[8]={A0,A1,A2,A3,A4,A5,9,10};
int r[8]={0,0,0,0,0,0,0,0};
AF_DCMotor m1(1);
AF_DCMotor m2(2); 

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
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
    r[i]=digitalRead(a[i]);
    if(r[i]==1)
    {
      Serial.print("1-");
    }
    else
    {
      Serial.print("0-");
    }
  }
  mov();
    Serial.println();
}

void mov()
{
  if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
    Serial.println("stop");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==0) && (r[4]==0) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(FORWARD);
    m2.run(FORWARD);
    Serial.println("Straight");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==0) && (r[3]==0) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if((r[0]==1) && (r[1]==0) && (r[2]==0) && (r[3]==1) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if((r[0]==0) && (r[1]==0) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==0) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }


  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==0) && (r[5]==0) && (r[6]==1) && (r[7]==1)) 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==0) && (r[6]==0) && (r[7]==1)) 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==1) && (r[6]==0) && (r[7]==0)) 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==0) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m2.run(RELEASE);
    m1.run(FORWARD);
    Serial.println("Move Right");
  }


  else if((r[0]==1) && (r[1]==1) && (r[2]==0) && (r[3]==0) && (r[4]==0) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if((r[0]==1) && (r[1]==0) && (r[2]==0) && (r[3]==0) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }
  else if((r[0]==0) && (r[1]==0) && (r[2]==0) && (r[3]==1) && (r[4]==1) && (r[5]==1) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(RELEASE);
    m2.run(FORWARD);
    Serial.println("Move Left");
  }


  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==0) && (r[4]==0) && (r[5]==0) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==0) && (r[5]==0) && (r[6]==0) && (r[7]==1)) 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==0) && (r[6]==0) && (r[7]==0)) 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }

 
  else if((r[0]==1) && (r[1]==1) && (r[2]==0) && (r[3]==0) && (r[4]==0) && (r[5]==0) && (r[6]==1) && (r[7]==1)) 
  {
    m1.run(FORWARD);
    m2.run(FORWARD);
    Serial.println("Straight");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==0) && (r[5]==0) && (r[6]==0) && (r[7]==0)) 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==0) && (r[4]==0) && (r[5]==0) && (r[6]==0) && (r[7]==1)) 
  {
    m1.run(FORWARD);
    m2.run(RELEASE);
    Serial.println("Move Right");
  }
  else if((r[0]==1) && (r[1]==1) && (r[2]==1) && (r[3]==1) && (r[4]==1) && (r[5]==0) && (r[6]==0) && (r[7]==0)) 
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

