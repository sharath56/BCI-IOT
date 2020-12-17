#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
const int relay = D3;
//const int relay = D4;
// Network Parameters
const char* ssid     = "pi";
const char* password = "sharath@123";

// ThingSpeak information
char* server = "api.thingspeak.com";
unsigned long channelID =  1260898;
char* readAPIKey = "QBG4QPZEPJQS3707";
unsigned int dataFieldOne = 4;                            // Field to write temperature data

// Global variables
// These constants are device specific.  You need to get them from the manufacturer or determine them yourself.
float aConst = 2.25E-02;
WiFiClient client;

void setup() {

  Serial.begin(115200);
  Serial.println("Start");
  pinMode(relay, OUTPUT);
 // pinMode(relay,OUTPUT);
  connectWiFi();

  // Read the constants at startup.
  aConst = readTSData( channelID, dataFieldOne );
  //Serial.println(aConst);
  delay(100);
}

void loop() {

  delay(10);
  Serial.println("Waiting...");
  //reading data from thing speak
  aConst = readTSData( channelID, dataFieldOne );
 // Serial.println(aConst);
}

int connectWiFi() {
  WiFi.begin( ssid, password );
  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    Serial.print(".");
  }

  Serial.println( "Connected" );
  ThingSpeak.begin( client );
}

float readTSData( long TSChannel, unsigned int TSField )
{

  float data =  ThingSpeak.readFloatField( TSChannel, TSField, readAPIKey );
  //Serial.println( " Data read from ThingSpeak: " + String( data, 10) );
  //return data;
  Serial.println(data);
  
 if (data >= 20 && data<=50)
 {
   digitalWrite(relay, LOW);
   
   //digitalWrite(motorPin, LOW);
 }
 else if (data > 50)
 {
  digitalWrite(relay, HIGH);
  //digitalWrite(motorPin, HIGH)
 }

}
