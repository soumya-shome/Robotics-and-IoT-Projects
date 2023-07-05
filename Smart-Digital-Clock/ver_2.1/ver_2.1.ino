#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>
#include <ezTime.h>

Timezone myLocalTime; 

ESP8266WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

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
  function send_data()
  {
    var full_data = '{"R" :'+R+',"G":'+G+',"B":'+B+'}';
    Socket.send(full_data);
  }
</script>
</head>
<body onload="javascript:init()">
  <div>
  <input type="color" value="#ff0000" id ="col" oninput="sendColour()">
    <input type="text" id="put">
   </div>  
  
</body>
</html>
)=====";


int r=255,g=0,b=0;

WiFiManager wifiM;


#define PIN            2
#define NUMPIXELS      58
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  Serial.begin(115200);
  Serial.println("\n Starting");
  wifiM.autoConnect("Techie99","password");
  Serial.println("connected...yeey :)");
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  pixels.begin();
  Serial.println("");
  server.begin();
  server.on("/",[](){
    server.send_P(200, "text/html", webpage);  
  });
  myLocalTime.setLocation(F("Asia/Kolkata"));
  waitForSync();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}





void loop()
{
  webSocket.loop();
  tim();
  server.handleClient();
}

void tim(){
  int hours =  myLocalTime.dateTime("H").toInt();
  int minu = myLocalTime.dateTime("i").toInt();
  int times = hours*100 + minu;
  Serial.println(times);
  drawdigit(0,r,g,b,minu%10);
  drawdigit(14,r,g,b,minu/10);
  drawdigit(28,r,g,b,hours%10);
  drawdigit(42,r,g,b,hours/10);

  pixels.setPixelColor(56, pixels.Color(r,g,b));
  pixels.setPixelColor(57, pixels.Color(r,g,b));
  
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){
  if(type == WStype_TEXT){

    //Serial.printf("[%u] get Text: %s\n", num, payload);
    String message = String((char*)( payload));
    Serial.println(message);
    
    DynamicJsonDocument doc(200);
    DeserializationError error = deserializeJson(doc, message);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
     }
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
