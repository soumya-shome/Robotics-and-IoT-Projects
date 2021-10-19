int h[7]={2,3,4,5,6,7,8};

void setup() {
  for(int i=0;i<7;i++)
  {
    pinMode(h[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<10;i++)
  {
    num(i);
    delay(1000);
  }
}

void num(int n)
{
  switch(n)
  {
    case 0:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    break;
    
    case 1:
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    break;

    case 2:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
    break;
    
    case 3:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    break;

    case 4:
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    break;

    case 5:
      digitalWrite(2,HIGH);
      digitalWrite(3,0);
      digitalWrite(4,HIGH);
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    break;

    case 6:
      digitalWrite(2,HIGH);
      digitalWrite(3,0);
      digitalWrite(4,HIGH);
      digitalWrite(5,1);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    break;

    case 7:
      digitalWrite(2,1);
      digitalWrite(3,1);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,1);
      digitalWrite(8,0);
    break;

    case 8:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
    break;

    case 9:
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    break;
    
  }
}

