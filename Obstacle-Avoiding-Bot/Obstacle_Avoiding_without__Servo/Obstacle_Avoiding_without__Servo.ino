const int trigPin = 7;
const int echoPin = 8;
long duration;
int distance;
#define rm1 9
#define rm2 10
#define lm1 5
#define lm2 6 
//#define s1 3
//#define s2 11

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
 // pinMode(s1,OUTPUT);
 // pinMode(s2,OUTPUT);
}

void straight()
{
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
}

void left()
{
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
}

void brake()
{
  digitalWrite(rm1,1);
  digitalWrite(rm2,1);
  digitalWrite(lm1,1);
  digitalWrite(lm2,1);
}

void SonarSensor()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance-");
  Serial.println(distance);
}

void loop() {
  SonarSensor();
 // analogWrite(s1,60);
 // analogWrite(s2,60);
  if(distance>=20)
  {
    straight();
  }
  else 
  {
    brake();
    delay(500);
    left();
    delay(400);
    brake();
    delay(300);
    Serial.println("Left");
  }
}
