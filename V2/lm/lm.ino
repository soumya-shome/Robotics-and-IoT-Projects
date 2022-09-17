#define lc 0
#define sc 1

#define lm1 10
#define lm2 11
#define rm1 12
#define rm2 13

int a[8]={2,3,4,5,6,7,8,9};
int error=0;

String s="";

void setup() {
  Serial.begin(9600);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  for(int i=0;i<8;i++)
  {
    pinMode(a[i],INPUT);
  }
}

void readsensors()
{
  s="";
  for(int i=0;i<8;i++)
  {
    s=s+digitalRead(a[i]);
  }
}

void loop()
{
//  digitalWrite(en1,140);
 // digitalWrite(en2,140);
  readsensors();
  movement();
 // delay(50);
 // brake();
  
}


void movement()
{
  Serial.println(s);
  if(s=="11111111")
    brake();
  else if(s=="11100111")
    forward();
  else if(s=="11001111")
    left();
  else if(s=="10011111")
    left();
  else if(s=="00111111")
    left();
    
  else if(s=="11110011")
    right();
  else if(s=="11111001")
    right();
  else if(s=="11111100")
    right();
}

void forward()
{
  Serial.println("forward");
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void left()
{
  Serial.println("left");
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void right()
{
  Serial.println("right");
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void brake()
{
  Serial.println("stop");
  digitalWrite(lm1,1);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,1);  
}
