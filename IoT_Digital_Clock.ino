#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 0

const char *ssid     = "Soumyadeep";
const char *password = "10967bubu";
const long utcOffsetInSeconds = 19800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

TM1637Display display(CLK, DIO);

void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
  display.setBrightness(0x0f);
}

void loop() {
  timeClient.update();
  int times=0;
  times=times+(timeClient.getHours()*100);
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.println(timeClient.getMinutes());
  //Serial.print(":");
  times=(timeClient.getHours()*100)+timeClient.getMinutes();
  Serial.println(times);
  //Serial.println(timeClient.getFormattedTime());
  display.showNumberDecEx(times, 0b11100000, true, 4, 0);
  //delay(50);
  //display.showNumberDec(times, true);
  //delay(50);
}
