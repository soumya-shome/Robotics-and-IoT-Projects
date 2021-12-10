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

byte led=6; //led buzzer

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

Servo gate_s; //servo

String password ="1234"; //admin password
String s;
String c="";
String card="0D 11 57 73";

int l_mode=0; //0-servo 1-lock

void setup() {
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  lcd.begin(20, 4);
  Serial.begin(9600);
  gate_s.attach(5);
  SPI.begin();      // Initiat e  SPI bus
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
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
      check(s);
      s="";
    }
  }
  //Serial.println();
}

void display(int n){
  Display_time();
  switch(n){
    default:
     lcd.setCursor(0,1);
     lcd.print("Enter Password");
  }
}

void check(String pass){
  if(pass.equals(password) || pass.equals(card))
  {
    access(1);
  }
  else if(pass.equals("01110")){
    l_mode=(!l_mode);      
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
      digitalWrite(led,HIGH);
      gate();
      delay(500);
    break;
    
    case 2:
      lcd.print("   Denied      ");
      delay(500);
    break;
  }
  lcd.clear();
  lcd.setCursor(0,0);
}

void gate(){
  switch(l_mode){
    case 0:
      for(int i=100;i>=0;i--)
      {
        gate_s.write(i);
        delay(15);
      }
      delay(2000);
      digitalWrite(led,LOW);      
      for(int i=0;i<=100;i++)
      {
        gate_s.write(i);
        delay(15);
      }
    break;

    case 1:
      digitalWrite(5,HIGH);
      delay(2000);
      digitalWrite(led,LOW);
      digitalWrite(5,LOW);
    break;    
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
  check(content.substring(1));
  content="";
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