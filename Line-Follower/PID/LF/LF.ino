int l1=2;
int l2=3;

int r1=4;
int r2=5;

int en1=A4;
int en2=A5;


int a[8];
int last_proportional=0;
int integral=0;

char select_turn(unsigned char found_left,unsigned char found_right,unsigned char found_st);

int mod(int v);
int set_motors(int a,int b);
void turn(char dir);
void PID();

int right=0;
int left=0;

void setup() 
{
    pinMode(l1,OUTPUT);
    pinMode(l2,OUTPUT);

    pinMode(r1,OUTPUT);
    pinMode(r2,OUTPUT);

    pinMode(en1,OUTPUT);
    pinMode(en2,OUTPUT);

    Serial.begin(9600);
}


void loop() 
{
  PID();
  set_motors(150,150);
  delay(20);
  unsigned char found_left=0;
  unsigned char found_right=0;
  unsigned char found_st=0;

 readline();
 if(a[0]==LOW)
  found_left=1;

 if(a[7]==LOW)
  found_right=1;

 if(a[3]==LOW || a[4]==LOW)
  found_st=1;

 unsigned char dir;

 dir=select_turn(found_left,found_right,found_st);
 turn(dir);

}

int set_motors(int l,int r)
{
  Serial.println(r);
  Serial.println(l);

  if(l>0 && r>0)
  {
    analogWrite(en1,mod(l));
    analogWrite(en2,mod(r));

    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);

    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);

  }

  else if(l<0 && r>0)
  {
    analogWrite(en1,mod(l));
    analogWrite(en2,mod(r));

    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);

    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
  }

  else if(l>0 && r<0)
  {
    analogWrite(en1,mod(l));
    analogWrite(en2,mod(r));

    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);

    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
  }

  else if(l==0 && r==0)
  {
    analogWrite(en1,mod(l));
    analogWrite(en2,mod(r));

    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);

    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
  }
}
