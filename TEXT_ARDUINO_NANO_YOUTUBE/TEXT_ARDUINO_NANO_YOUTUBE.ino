//youtube.com/TARUNKUMARDAHAKE
//WWW.TARUNKUMARDAHAKE.COM
//FACEBOOK.COM/TARUNKUMARDAHAKE

char ground[8] = {A0,A1,A2,A3,A4,A5,12,13};

char ALPHA[] = {0,0,0,0,0,0,0,0,0,0,0,
102,102,102,60,24,24,24,0, 0,0,           //y           
  60,102,102,102,102,102,60,0, 0,0,       //o     
102,102,102,102,102,102,60,0, 0,0,        //u   
  126,24,24,24,24,24,24,0, 0,0,           //t     
102,102,102,102,102,102,60,0, 0,0,        //u   
124,102,102,124,102,102,124,0,0,0,        //b   
126,96,96,120,96,96,126,0, 0,0,           //e   
0,0,0,0,0,0,0,0,0,0,0
};
void setup() 
{
  for (int x=8;x<14;x++)
  {
    pinMode(x, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  
  for (int i=0;i<8;i++)
  {
    digitalWrite(ground[i],HIGH);
  }
  DDRD = 0xFF;
  PORTD =0;
}

void loop() 
{
  for(int x=0;x<142;x++)
  {
    for(int a=0;a<20;a++)
    {
 for          (int i=0;i<8;i++)
          { 
             digitalWrite(ground[i],LOW);
             PORTD = ALPHA[i+x];
            delay(1);
            digitalWrite(ground[i],HIGH);
          }    
    }
  }
  delay(1000);
}

