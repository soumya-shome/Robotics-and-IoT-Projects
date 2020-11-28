*************
//
// SUCCESSFULL
//
*************
#include <ESP8266WiFi.h>
char ssid[] = "Soumyadeep";
char pass[] = "10967bubu";
void setup() {
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
}

void loop() {
}
