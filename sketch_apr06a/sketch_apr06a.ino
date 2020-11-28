#define lc 0
#define sc 1

#define lm1 3
#define lm2 5
#define rm1 9
#define rm2 10

int s1,s2,s3,s4,s5,s6,s7,s8;
int error=0;

void setup() {
  // put your setup code here, to run once:
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(13,OUTPUT);
}

void readsensors()
{
  s1=digitalRead(A5);
  s2=digitalRead(A4);
  s3=digitalRead(A3);
  s4=digitalRead(A2);
  s5=digitalRead(A1);
  s6=digitalRead(A0);
  s7=digitalRead(2);
  s8=digitalRead(4);
}
void straight()
{
  analogWrite(lm1,110);
  analogWrite(lm2,0);
  analogWrite(rm1,110);
  analogWrite(rm2,0);
}
void left_turn1()
{
  analogWrite(lm1,0);
  analogWrite(lm2,90);
  analogWrite(rm1,140);
  analogWrite(rm2,0);
}
void right_turn1()
{
  analogWrite(lm1,140);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,90);
}
void left_turn2()
{
  analogWrite(lm1,0);
  analogWrite(lm2,80);
  analogWrite(rm1,160);
  analogWrite(rm2,0);
}
void right_turn2()
{
  analogWrite(lm1,160);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,80);
}
void left_turn3()
{
  analogWrite(lm1,0);
  analogWrite(lm2,40);
  analogWrite(rm1,180);
  analogWrite(rm2,0);
}
void right_turn3()
{
  analogWrite(lm1,180);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,40);
} 
void left_90()
{
  analogWrite(lm1,0);
  analogWrite(lm2,200);
  analogWrite(rm1,200);
  analogWrite(rm2,0);
}
void right_90()
{
  analogWrite(lm1,200);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,200);
}
void brake()
{
  analogWrite(lm1,255);
  analogWrite(lm2,255);
  analogWrite(rm1,255);
  analogWrite(rm2,255);
}
void error_map()
{
  if((s3==sc)&&(s4==lc)&&(s5==lc)&&(s6==sc))
    {
      error=0;
    }
    
    else if((s3==sc)&&(s4==lc)&&(s5==sc)&&(s6==sc))
    {
      error=-0.5;
    }
    else if((s3==lc)&&(s4==lc)&&(s5==sc)&&(s6==sc))
    {
      error=-1;
    }
    else if((s2==sc)&&(s3==lc)&&(s4==sc)&&(s5==sc))
    {
      error=-1.5;
    }
    else if((s2==lc)&&(s3==lc)&&(s4==sc)&&(s5==sc))
    {
      error=-2;
    }
    else if((s1==sc)&&(s2==lc)&&(s3==sc)&&(s4==sc))
    {
      error=-2.5;
    }

    
    else if((s3==sc)&&(s4==sc)&&(s5==lc)&&(s6==sc))
    {
      error=0.5;
    }
    else if((s3==sc)&&(s4==sc)&&(s5==lc)&&(s6==lc))
    {
      error=1;
    }
    else if((s4==sc)&&(s5==sc)&&(s6==lc)&&(s7==sc))
    {
      error=1.5;
    }
    else if((s4==sc)&&(s5==sc)&&(s6==lc)&&(s7==lc))
    {
      error=2;
    }
    else if((s5==sc)&&(s6==sc)&&(s7==lc)&&(s8==sc))
    {
      error=2.5;
    }
}

void loop() {
  // put your main code here, to run repeatedly:

    readsensors();

    if((s1==lc)&&(s8==sc))
    {
      left_90();
      delay(40);
    }
    else if((s1==sc)&&(s8==lc))
    {
      right_90();
      delay(40);
    } 

    else
    {
      error_map();

      if(error<0 && error>-1)
        left_turn1();
      else if(error<=-1 && error>-2)
        left_turn2();
      else if(error<=-2.5)
        left_turn3();
          
      else if(error>0 && error<1)
        right_turn1();
      else if(error>=1 && error<2)
        right_turn2();
      else if(error>=2)
        right_turn3();
      
      else if((s1==lc)&&(s2==lc)&&(s3==lc)&&(s4==lc)&&(s5==lc)&&(s6==lc)&&(s7==lc)&&(s8==lc))
      {
        brake();
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        straight();
        delay(100);
      }
        else
        straight();
      
    }
  
}
