#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include<ArduinoJson.h>
String host = "192.168.43.170";
String url="/Project Water/page4.php";

WiFiClient client;
const int httpPort = 80;
StaticJsonDocument<500> doc;

#define RST_PIN  2
#define SS_PIN   15

char ssid[] = "Soumyadeep";
char pass[] = "10967bubu";
String card="";
MFRC522 mfrc522(SS_PIN, RST_PIN);
int Mode=0;
void setup()
{
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
  Serial.print("Connecting");
  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
  delay(1000);
  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP());
  delay(2000);
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();
  mfrc522.PCD_Init();
  //mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  delay(5000);
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

String ReadCard(){
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return "";
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return "";
  }
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  return content.substring(1)+" ";
}

void loop()
{
   if(digitalRead(4)==0){
    Serial.println("Mode 1");
    Mode=1;
    delay(200);
  }
  if(digitalRead(5)==0){
    delay(300);
    if(digitalRead(5)==0){
      Serial.println("Mode 3");
      Mode=3;
      delay(500);
    }
    else{
      Serial.println("Mode 2");
      Mode=2;
      delay(500);
    }
  }
  card=ReadCard();
  if(card!=""){
    if(Mode==1){
      Serial.println(card);
      if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
      }
      url="/Project_Water/page4.php";
      card.trim();
      String card2="";
      for(int i=0;i<=card.length();i++){
        if(card.charAt(i)!=' '){
          card2=card2+card.charAt(i);
        }
      }
      //url=url+"?card="+card+"/";
      url=url+"?card="+card2;
      Serial.println("URL : "+host+url+"-->");
      Serial.println("<--Requesting URL-->");
      
      client.print(String("GET ")+url+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"Connection: close\r\n\r\n");
      //Serial.print(String("GET ")+url+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"Connection: close\r\n\r\n");
      delay(50);
      
      while(client.available()){
        String line=client.readStringUntil('\r');
        Serial.println("Line : "+line);
        if(line.charAt(1)=='{'){
          String result=line.substring(1);
          //Serial.println(result);
          DeserializationError err = deserializeJson(doc,result);
          if(err){
            Serial.println("Error: ");
            Serial.println(err.c_str());
            return;
          }
          String a=doc["success"];
          String b=doc["message"];
          String c=doc["status"];
          Serial.println("Success : "+a);
          Serial.println("Message : "+b);
          Serial.println("Status : "+c);
       } 
      }
      
      delay(5000);
      Serial.println();
    }
  }
}
