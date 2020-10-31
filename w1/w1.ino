#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>
#include <SPI.h>
#include <MFRC522.h>
#include<LiquidCrystal_I2C.h>

#define BLYNK_PRINT Serial
#define RST_PIN  0
#define SS_PIN   15
LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);

char auth[] = "f872a20726b54dc4b3bb73247cce4813";
char ssid[] = "Run Wifi Run";
char pass[] = "flashpoint";
int timezone = 5.30 * 3600;
int dst = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(ssid,pass);
  lcd.begin(20,4);
  Serial.print("Connecting");
  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");
  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  Serial.println("\nTime response....OK");
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  
}

void loop()
{
  Blynk.run();
  timed();
  rfid();
  lcd.setCursor(0,2);
  lcd.print("Place your card");
  lcd.setCursor(0,3);
  if(digitalRead(2)==LOW)
  {
    lcd.print("LOCKED");
  }
  else
  {
    lcd.print("UNLOCKED");
  }
  delay(100);
}

void timed()
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  lcd.setCursor(0,0);
  lcd.print("Date:");
  Serial.print(p_tm->tm_mday);
  Serial.print("/");
  Serial.print(p_tm->tm_mon + 1);
  Serial.print("/");
  Serial.print(p_tm->tm_year + 1900);
  Serial.print(" ");

  lcd.print(p_tm->tm_mday);
  lcd.print("/");
  lcd.print(p_tm->tm_mon + 1);
  lcd.print("/");
  lcd.print(p_tm->tm_year + 1900);
  Serial.print(" ");
  
  lcd.setCursor(0,1);
  lcd.print("Time");
  Serial.print((p_tm->tm_hour));
  Serial.print(":");
  Serial.print((p_tm->tm_min));
  Serial.print(":");
  Serial.println(p_tm->tm_sec);

  lcd.print((p_tm->tm_hour));
  lcd.print(":");
  lcd.print((p_tm->tm_min));
  lcd.print(":");
  lcd.println(p_tm->tm_sec);
  
  delay(1000);
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
  Serial.print(content.substring(1)+" "); //prints the RFID Tag
  if (content.substring(1) == "06 D3 AB 1B")
  {
    Serial.println("Welcome");
    /*digitalWrite(2,HIGH);
    delay(2000);
    digitalWrite(2,LOW);
    */
    lcd.setCursor(0,2);
    lcd.clear();
    lcd.print("UNLOCKED");
    delay(2000);
    lcd.clear();
    lcd.print("LOCKED");
    content="";
  }
  else
  {
    
    lcd.setCursor(0,3);
    lcd.print("   DENIED");
    delay(500);
    lcd.clear();
    Serial.println("Denied");
  }
  Serial.println();
}
