int motorPin1  = 12;
int motorPin2  = 13;
int motorPin3  = 6;
int motorPin4  = 5;
String readString;
void setup(){
   pinMode(motorPin1, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   pinMode(motorPin3, OUTPUT);
   pinMode(motorPin4, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
     while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if(readString=="FORWARD")
    {
      front();
    }
    if(readString=="BACKWARD")
    {
      back();
    }
    if(readString=="LEFT")
    {
      left();
    }
    if(readString=="RIGHT")
    {
      right();
    }
    if(readString=="STOP")
    {
      stopped();
    }
    readString="";
   }
}

void front()
{
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
}

void back()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}

void left()
{
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(200);
}

void right()
{
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(200);
}

void stopped()
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}

