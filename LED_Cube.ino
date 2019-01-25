
  int layer[4]={A3,A2,A1,A0}; //initializing and declaring led layers
  int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4}; //initializing and declaring led rows
  int time = 250;

  
 
void setup()
{
  
  for(int i = 0; i<16; i++)   
  {
    pinMode(column[i], OUTPUT);  //setting rows to ouput
  }
  
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }
  
  randomSeed(analogRead(10));  //seeding random for random pattern
}

void loop()
{
  FlickerOn();
  FlickerOff();
  OnandOffByLayers();
  OnAndOffByColumns();
  LayerStopUpAndDown();
  AroundEdgeDown();
  RandomFlicker();
  RandomRain();
  DiagonalRectangle();
  Propeller();
  SpiralInAndOut();
  GoThroughAllLedsOneAtATime();
  delay(1000);
}



void AllOff()
{
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 0);
   }
}

void AllOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}


void ColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
}

void ColumnsOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
}

void LayersOn()
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(layer[i],1);
  }
}

void LayersOff()
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(layer[i],0);
  }
}

void FlickerOn()
{
  AllOff();
  for(int i=0 ; i<=150 ; i+=15 )
  {
    AllOn();
    delay(i);
    AllOff();
    delay(i);
  }
}

void FlickerOff()
{
  AllOn();
  for(int i = 0; i<= 150; i+=15)
  {
    AllOff();
    delay(i+50);
    AllOn();
    delay(i);
  }
}

void OnandOffByLayers()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    AllOn();
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = 4; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
  }
}


void OnAndOffByColumns()
{
  AllOff();
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for(int y = 0; y<3; y++)
  {
    for(int i=0;i<=3;i++)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=4;i<=7;i++)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=8;i<=11;i++)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=11;i<=15;i++)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=15;i>=12;i--)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=11;i>=8;i--)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=7;i>=4;i--)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=3;i>=0;i--)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=15;i>=12;i--)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=11;i>=8;i--)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=7;i>=4;i--)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=3;i>=0;i--)
    {
      digitalWrite(column[i],0);
      delay(80);
    }
    for(int i=0;i<=3;i++)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=4;i<=7;i++)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=8;i<=11;i++)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
    for(int i=11;i<=15;i++)
    {
      digitalWrite(column[i],1);
      delay(80);
    }
  }
}


void LayerStopUpAndDown()
{
  LayersOff();
  ColumnsOn();
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      for(int c=0;c<1;c++)
      {
        digitalWrite(layer[c],1);
        delay(80);
        digitalWrite(layer[c],0);  
      }
      for(int c=3;c>=0;c--)
      {
        digitalWrite(layer[c],1);
        delay(80);
        digitalWrite(layer[c],0);  
      }
    }

    for(int j=0;j<4;j++)
    {
      digitalWrite(layer[j],1);
      delay(80);
    }
    for(int j=3;j>=0;j--)
    {
      digitalWrite(layer[j],1);
      delay(80);
    }
  }
}

void AroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    AllOff();
    for(int i = 4; i >= 0; i--)
    {
      digitalWrite(layer[i-1], 1);
      digitalWrite(column[5], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[10], 0);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      
      digitalWrite(column[4], 0);
      delay(x);
      digitalWrite(column[4], 1);
      
      digitalWrite(column[8], 0);
      delay(x);
      digitalWrite(column[8], 1);
      
      digitalWrite(column[12], 0);
      delay(x);
      digitalWrite(column[12], 1);
      
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      
      digitalWrite(column[14], 0);
      delay(x);
      digitalWrite(column[14], 1);
      
      digitalWrite(column[15], 0);
      delay(x);
      digitalWrite(column[15], 1);
      
      digitalWrite(column[11], 0);
      delay(x);
      digitalWrite(column[11], 1);
      
      digitalWrite(column[7], 0);
      delay(x);
      digitalWrite(column[7], 1);
      
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);
    }
  }
}

void RandomFlicker()
{
  AllOff();
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomColumn = random(0,16);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(10);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(10); 
  }
}
void RandomRain()
{
  AllOff();
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,16);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer[0], 1);
    delay(150);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(100);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(100);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(150);
    digitalWrite(layer[3], 0);
    digitalWrite(column[randomColumn], 1);
  }
}


void DiagonalRectangle()
{
  int x = 350;
  AllOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    AllOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    AllOff();
    //bottom right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    AllOff();
    //bottom middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    AllOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    AllOff();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    AllOff();
    //top right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    AllOff();
    //top middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    AllOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 0);
  }
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  delay(x);
  AllOff();
}


void Propeller()
{
  AllOff();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1);
      //a1
      ColumnsOff();
      digitalWrite(column[0], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[15], 0);
      delay(x);
      //b1
      ColumnsOff();
      digitalWrite(column[4], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[11], 0);
      delay(x);
      //c1
      ColumnsOff();
      digitalWrite(column[6], 0);
      digitalWrite(column[7], 0);
      digitalWrite(column[8], 0);
      digitalWrite(column[9], 0);
      delay(x);
      //d1
      ColumnsOff();
      digitalWrite(column[3], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[12], 0);
      delay(x);
      //d2
      ColumnsOff();
      digitalWrite(column[2], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[13], 0);
      delay(x);
      //d3
      ColumnsOff();
      digitalWrite(column[1], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[14], 0);
      delay(x);
    }
  }
  //d4
  ColumnsOff();
  digitalWrite(column[0], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[15], 0);
  delay(x);
}
//spiral in and out
void SpiralInAndOut()
{
  AllOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
//spiral out counter clockwise
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
//spiral in counter clock wise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[4], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[12], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[14], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
//spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[14], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[12], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[4], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
  }
}
//go through all leds one at a time
void GoThroughAllLedsOneAtATime()
{
  int x = 15;
  AllOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 0; i<4; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 4; i<8; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 8; i<12; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 12; i<16; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
  }
}

