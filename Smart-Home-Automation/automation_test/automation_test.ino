#include <Keypad.h>
const byte ROWS = 3;
const byte COLS = 2;
int l[]={0,0,0,0,0,0};
int lp[]={7,8,9,10,11,12};
char hexaKeys[ROWS][COLS] = {
  {'1','2'},
  {'3','4'},
  {'5','6'}};
byte rowPins[ROWS] = {4, 3, 2};
byte colPins[COLS] = {6, 5};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(lp[0],OUTPUT);
  pinMode(lp[1],OUTPUT);
  pinMode(lp[2],OUTPUT);
  pinMode(lp[3],OUTPUT);
  pinMode(lp[4],OUTPUT);
  pinMode(lp[5],OUTPUT);
}

void up(int a){
  int s;
  if(l[a]==0)
    s=1;
  else
    s=0;
  l[a]=s;
}

void glo(){
  for(int i=0;i<6;i++){
    //digitalWrite(lp[i],l[i]);
    Serial.print(l[i]);
    Serial.print(",");
  }
  Serial.println();
}

void loop(){
  glo();
  char customKey = customKeypad.getKey();
  if (customKey){
    Serial.println(customKey);
    
  }
 
}
