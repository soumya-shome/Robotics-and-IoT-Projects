#define lc 0
#define sc 1

#define lm1 3
#define lm2 5
#define rm1 9
#define rm2 10

void setup() {
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
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

void loop() {
  left_90();
  delay(250);
  straight();
  delay(250);
  brake();
  delay(3000);
}
