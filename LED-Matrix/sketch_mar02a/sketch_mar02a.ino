int pos[8]={10,11,12,13,A2,A3,A4,A5};
int ground[8] = {9,8,7,6,5,4,3,2};
void setup() 
{
  for (int x=2;x<=13;x++){
    pinMode(x, OUTPUT);
  }
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  for (int i=0;i<8;i++){
    digitalWrite(ground[i],HIGH);
    digitalWrite(pos[i],LOW);
  }
}

void loop() 
{
  for(int i =0;i<8;i++){
    digitalWrite(ground[i],LOW);
    for(int j=0;j<8;j++){
      digitalWrite(pos[j],HIGH);
      delay(100);
      digitalWrite(pos[j],LOW);
      delay(100);
    }
    digitalWrite(ground[i],HIGH);
  }
}
