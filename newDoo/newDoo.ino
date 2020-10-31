#include <Keypad.h>
#include <Servo.h>
#include<LiquidCrystal_I2C.h>
//#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
//#include "RTClib.h"
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);

int lr=6;
int lg=7;

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Servo m;
String password ="1234"; //create a password
String s;

//RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void setup() {
 pinMode(lr,OUTPUT);
 pinMode(lg,OUTPUT);
 lcd.begin(20, 4);
 lcd.setCursor(0,0);
 lcd.print("Enter Password");
 Serial.begin(9600);
  m.attach(8);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();
 /* if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     //rtc.adjust(DateTime(2019, 2, 12, 23, 19, 50));
  }*/
  digitalWrite(lr,1);
  delay(200);
  digitalWrite(lr,0);
  delay(200);
  digitalWrite(lg,1);
  delay(200);
  digitalWrite(lg,0);
  delay(200);
  Serial.println("Ready");
}

String c="";
String p="1234";


void loop() {
  rfid();
  char b = myKeypad.getKey();
  if(b){
    if(b != '#')
    {
        lcd.setCursor(0,1);
        s= s+ b;   
        Serial.println(s);
        lcd.print(s); 
    }
    else
    {
      Serial.println("En="+s);
      check();
      s="";
    }
  }
  //Time();
  //Serial.println();
}



void check()
{
  if(s.equals(password))
  {
    access(1);
  }
  else
  {
    access(2);
  }
  
}




void sweep()
{
      for(int i=100;i>=0;i--)
      {
        m.write(i);
        delay(15);
      }
      delay(2000);
      for(int i=0;i<=100;i++)
      {
         m.write(i);
          delay(15);
      }
}



void rfid()
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println(content.substring(1)+" "); //prints the RFID Tag
  if (content.substring(1) == "0D 11 57 73")
  {
//    Time();
    Serial.print(content.substring(1)+" ");
    access(1);
    delay(2000);
    Serial.println();
    content="";
  }
  else
  {
    access(2);
  }
}




void access(int a)
{
  lcd.setCursor(0,0);
  switch(a)
  {
    case 1:
      lcd.print("   Granted     ");
      digitalWrite(lg,1);
      sweep();   
      
 
  delay(200);
    break;
    
    case 2:
      lcd.print("   Denied      ");
      digitalWrite(lr,1);
  }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(lr,0);
   digitalWrite(lg,0);
 lcd.print("Enter Password");
}

/*void Time()
{
  DateTime now = rtc.now();
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  int t=(now.hour(), DEC);
  if(t>12  && t<=24)
  {
   Serial.print(t-12);
  }
  else
  {
   Serial.print(t);
  }
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  if((now.hour(), DEC)>12)
  {
    Serial.print(" am");
  }
  else
  {
    Serial.print(" pm");
  }
}*/
