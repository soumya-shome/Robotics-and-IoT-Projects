#define irr 2
#define irl 4
#define rm1 5
#define rm2 6
#define lm1 9
#define lm2 10 

void setup() {
  Serial.begin(9600);
  pinMode(irr,INPUT);
  pinMode(irl,INPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
}

void straight()
{
  analogWrite(rm1,100);
  analogWrite(rm2,0);
  analogWrite(lm1,100);
  analogWrite(lm2,0);
}

void Stop()
{
  analogWrite(rm1,255);
  analogWrite(rm2,255);
  analogWrite(lm1,255);
  analogWrite(lm2,255);
}

void right()
{
  analogWrite(rm1,0);
  analogWrite(rm2,0);
  analogWrite(lm1,100);
  analogWrite(lm2,0);
  delay(400);
}

void left()
{
  analogWrite(rm1,100);
  analogWrite(rm2,0);
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  delay(400);
}

void loop() {
  int r1=digitalRead(irr);
  int r2=digitalRead(irl);
  Serial.print("irr = "+r1);
  Serial.println("irl = "+r2);
   if(r1==1 && r2==1)
   {
    Serial.println("Straight ");
    straight();
   }
   else if(r1==0 && r2==1)
   {
    Serial.println("left ");    
    left();
   }
   else if(r1==1 && r2==0)
   {
    right();
    Serial.println("right");
   }
   else
   {
    Serial.println("Stop ");
     Stop();
   }
   delay(300);
}
