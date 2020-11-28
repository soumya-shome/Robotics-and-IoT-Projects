#include <Adafruit_NeoPixel.h>

#define PIN            7
#define NUMPIXELS      58
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  Serial.println();
  pixels.begin();
}
int r=0,g=255,b=255;
int a=0;
int n1=0;
void loop()
{
  timer();
  /*counter(n1);
  n1++;
  if(n1>9999 ){
    n1=0;
  }*/
  delay(50);
}

void counter(int n){
  int q[4]={0,0,0,0};
  int w=0;
  while(n!=0){
    q[w]=n%10;
    w++;
    n=n/10;
  }
  drawdigit(0,r,g,b,q[3]);
  drawdigit(14,r,g,b,q[2]);
  drawdigit(28,r,g,b,q[1]);
  drawdigit(42,r,g,b,q[0]);
}

void timer(){
  switch(a){
    case 1:
      r=255;
      g=0;
      b=0;
    break;
    case 2:
      r=0;
      g=255;
      b=0;
    break;
    case 3:
      r=0;
      g=0;
      b=255;
    break;
    case 4:
      r=255;
      g=255;
      b=0;
    break;
    case 5:
      r=255;
      g=0;
      b=255;
    break;
    case 6:
      r=0;
      g=255;
      b=255;
    break;
    case 7:
      r=255;
      g=255;
      b=255;
    break;
  }
  a++;
  if(a>7)
    a=0;
  int hours = 23;
  int mins=59;
  Serial.print(hours); 
  Serial.print(':');
  Serial.println(mins); 
  drawdigit(0,r,g,b,mins-((mins/10)*10));
  drawdigit(14,r,g,b,mins/10);
  pixels.setPixelColor(56, pixels.Color(r,g,b));
  pixels.setPixelColor(57, pixels.Color(r,g,b));
  drawdigit(28,r,g,b,hours-((hours/10)*10));
  drawdigit(42,r,g,b,hours/10);
  delay(1000);
}


void drawdigit(int offset, int r, int g, int b, int n)
{

  if (n==2 || n==3 || n== 4 || n==5 || n==6 || n==8 || n==9 )//A
  {
    pixels.setPixelColor(0+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(1+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(0+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(1+offset, pixels.Color(0,0,0));
  }
  
  if (n==0 || n==1 || n== 2 || n==3 || n==4 || n==7 || n==8 || n==9)//E
  {
    pixels.setPixelColor(8+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(9+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(8+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(9+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==2 || n== 3 || n==5 || n==6 || n==7 || n==8 || n==9)//F
  {
    pixels.setPixelColor(10+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(11+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(10+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(11+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==4 || n==5 || n== 6 || n==8 || n==9 )//G
  {
    pixels.setPixelColor(12+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(13+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(12+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(13+offset, pixels.Color(0,0,0));
  }
  
  pixels.show();
}
