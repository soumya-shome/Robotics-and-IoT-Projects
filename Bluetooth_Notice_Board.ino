#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

String readString;

void setup() {
lcd.init();
lcd.backlight();
Serial.begin(9600);
lcd.setCursor(0,0);
}

void loop()
{
  int i=0;
  char commandbuffer[100];
  if(Serial.available())
  {
     delay(100);
     while( Serial.available() && i< 99) 
     {
        commandbuffer[i++] = Serial.read();
     }
     commandbuffer[i++]='\0';
  }
  if(i>0)
     Serial.println((char*)commandbuffer);
     lcd.print((char*)commandbuffer);
     delay(1000);
     lcd.clear();
}


