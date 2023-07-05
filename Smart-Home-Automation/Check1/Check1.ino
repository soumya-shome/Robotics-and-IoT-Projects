#include<ArduinoJson.h>
#include <ESP8266WiFi.h>
char ssid[] = "Soumyadeep";
char pass[] = "10967bubu";
String host = "192.168.1.7";
String url="/Automation/p3.php";
WiFiClient client;
const int httpPort = 80;
StaticJsonDocument<500> doc;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  //pinMode(4,OUTPUT);
  //pinMode(5,OUTPUT);
  //pinMode(16,OUTPUT);
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
  int i;
  if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }
    Serial.print("<--Requesting URL-->");
    client.print(String("GET ")+url+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"Connection: close\r\n\r\n");
    delay(50);
    while(client.available()){
      String line=client.readStringUntil('\r');
      if(line.charAt(1)=='{'){
        String result=line.substring(1);
        Serial.println(result);
        DeserializationError err = deserializeJson(doc,result);
        if(err){
          Serial.println("Error: ");
          Serial.println(err.c_str());
          return;
        }
        int a=doc["success"];
        int c=int(doc["tot"]);
        Serial.println("LED No.    Status");
        for(i=0;i<c;i++){
          Serial.print(int(doc["no"][i]));
          Serial.println(int(doc["status"][i]));
          digitalWrite(int(doc["no"][i]),int(doc["status"][i]));
        }
        } 
    }
}
