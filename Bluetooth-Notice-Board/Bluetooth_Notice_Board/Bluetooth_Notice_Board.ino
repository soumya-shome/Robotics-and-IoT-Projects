#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

String readString;

void setup() {
  lcd.begin(16,2);   // iInit the LCD for 16 chars 2 lines
  lcd.backlight();   // Turn on the backligt (try lcd.noBaklight() to turn it off)
  lcd.setCursor(0,0);    
  Serial.begin(9600);
  lcd.clear();
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
  if(i>0){
    lcd.clear();
     Serial.println((char*)commandbuffer);
     lcd.print((char*)commandbuffer);
     delay(1000);
  }
  lcd.scrollDisplayLeft();
  delay(450);
}


