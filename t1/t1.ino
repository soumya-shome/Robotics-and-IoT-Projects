//#define BLYNK_PRINT Serial

//#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  2
#define SS_PIN   15


//char auth[] = "f872a20726b54dc4b3bb73247cce4813";
//char ssid[] = "Run Wifi Run";
//char pass[] = "flashpoint";

MFRC522 mfrc522(SS_PIN, RST_PIN);

//WidgetTerminal terminal(V2);

//BLYNK_WRITE(V1)
//{
 // int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
 /* Serial.println(pinValue);
  if(pinValue==1)
  {
    digitalWrite(16,HIGH);
    Serial.println("HIGH");
  //  terminal.println("Welcome Master");
  }
  else
  {
    digitalWrite(16,LOW);
    Serial.println("LOW");
  }*/
  // process received value
//}

void setup()
{
  //pinMode(16,OUTPUT);
  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  //Blynk.run();
  rfid();
}

void rfid()
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;

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
  //terminal.println(content.substring(1)+" ");
  /*if (content.substring(1) == "06 D3 AB 1B")
  {
    Blynk.virtualWrite(V1,HIGH);
    //terminal.println("accepted");
    delay(2000);
    Blynk.virtualWrite(V1,LOW);
    content="";
  }
  else
  {
    Serial.println("Denied");
    delay(500);
  }*/
  content="";
  Serial.println();
}
}
