#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int a=A0;
int b=A1;

void setup() {
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  motor1.setSpeed(130);
  motor2.setSpeed(130);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.begin(9600);
}

void loop() {
  int c=digitalRead(a);
  int d=digitalRead(b);
  Serial.print("a"+a);
  Serial.println("b="+b);
  if(c==d) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  else {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
}