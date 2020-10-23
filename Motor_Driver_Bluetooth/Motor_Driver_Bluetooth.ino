String readString;

int motorPin1  = 4;
int motorPin2  = 5;
int motorPin3  = 9;
int motorPin4  = 10;


void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD")
    {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(500);
    }
    if (readString =="BACKWARD"){
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin4, LOW);
      digitalWrite(motorPin3, HIGH);
      delay(500);
    }
    if (readString =="LEFT"){
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, HIGH);
      digitalWrite(motorPin4, LOW);
      delay(500);
    }
    if (readString =="RIGHT"){
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(500);
    }
    if (readString =="STOP"){
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, LOW);
      delay(500);
    }

    readString="";
  }
}


