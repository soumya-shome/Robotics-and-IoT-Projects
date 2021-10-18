#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <Wire.h>
#include <SPI.h>
#include <DS3231.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

LiquidCrystal_I2C lcd(0x3F , 2,1,0,4,5,6,7,3,POSITIVE);

int lr=2;
int lg=3;

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 5};
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

Servo m;
String password ="1234"; //create a password
String s;
String c="";
String p="1234";
DS3231  rtc(SDA, SCL);

void setup() {
 pinMode(lr,OUTPUT);
 pinMode(lg,OUTPUT);
 lcd.begin(20, 4);
 rtc.begin();
 SPI.begin(); 
 Serial.begin(9600);
// lcd.setCursor(0,0);
// lcd.print("Enter Password");
 m.attach(4);
 mfrc522.PCD_Init();
 /*
  * rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(11, 11, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(6, 3, 2019);
  */
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

void loop() {
  rfid();
 timed();
 lcd.setCursor(0,2);
 lcd.print("Enter Key ");
 lcd.setCursor(0,3);
 lcd.print(s);
 //lcd.setCursor(0,1);
 //lcd.print("Time: ");
 //lcd.print(rtc.getTimeStr());
 
 //lcd.setCursor(0,3);
 //lcd.print("Date: ");
// lcd.print(rtc.getDateStr());
  char b = myKeypad.getKey();
  if(b){
    if(b != '#')
    {
        s= s+ b;          
    }
    else
    {
      Serial.println(s);
      check();
      s="";
    }
  }
  
 delay(1000);
 lcd.clear();
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
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.print(content.substring(1)+" "); //prints the RFID Tag
  if (content.substring(1) == "0D 11 57 73")
  {
 //  timed();
    Serial.print(content.substring(1)+" ");
    access(1);
    delay(2000);
    content="";
  }
  else
  {
    access(2);
  }
  //Serial.println();
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
    break;
  }
  delay(1000);
  lcd.clear();
  timed();
  digitalWrite(lr,0);
  digitalWrite(lg,0);
}

void timed()
{
  lcd.setCursor(0,0);
 lcd.print("Time: ");
 lcd.print(rtc.getTimeStr());
// Serial.print(lcd.print(rtc.getTimeStr()));
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(" ");
 lcd.print(rtc.getDateStr());
 Serial.print(rtc.getDateStr());
}
