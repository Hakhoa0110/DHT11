#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           
#include <SimpleTimer.h>
#define DHTTYPE DHT11
#define dht_dpin 2

DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;
char auth[] = "NS_cYUCICGid0_Meyw76UR1O4S4fj4O3";
char ssid[] = "HNM";
char pass[] = "giadinhhnm";
float t;
float h;

void setup()
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  float l = 50;
  Serial.println("\n\nHumidity and temperature\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("Current temperature = ");
  Serial.print(t); 
  Serial.print("light = ");
  Serial.print(l); 
  
  Blynk.virtualWrite(V6, t);
  Blynk.virtualWrite(V5, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
