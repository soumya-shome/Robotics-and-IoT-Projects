#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <Wire.h>
#include "RTClib.h"



#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

byte led_red=A1;
byte led_green=A0;

const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, A3};
byte colPins[COLS] = {A2, A1, A0};
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

Servo gate_s;

String password ="1234";
String s;
String c="";



void setup() {
  pinMode(led_red,OUTPUT);
  pinMode(led_green,OUTPUT);
  lcd.begin(20, 4);
  Serial.begin(9600);
  gate_s.attach(8);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  Serial.println("Ready");
}

void loop() {
  rfid();
  display(1);
  char b = myKeypad.getKey();
  if(b){
    if(b != '#'){
        lcd.setCursor(0,2);
        s= s+ b;   
        Serial.println(s);
        lcd.print(s); 
    }
    else{
      Serial.println("En="+s);
      check();
      s="";
    }
  }
  //Serial.println();
}

void check(){
  if(s.equals(password))
  {
    access(1);
  }
  else
  {
    access(2);
  }
}

void sweep(){
  for(int i=100;i>=0;i--)
  {
    gate_s.write(i);
    delay(15);
  }
  delay(2000);
  for(int i=0;i<=100;i++)
  {
    gate_s.write(i);
    delay(15);
  }
}

void rfid(){
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;

  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;
  
  String content= "";
  int letter;
  for (int i = 0; i < mfrc522.uid.size; i++) 
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
    //Time();
    //Serial.print(content.substring(1)+" ");
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

void access(int a){
  lcd.setCursor(0,3);
  switch(a)
  {
    case 1:
      lcd.print("   Granted     ");
      digitalWrite(led_green,1);
      sweep();   
      delay(200);
    break;
    
    case 2:
      lcd.print("   Denied      ");
      digitalWrite(led_red,1);
    break;
  }
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  digitalWrite(led_red,0);
  digitalWrite(led_green,0);
 //lcd.print("Enter Password");
}

void Display_time(){
  DateTime now = rtc.now();
  
  int h=((now.hour()>12)?(now.hour()%12):now.hour());
  String hr=h>9?String(h):"0"+String(h);
  String min=now.minute()>9?String(now.minute()):"0"+String(now.minute());
  String clck=(now.hour()>12)?" PM":" AM";
  /*
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());*/
  /*Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");*/
  /*Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  
  Serial.println(clck);
  */
  String time_n=hr+":"+min+clck+" ";
  String date=String(now.day(),DEC)+"/"+String(now.month(),DEC)+"/"+String(now.year(),DEC);
  String time=time_n+date;
  //Serial.println(time);
  lcd.setCursor(0,0); 
  lcd.print(time);
}

void display(int n){
  Display_time();
  switch(n){
    default:
     lcd.setCursor(0,1);
     lcd.print("Enter Password");
  }

}