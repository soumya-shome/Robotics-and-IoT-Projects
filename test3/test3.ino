#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
String ssid = "Soumyadeep";
String password = "10967bubu";
String host = "192.168.1.5";
String url="/Automation/p1.php?id=1";
WiFiClient client;
const int httpPort = 80;
void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

    
}
  void loop()
  {
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
        //Serial.println(line);
        String result=line.substring(1);
        Serial.println(result);
        //int size=result.length()+1;
        //Serial.println(size);
      } 
    }
  }
