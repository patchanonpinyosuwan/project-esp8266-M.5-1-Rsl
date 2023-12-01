#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define LED D0
#define SPEAKER D8
void setup() 
{
  pinMode(LED,OUTPUT);
  pinMode(SPEAKER,OUTPUT);
}
void loop(){
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);

  digitalWrite(SPEAKER,HIGH);
  delay(500);
  digitalWrite(SPEAKER,LOW);
  delay(500);
}

