#include "DHT.h"
#include<WiFi.h>
#include "ThingSpeak.h"
#define DHTPIN 5
#define DHTTYPE DHT11

const char* wifiname = "vivo Y31";
const char* wifipass = "$$connect$$";
unsigned long channelid = 3210084;
const char* apikey = "VM4SC15ZGW769JFU";
WiFiClient client;

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiname,wifipass);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("wifi connecting...");
    delay(500);
  }
  Serial.println("\nWiFi connected");
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println("C");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  ThingSpeak.setField(1,t);
  ThingSpeak.setField(2,h);
  int x = ThingSpeak.writeFields(channelid,apikey);
  if(x == 200)
  {
    Serial.println("Data updated on thingspeak");
  }
  else
  {
    Serial.println("Data not sent");
  }
  delay(2000);

}
