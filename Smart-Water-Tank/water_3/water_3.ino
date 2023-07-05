#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include <Keypad_I2C.h>

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

Keypad_I2C I2C_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, keypad_addr, PCF8574 );

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial mySerial(12, 14);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;
String password="1234";

int mode=1;
char keyc;

void setup() { 
  Serial.begin(9600);
  I2C_Keypad.begin(); 
  finger.begin(57600);
  lcd.begin(20,4);
  lcd.backlight();
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

uint8_t readnumber(void) {
  uint8_t num = 0;
  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop()
{
  key();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Mode:");
  lcd.setCursor(5,0);
  lcd.print(mode);
  //Serial.print("Mode:");
  //Serial.println(mode);
  d_mode(mode);
}

void d_mode(int mde){
  if(mde==1){
    //Request_w();
    int id1=getFingerprintIDez();
    if(id1!=-1){
      lcd.setCursor(0,1);
      lcd.print("Success");
      lcd.setCursor(0,2);
      lcd.print("id=");
      lcd.print(id1);
      digitalWrite(led,1);
      delay(2000);
      digitalWrite(led,0);
    }
    else{
      if(finger.getImage()!=FINGERPRINT_NOFINGER){
        lcd.setCursor(0,1);
        lcd.print("Failed");
        delay(1000);
      }
    }
  }
  else if(mde==2){
    int y=ad_ch();
    if(y==1){
      while (! getFingerprintEnroll() );
      Serial.print("ID : ");
      Serial.println(id);
      delay(5000);
    }
    else{
    lcd.setCursor(0,3);
    lcd.print("New Entry Denied");
    delay(2000);
    }
    mode=1;
  }
  else if(mde==3){
    delay(500);
    mode=1;
  }
  else if(mde==4){
    cleardata();
    lcd.setCursor(0,1);
    lcd.print("Data Cleared");
    delay(1000);
    mode=1;
  }
}

int ad_ch(){
  int d=0;
  String p="";
  while(d!=1){
    keyc=' ';
    key();
    if(keyc=='#'){
      d=1;
    }
    else if(keyc!='*'){
      if(keyc=='1'||keyc=='2'||keyc=='3'||keyc=='4'||keyc=='5'||keyc=='6'||keyc=='7'||keyc=='8'||keyc=='9'||keyc=='0'){
        p=p+keyc;
      }
    }
    delay(0);
  }
  if(p.equals(password)){
    Serial.println("OK");
    return 1;
  }
  else{
    return 0;
  }
}

void cleardata(){
  finger.emptyDatabase();
}
uint8_t getFingerprintEnroll() {
  int p = -1;
  finger.getTemplateCount();
  id=(finger.templateCount)+1;
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
  Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
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
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
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
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
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
