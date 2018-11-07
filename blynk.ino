#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "844f201529d547bbb59528d9a8672531";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WiFi@OSU";
char pass[] = "";

BLYNK_READ(V5){
  float sensorData = analogRead(A0);
  float celsius = (sensorData-500)/10;
  Blynk.virtualWrite(V5, celsius);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
