#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <MFRC522.h>
#include<LiquidCrystal_I2C.h>
#include <time.h>

#define BLYNK_PRINT Serial
#define RST_PIN  16
#define SS_PIN   15
#define Door   2



LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);
MFRC522 mfrc522(SS_PIN, RST_PIN);

char auth[] = "f872a20726b54dc4b3bb73247cce4813";
char ssid[] = "Run Wifi Run";
char pass[] = "flashpoint";

int timezone = 5.30 * 3600;
int dst = 0;

void setup() {
  //pinMode(Door,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(ssid,pass);
  while (!Serial);
    SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  digitalWrite(Door,LOW);
  //lcd.print("Enter Password");
  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
    // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  
  Serial.println(WiFi.localIP() );
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");
  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }  
}

void loop() {
  Blynk.run();
  rfid();
  timed();
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
  if (content.substring(1) == "06 D3 AB 1B")
  {
    digitalWrite(Door,HIGH);
    delay(2000);
    digitalWrite(Door,LOW);
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
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  Serial.print(p_tm->tm_mday);
  Serial.print("/");
  Serial.print(p_tm->tm_mon + 1);
  Serial.print("/");
  Serial.print(p_tm->tm_year + 1900);
  Serial.print(" ");
  Serial.print((p_tm->tm_hour));
  Serial.print(":");
  Serial.print((p_tm->tm_min));
  Serial.print(":");
  Serial.println(p_tm->tm_sec);
  delay(1000);
}
