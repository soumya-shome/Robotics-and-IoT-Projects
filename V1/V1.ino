
int l1=2;
int l2=3;

int r1=4;
int r2=5;

int en1=A0;
int en2=A1;

void setup() {
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<=255;i++)
  {
    analogWrite(en1,i);
    analogWrite(en2,i);

    digitalWrite(r1,1);
    digitalWrite(r2,0);

    digitalWrite(l1,1);
    digitalWrite(l2,0);
    
    Serial.println(i);
    
    delay(100);
  }
  delay(2000);
}
