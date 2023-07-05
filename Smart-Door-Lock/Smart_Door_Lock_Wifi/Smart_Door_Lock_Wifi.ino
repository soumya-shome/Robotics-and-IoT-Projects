#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>
#include <SPI.h>
#include <MFRC522.h>
#include<LiquidCrystal_I2C.h>


//#include <Servo.h>

//Servo m;
#define BLYNK_PRINT Serial
#define RST_PIN  2
#define SS_PIN   15
#define relay 16
#define buzzer 0

char auth[] = "f872a20726b54dc4b3bb73247cce4813";
char ssid[] = "Soumyadeep";
char pass[] = "10967bubu";
//int thresholds[16]={622,487,302,964,915,856,1  ,2  ,3  ,4  ,  5, 6 , 7 ,62 ,783,9 };
//char keypad[16]=   {'1','2','3','4','5','6','7','8','9','C','*','0','#','A','B','D'};

String d[10]={"06 D3 AB 1B","","","","","","","","",""};
String sf="1234";
String s="";

int timezone = 5.30 * 3600;
int dst = 0;

LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);
MFRC522 mfrc522(SS_PIN, RST_PIN);
WidgetTerminal terminal(V2);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  WiFi.begin(ssid,pass);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("Connecting.....");
  Serial.print("Connecting");
  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
  delay(1000);
  lcd.clear();
  lcd.print("Wifi Connected !! ");
  Serial.println("Wifi Connected Success!");
  lcd.setCursor(0,1);
  lcd.print("IP Address: ");
  Serial.print("NodeMCU IP Address : ");
  lcd.setCursor(0,2);
  lcd.print(WiFi.localIP());
  Serial.println(WiFi.localIP());
  delay(2000);
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  Serial.println("\nWaiting for Internet time");
  while(!time(nullptr)){
     Serial.print("*");
     delay(1000);
  }
  lcd.setCursor(0,3);
  lcd.print("Internet Time ... OK");
  Serial.println("\nTime response....OK");
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();
  mfrc522.PCD_Init();
  //mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  delay(5000);
  lcd.clear();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.println(pinValue);
  if(pinValue==1)
  {
    buzzin();
    lcd.setCursor(0,2);
    lcd.println("Welcome Master");
    terminal.print("Welcome Master");
    sendtime();
    digitalWrite(relay,1);
  }
  else if(pinValue==0)
  {
    digitalWrite(relay,0);
  }
}

void loop()
{
  //lcd.setCursor(0,2);
  //lcd.print("Enter Key : ");
  //lcd.print(s);
  //Serial.println("s= "+s);
  Blynk.run();
  rfid();
  timed();
 // getkey();
  lcd.clear();
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
  if (check(content.substring(1)) == 1)
  {
    terminal.print("Welcome "+content.substring(1)+" ");
    sendtime();
    access();
  }
  else
  {
    denied();
  }
  Serial.println();
}

int check(String s)
{
  int y=0;
  for(int i=0;i<10;i++)
  {
    if(s.compareTo(d[i])==0)
    {
      y++;
      break;
    }
  }
  if(y==1)
    return 1;
  else 
    return 0;
}

void access()
{
  buzzin();
  lcd.setCursor(0,3);
  lcd.println("Welcome");
  Blynk.virtualWrite(V1,HIGH);
  digitalWrite(relay,HIGH);
  delay(5000);
  digitalWrite(relay,LOW);
  Blynk.virtualWrite(V1,LOW);
}

void buzzin()
{
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
}

void denied()
{
  lcd.setCursor(0,3);
  lcd.println("Access Denied");
  terminal.println("Wrong Card Places");
  digitalWrite(buzzer,HIGH);
  delay(2000);
  digitalWrite(buzzer,LOW);
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
  Serial.print(" ");

  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.print(p_tm->tm_mday);
  lcd.print("/");
  lcd.print(p_tm->tm_mon + 1);
  lcd.print("/");
  lcd.print(p_tm->tm_year + 1900);
  lcd.setCursor(0,1);
  lcd.print("Time");
  if((p_tm->tm_hour)>12)
    lcd.print((p_tm->tm_hour)-12);
  else 
    lcd.print((p_tm->tm_hour));
  lcd.print(":");
  lcd.print((p_tm->tm_min));
  //lcd.println(p_tm->tm_sec);
  lcd.print(" ");
  if((p_tm->tm_hour)>=12)
    lcd.print("PM");
  else
    lcd.print("AM");
  
  delay(1000);
}

void sendtime()
{
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  
  terminal.print(p_tm->tm_mday);
  terminal.print("/");
  terminal.print(p_tm->tm_mon + 1);
  terminal.print("/");
  terminal.print(p_tm->tm_year + 1900);
  terminal.print(" ");
  terminal.print((p_tm->tm_hour));
  terminal.print(":");
  terminal.print((p_tm->tm_min));
  terminal.print(":");
  terminal.println(p_tm->tm_sec);
}

void check()
{
  if(sf==s)
  {
    terminal.print("Welcome ");
    sendtime();
    access();
  }
  else
  {
    denied();
  }
}

/*void getkey()
{
  
  int value=analogRead(A0);
  for(int i=0;i<16;i++)
  {
    if(abs(value-thresholds[i])<5)
    {
      Serial.println(keypad[i]);
      if(keypad[i]=='B')
      {
        check();
        s="";
      }
      else
      {
        s=s+" ";
      }
      while(analogRead(A0)<1000){delay(100);}
    }
  }
}*/
