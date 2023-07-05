#include<ArduinoJson.h>
const char* json="{\"success\":1,\"tot\":9,\"led\":[1,2,3,4,5,6,7,8,9],\"status\":[7,2,3,4,5]}";
void setup() {
  Serial.begin(9600);
  StaticJsonDocument<500> doc;

  DeserializationError err = deserializeJson(doc,json);

  if(err){
    Serial.println("Error: ");
    Serial.println(err.c_str());
    return;
  }

  int a=doc["success"];
  int led=doc["led"][0];
  int siz=doc["tot"];
  int statu=doc["status"][0];
  Serial.println(siz);
 // Serial.println(led);
 // Serial.println(statu);
}

void loop() {
}
