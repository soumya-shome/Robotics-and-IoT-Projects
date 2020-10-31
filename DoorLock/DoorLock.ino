#include <Keypad.h>
#include <Servo.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F , 2,1,0,4,5,6,7,3,POSITIVE);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Servo myServo;



void setup(){
  Serial.begin(9600);
}

String s="";
void loop(){
  char cK = customKeypad.getKey();
  if (cK){
    Serial.println(cK);
    s=s+cK;
  }
  Serial.println(s);
  
}
