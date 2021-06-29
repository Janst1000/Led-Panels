#include <Wifi.h>
#include "time.h"

const char* ssid		= "";
const char* password	= "";

void setup(){
  
	Serial.begin(115200);
  pinMode(
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
}

void loop(){
  if(Wifi.status() != WL_CONNECTED){
    
  }
}
