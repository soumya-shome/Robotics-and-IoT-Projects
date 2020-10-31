#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include <NTPClient.h>
#include <Arduino.h>
#include <TM1637Display.h>
#include <WiFiUdp.h>
//#define TRIGGER_PIN 4
#define CLK 2
#define DIO 0
WiFiManager wifiM;
WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 19800;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  Serial.println("\n Starting");
  wifiM.autoConnect("Techie99","password");
  Serial.println("connected...yeey :)");
  //pinMode(TRIGGER_PIN, INPUT);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
  display.setBrightness(0x0f);
}


void loop() {
  /*if ( digitalRead(TRIGGER_PIN) == LOW ) {
    if (!wifiM.startConfigPortal("Techie99","password")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      ESP.reset();
      delay(5000);
    }
    Serial.println("connected...yeey :)");
  }*/
  timeClient.update();
  int times=0;
  times=times+(timeClient.getHours()*100);
  times=(timeClient.getHours()*100)+timeClient.getMinutes();
  Serial.println(times);
  display.showNumberDecEx(times, 0b11100000, true, 4, 0);
}
