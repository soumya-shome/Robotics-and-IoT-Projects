#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include <Keypad_I2C.h>

String flno="000A";

String host = "192.168.1.7";
String url="";
WiFiClient client;
const int httpPort = 80;
StaticJsonDocument<500> doc;
char ssid[] = "Soumyadeep";
char pass[] = "10967bubu";
int y;
#define keypad_addr 0X20
#define led 0
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1,0};

uint8_t id;
String password="1234";
int mode=1;
char keyc;
int r=-1;
Keypad_I2C I2C_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, keypad_addr, PCF8574 );
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial mySerial(12, 14);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup(){
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  I2C_Keypad.begin(); 
  finger.begin(57600);
  lcd.begin(20,4);
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.print("Connecting");
  lcd.print("Connecting..");
  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
  delay(1000);
  Serial.println("Wifi Connected Success!");
  lcd.clear();
  lcd.print("Connected");
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  delay(2000);
  pinMode(led,OUTPUT);
}
void loop(){
  key();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mode:");
  lcd.setCursor(5,0);
  lcd.print(mode);
  d_mode(mode);  
}

void d_mode(int mde){
  digitalWrite(led,0);
  if(mde==1){
    int id1=getFingerprintIDez();
    if(id1!=-1){
      digitalWrite(led,1);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("Requesting");
      url="/Project_Water/request_w.php?id="+flno+id1;
      send_data();
    }
    delay(100);
  }
  else if(mde==2){
    finger.getTemplateCount();
    id=(finger.templateCount)+1;
    url="/Project_Water/admin_permit.php?fn="+flno+"&id="+id;
    int y=send_data();
    if(y==1){
      delay(1000);
      r=-1;
      while (! getFingerprintEnroll() ){;
        Serial.print("ID : ");
        Serial.println(id);
      }
      if(r==1){
        url="/Project_Water/register_id.php?id="+flno+id;//send new id
        int z=send_data();
        if(z!=1){
          deleteFingerprint(id);
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("Failed");
        }
      }else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.println("Match UnSuccessfull");
        lcd.print("Try Again");
      }
    }
    delay(2000);
    mode=1;
  }
  else if(mde==3){
    deleteFingerprint(3);
  }
  else if(mde==4){
    url="/Project_Water/del_ids.php?fn="+flno;
    if(send_data()==1){
      cleardata();
      lcd.setCursor(0,1);
      lcd.print("Data Cleared");
    }else{
      lcd.setCursor(0,1);
      lcd.print("Failed");
    }
    delay(2000);
    mode=1;
  }
}

uint8_t send_data(){
  int a,c,d;
  String b;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return -1;
  }
  lcd.setCursor(0,0);
  lcd.print("Requesting...");
  Serial.println("URL : "+host+url+"-->");
  Serial.println("<--Requesting URL-->");   
  client.print(String("GET ")+url+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"Connection: close\r\n\r\n");
  delay(50);
  while(client.available()){
    String line=client.readStringUntil('\r');
    
    if(line.charAt(1)=='{'){
      Serial.println("RECEIVED");
      String result=line.substring(1);
      DeserializationError err = deserializeJson(doc,result);
      if(err){
        Serial.println("Error: ");
        Serial.println(err.c_str());
        return -1;
      }
      a=doc["success"];
      String b2=doc["message"];
      b=b2;
      c=doc["status"];
      d=doc["md"];
    }
  }
  Serial.print("Success : ");
  Serial.println(a);
  Serial.print("Message : ");
  Serial.println(b);
  Serial.print("Status : ");
  Serial.println(c);
  Serial.print("Mode : ");
  Serial.println(d);
  if(d==1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println(b);
      lcd.setCursor(0,3);
      lcd.print("Status: ");
      lcd.print(c);
      delay(5000);
      return a;
  }else if(d==2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(b);
    return a;
  }else if(d==3){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(b);
    return c;
  }else if(d==5){
    return a;
  }
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of ");
  Serial.println(finger.confidence);
  return finger.fingerID; 
}

uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  p = finger.deleteModel(id);
  if (p == FINGERPRINT_OK) {
    lcd.setCursor(0,2);
    lcd.print("Deleted");
    Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
    return p;
  }   
}

void cleardata(){
  finger.emptyDatabase();
}

void key(){
  char key = I2C_Keypad.getKey();
  if(key){
    Serial.println(key);
    if(key=='A'){
      mode=1;keyc=' ';
    }else if(key=='B'){
      mode=2;keyc=' ';
    }else if(key=='C'){
      mode=3;keyc=' ';
    }else if(key=='D'){
      mode=4;keyc=' ';
    }else if(key=='*' || key=='#' || key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'){
      keyc=key;
    }
  }
}

uint8_t getFingerprintEnroll() {
  r=-1;
  lcd.clear();
  int p = -1;
  lcd.setCursor(0,0);
  lcd.print("Place Your Finger:");
  Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }
  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  lcd.setCursor(0,1);
  lcd.print("Remove Finger");
  Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  lcd.setCursor(0,2);
  lcd.print("Place Finger Again");
  Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }
  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  Serial.print("Creating model for #");  Serial.println(id);
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints matched!");
    r=1;
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    r=0;
    return -1;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    r=0;
    return -1;
  } else {
    Serial.println("Unknown error");
    r=0;
    return -1;
  }   
  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  lcd.setCursor(0,3);
  if (p == FINGERPRINT_OK) {
    Serial.println("Stored!");
    lcd.print("Match Successfull");
    r=1;
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    r=0;
    return -1;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    r=0;
    return -1;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    r=0;
    return -1;
  } else {
    Serial.println("Unknown error");
    r=0;
    return -1;
  }   
}
