
int r1 = 9;
int r2 = 10;
int l1 = 6;
int l2 = 5;
const int trigPin = 7;
const int echoPin = 8;
long duration;
int distance;
String readString;
int a=1;
void setup(){
  pinMode(11,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void forward() {
analogWrite(r1,190);
digitalWrite(r2,0);
analogWrite(l1,190);
digitalWrite(l2,0);
}

void backward() {
digitalWrite(r1,0);
analogWrite(r2,190);
digitalWrite(l1,0);
analogWrite(l2,190);
}

void left() {
analogWrite(r1,190);
digitalWrite(r2,0);
digitalWrite(l1,0);
digitalWrite(l2,0);
}

void right() {
digitalWrite(r1,0);
digitalWrite(r2,0);
analogWrite(l1,190);
digitalWrite(l2,0);
}

void brake() {
digitalWrite(r1,0);
digitalWrite(r2,0);
digitalWrite(l1,0);
digitalWrite(l2,0);
}

void dist() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
}

int obstacle(){
  dist();
  if(distance<=12)
  {
    brake();
    delay(250);
    backward();
    delay(500);
    right();
    delay(750);
    brake();
    return 0;
  }
  else{
    return 1;
  }
}

void bluetooth()
{
  while(Serial.available())
    {
      delay(50);
      char c=Serial.read();
      readString+=c;
    }
    if(readString.length()>0)
    {
      if(readString=="forward"){
        if(obstacle()==1){
          forward();
        }
      }
      else if(readString=="backward"){
        backward();
      }
      else if(readString=="left"){
        left();
      }
      else  if(readString=="right"){
        right();
      }
      else if(readString=="stop"){
        brake();
      }
      else if(readString=="ultra"){
        if(obstacle()==1){
          forward();
        }
      }
      Serial.println(readString);
      if(readString!="ultra")
        readString="";
        
    }
}

void loop() {
  if(digitalRead(11)==LOW)
  {
    a++;
    Serial.println(a);
    delay(200);
  }
  if(a==1){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    brake();
  }
  else if(a==2){
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    bluetooth();
  }
  else{
    brake();
    a=1;
  }
}
