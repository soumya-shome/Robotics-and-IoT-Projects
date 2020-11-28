#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>
#include <ezTime.h>
#include <Wire.h>
#include "RTClib.h"

#define DETECT_NO_INTERNET

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int token[4];

Timezone myLocalTime; 

ESP8266WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

void cal(String ip){
  ip=ip+".";
  int a=0;
  int b=0;
  for(int i=0;i<ip.length();i++){
    char c=ip.charAt(i);
    if(c!='.'){
      a=a*10+(c-'0');
    }
    else{
      token[b]=a;
      a=0;
      b++;
    }
  }
}

char webpage[] PROGMEM = R"=====(
<html>
<head>
<script>
  var Socket;
  var R = 0;
  var G = 0;
  var B = 0;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
    }
    function hexToR(h) {return parseInt((cutHex(h)).substring(0,2),16)}
  function hexToG(h) {return parseInt((cutHex(h)).substring(2,4),16)}
  function hexToB(h) {return parseInt((cutHex(h)).substring(4,6),16)}
  function cutHex(h) {return (h.charAt(0)=="#") ? h.substring(1,7):h}
    function sendColour(){
    var get=document.getElementById("col").value;
      R = hexToR(get);
      G = hexToG(get);
      B = hexToB(get); 
      var RGB='R'+R.toString()+'G'+G.toString()+'B'+B.toString();
    document.getElementById("put").value=RGB;
      send_data();
  }
  function resetTime(){
    Socket.send('{ "Mode": 2 }');
  }
  
  function send_data()
  {
    var full_data = '{"Mode" : 1 , "R" :'+R+',"G":'+G+',"B":'+B+'}';
    Socket.send(full_data);
  }
</script>
</head>
<body onload="javascript:init()">
  <div>
  <input type="color" value="#ff0000" id ="col" oninput="sendColour()"><br>
    <input type="text" id="put">
   </div>  
  <div>
    Reset Time : <input type="button" id="rese" onClick="resetTime()" value="Reset With Current Time">
  </div>
  
</body>
</html>
)=====";


int r=255,g=0,b=0;

WiFiManager wifiM;

const char* host = "httpbin.org";

bool hasInternet = false; 

const bool debug = false;

int ok=1;

#define i 13

#define PIN            0
#define NUMPIXELS      58
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int connectWifi(int retryDelay=500){
  Serial.print("Connecting to ");
//  Serial.println(ssid);
  hasInternet=false; 
  wifiM.autoConnect("Techie99","password"); 
  wl_status_t wifiStatus = WL_IDLE_STATUS;
  while (wifiStatus != WL_CONNECTED) {
    wifiStatus = WiFi.status();
    switch(wifiStatus){
      case WL_NO_SSID_AVAIL:
          Serial.println("SSID not available");
          hasInternet=false;
          break;
      case WL_CONNECT_FAILED:
          Serial.println("Connection failed");
          hasInternet=false;
          break;
      case WL_CONNECTION_LOST:
          Serial.println("Connection lost");
          hasInternet=false;
          break;
      case WL_DISCONNECTED:
          Serial.println("WiFi disconnected");
          hasInternet=false;
          break;
    }
    delay(retryDelay);
  }
  hasInternet = true;
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

/*void check(){
  if(debug)
  {
    //Serial.print("hasInternet ");
    //Serial.println(hasInternet);
  }
  wl_status_t wifiStatus = WiFi.status();
  if(wifiStatus != WL_CONNECTED){
      //Serial.println("Lost WiFi connection, reconnecting...");
      connectWifi(500);
  }
  //else 
    //Serial.println("WiFi OK");
  //Serial.print("Connecting to ");
  //Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    //Serial.println("Connection failed!!!");
    hasInternet=false;
    
    return;
  }
  hasInternet=true;
  
  String url = "/get";
  //Serial.print("Requesting URL: ");
  //Serial.println(host+url); 
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(10);
  while(client.available()){
    String line = client.readStringUntil('\r');
    //Serial.print(line);
  }
  //Serial.println("closing connection");
  //Serial.println();
  ok=1;
}*/

void setup(){
  Serial.begin(115200);
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");    
  }
  Serial.println("\n Starting");
  
  wifiM.autoConnect("Techie99","password");
  Serial.println("connected...yeey :)");
  /*while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }*/
  pixels.begin();
  Serial.println("");
  server.begin();
  server.on("/",[](){
    server.send_P(200, "text/html", webpage);  
  });
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  rtc.begin();
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");    
  }
  pinMode(i,INPUT_PULLUP);
}

void loop(){
  tim();
  webSocket.loop();
  server.handleClient();
  if(digitalRead(i)==0){
    String ip=WiFi.localIP().toString();
    Serial.println(ip);
    cal(ip);
    Serial.println(WiFi.localIP());
    Serial.println(token[0]);
  Serial.println();
  Serial.println(token[1]);
  Serial.println();
  Serial.println(token[2]);
  Serial.println();
  Serial.println(token[3]);
    delay(1000);
  }
}

/*void showIP(){
  drawdigit(0,r,g,b,minu%10);
  drawdigit(14,r,g,b,minu/10);
  drawdigit(28,r,g,b,hours%10);
  drawdigit(42,r,g,b,hours/10);

  drawdigit(0,r,g,b,minu%10);
  drawdigit(14,r,g,b,minu/10);
  drawdigit(28,r,g,b,hours%10);
  drawdigit(42,r,g,b,hours/10);

  drawdigit(0,r,g,b,minu%10);
  drawdigit(14,r,g,b,minu/10);
  drawdigit(28,r,g,b,hours%10);
  drawdigit(42,r,g,b,hours/10);
}*/

void tim(){
  DateTime now = rtc.now();
  /*Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();*/
  int hours=now.hour();
  int minu=now.minute();
  int times = hours*100 + minu;
  //Serial.println(times);
  drawdigit(0,r,g,b,minu%10);
  drawdigit(14,r,g,b,minu/10);
  drawdigit(28,r,g,b,hours%10);
  drawdigit(42,r,g,b,hours/10);
  pixels.setPixelColor(56, pixels.Color(r,g,b));
  pixels.setPixelColor(57, pixels.Color(r,g,b));
  
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){
  if(type == WStype_TEXT){
    Serial.printf("[%u] get Text: %s\n", num, payload);
    String message = String((char*)( payload));
    Serial.println(message);
    
    DynamicJsonDocument doc(200);
    DeserializationError error = deserializeJson(doc, message);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
     }
    if(doc["Mode"]==1){
      r = doc["R"];
      g = doc["G"];
      b = doc["B"];
      Serial.print("R=");
      Serial.print(r);
      Serial.print("G=");
      Serial.print(g);
      Serial.print("B=");
      Serial.print(b);
      Serial.println();
    }
    else if (doc["Mode"]==2){
      seTTime();
    }  
  }
}

void seTTime(){
  //check();
  if(ok==1){
    Serial.println("All Ok");
  }
  else{
    Serial.println("Not Ok");
    return;
  }
  myLocalTime.setLocation(F("Asia/Kolkata"));
  waitForSync();
  Serial.println("Setting Time");
  int y =  myLocalTime.dateTime("Y").toInt();
  int m = myLocalTime.dateTime("m").toInt();
  int d =  myLocalTime.dateTime("d").toInt();
  int h = myLocalTime.dateTime("H").toInt();
  int mi =  myLocalTime.dateTime("i").toInt();
  int s = myLocalTime.dateTime("s").toInt();
  Serial.println(myLocalTime.dateTime("H:i:s"));
  Serial.println(myLocalTime.dateTime("d.m.Y"));
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  rtc.adjust(DateTime(y, m, d, h, mi, s));
  delay(1000);
}

void drawdigit(int offset, int r, int g, int b, int n)
{
  if (n==2 || n==3 || n== 4 || n==5 || n==6 || n==8 || n==9 )//A
  {
    pixels.setPixelColor(0+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(1+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(0+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(1+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==2 || n==6 || n== 8)//B
  {
    pixels.setPixelColor(2+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(3+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(2+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(3+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==2 || n==3 || n== 5 || n==6 || n==8 || n==9)//C
  {
    pixels.setPixelColor(4+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(5+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(4+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(5+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==1 || n==3 || n==4 || n==5 || n==6|| n==7 || n==8 || n==9)//D
  {
    pixels.setPixelColor(6+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(7+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(6+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(7+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==1 || n== 2 || n==3 || n==4 || n==7 || n==8 || n==9)//E
  {
    pixels.setPixelColor(8+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(9+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(8+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(9+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==2 || n== 3 || n==5 || n==6 || n==7 || n==8 || n==9)//F
  {
    pixels.setPixelColor(10+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(11+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(10+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(11+offset, pixels.Color(0,0,0));
  }
  if (n==0 || n==4 || n==5 || n== 6 || n==8 || n==9 )//G
  {
    pixels.setPixelColor(12+offset, pixels.Color(r,g,b));
    pixels.setPixelColor(13+offset, pixels.Color(r,g,b));
  }
  else
  {
    pixels.setPixelColor(12+offset, pixels.Color(0,0,0));
    pixels.setPixelColor(13+offset, pixels.Color(0,0,0));
  }
  pixels.show();
}
