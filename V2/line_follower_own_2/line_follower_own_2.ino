
#define lc 0
#define sc 1

#define lm1 3
#define lm2 5
#define rm1 9
#define rm2 10

int s1,s2,s3,s4,s5,s6,s7,s8;
int error=0;

String s="";

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
  s=s+digitalRead(A0);
  s=s+digitalRead(A1);
  s=s+digitalRead(A2);
  s=s+digitalRead(A3);
  s=s+digitalRead(A4);
  s=s+digitalRead(A5);
  s=s+digitalRead(2);
  s=s+digitalRead(4);
}
void straight()
{
  analogWrite(lm1,110);
  analogWrite(lm2,0);
  analogWrite(rm1,110);
  analogWrite(rm2,0);
}
void leftturn()
{
  analogWrite(lm1,0);
  analogWrite(lm2,20);
  analogWrite(rm1,140);
  analogWrite(rm2,0);
}
void rightturn()
{
  analogWrite(lm1,140);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,20);
}

void brake()
{
  analogWrite(lm1,255);
  analogWrite(lm2,255);
  analogWrite(rm1,255);
  analogWrite(rm2,255);
}

void loop()
{
  readsensors();
  mov();
}

void mov()
{
  if(s=="11111111") 
  {
    brake();
    Serial.println("stop");
  }
  else if("0000000")
  {
    brake();
    Serial.println("Stop");
  }
  else if(s=="11100111")
  {
    straight();
    Serial.println("Move Straight");
  }
  else if(s=="11000011")
  {
    straight();
    Serial.println("Move Straight");
  }
  else if(s=="10000001") 
  {
    straight();
    Serial.println("Move Straight");
  }
  else if(s=="11100111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="11001111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="10011111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="00111111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="10001111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="00011111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  
  else if(s=="11100111")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11110011")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111001")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111100")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11110001")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111000")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11101111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="11011111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="10111111") 
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="01111111")
  {
    leftturn();
    Serial.println("Move Left");
  }
  else if(s=="11110111")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111011") 
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111101")
  {
    rightturn();
    Serial.println("Move Right");
  }
  else if(s=="11111110")
  {
    rightturn();
    Serial.println("Move Right");
  }
  //else if(s=="11111111")
  //else
  //{
    //brake();
  //}
}
