#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo myServoA,myServoB,myServoBASE,myServoP;               // Define any servo name
#define trigPin A4
#define echoPin A5
int servo_position = 0 ;

void setup() {
  
myServoB.attach (9);          // Define the servo signal pins
myServoA.attach (10); 
myServoBASE.attach(A0);
myServoP.attach (A1);
 Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
myServoB.write(120);
myServoA.write(40);
myServoBASE.write(160);
myServoP.write(0);

check();

}

void work()
{
 // down(0);
grab(0);
//down(1);

rot(1);

//down(0);
grab(1);
//down(1);

rot(2);
myServoA.write(40);
}

void down(int j)
{
  if(j==0)
  {
    for(int i=90;i<=160;i++){  
    myServoB.write(i);
    delay(10);
    }
  }

  else if(j==1)
  {
    for(int i=160;i>=90;i--){  
    myServoB.write(i);
    delay(10);
    }
  }
}

void grab(int k)
{
    for(int i=30;i>=0;i--){  
    myServoA.write(i);
    Serial.println(i);
    delay(20);
    }
  if(k==0)
  {
    myServoP.write(50);
  }
  else if(k==1)
  {
    myServoP.write(0);
  }
    for(int i=0;i<=30;i++){  
    myServoA.write(i);
    Serial.println(i);
    delay(20);
    }
}
void rot(int i)
{
  if(i==1)
  {
    for(int i=180;i>=90;i--){  
    myServoBASE.write(i);
    delay(20);
    }
  }
  else if(i==2)
  {
    for(int i=90;i<=180;i++){  
    myServoBASE.write(i);
    Serial.println(i);
    delay(20);
    }
  }
}

void check()
{
    long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if(distance>=11 && distance<=13)
 {
      Serial.print(distance);
      Serial.println(" cm");
      work();
      exit;
  }
}


  

