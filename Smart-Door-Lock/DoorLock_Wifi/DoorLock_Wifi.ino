#include <SPI.h>
#include <MFRC522.h>
#include<LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Wire.h>
#include <Timelib.h>

#define RST_PIN  4
#define SS_PIN   15

LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);
MFRC522 mfrc522(SS_PIN, RST_PIN);
DS3231  rtc(SDA, SCL);


void setup() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(20,4);
  rtc.begin();
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
  //mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  //Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  rfid();
   lcd.setCursor(0,2);
 lcd.print("Time: ");
 lcd.print(rtc.getTimeStr());
 
 lcd.setCursor(0,3);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
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
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.print(content.substring(1)+" "); //prints the RFID Tag
  if (content.substring(1) == "0D 11 57 73")
  {
  //  access(1);
    //delay(2000);
    content="";
  }
  else
  {
//    access(2);
  }
  Serial.println();
}


void timed()
{
  lcd.setCursor(0,2);
 lcd.print("Time: ");
 lcd.print(rtc.getTimeStr());
 Serial.print(lcd.print(rtc.getTimeStr()));
 lcd.setCursor(0,3);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 Serial.print(rtc.getDateStr());
}
