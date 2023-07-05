#include <Keypad.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);  
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();
}

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


void loop() {  
  rfid();                    
   char b = myKeypad.getKey();
  if(b){
    if(b=='1')
    {
      digitalWrite(6, HIGH);
      delay(100);           
      digitalWrite(6, LOW); 
      delay(100);
    }
    else if(b=='2')
    {
      digitalWrite(7, HIGH);
      delay(100);           
      digitalWrite(7, LOW); 
      delay(100);
    }
    Serial.println(b);
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
    access(1);    
  }
  else
  {
    access(0);
  }
  delay(2000);
}


void access(int a)
{
  switch(a)
  {
    case 0:
      digitalWrite(6, HIGH);
      delay(100);           
      digitalWrite(6, LOW); 
      delay(100);
    break;

    case 1:
      digitalWrite(7, HIGH);
      delay(100);           
      digitalWrite(7, LOW); 
      delay(100);
    break;
  }
}
