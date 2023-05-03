/*CODES FOR THE DEVICE "TEST BLYNK" #define BLYNK_TEMPLATE_ID "TMPL3TwzXJHWX"
#define BLYNK_TEMPLATE_NAME "TEST BLYNK"
#define BLYNK_AUTH_TOKEN "KL1nVMXMcmJSxDLfMNBPsNFZ9OVWtZBc"*/
#include "DHT.h"
#define DHTPIN 18
#define DHTTYPE DHT11
#define BLYNK_TEMPLATE_ID          "TMPLe0U067rR"
#define BLYNK_DEVICE_NAME           "ESP PBL"
#define BLYNK_AUTH_TOKEN            "N1_Vth27MI_uYRWi95zzggkFYVFjvq52"

#define BLYNK_FIRMWARE_VERSION          "0.1.0"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define APP_DEBUG


DHT dht(DHTPIN, DHTTYPE);

float dht11_temp;
float dht11_humi;

int ldrpin = 4;

int sensorVal = 0;
const int soilPin =34;

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin("realme C11", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize Blynk
  dht.begin();
  
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi.SSID().c_str(), WiFi.psk().c_str());
}

void loop() {
  Blynk.run();
 
  sensorVal=analogRead(soilPin);
  Serial.println("Soil Moisture Value =");
  Serial.println(sensorVal);
  //float l = analogRead(ldrpin);
  float l1 = digitalRead(ldrpin);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Blynk.virtualWrite(V0, sensorVal);
  //Blynk.virtualWrite(V1, l);
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
  Blynk.virtualWrite(V4, l1);
  if(l1 == 0)
  {
    Serial.println("PLANT IS GETTING ENOUGH LIGHT :)");
  }
  else
  {
    
    Serial.println("PLANT IS NOT GETTING ENOUGH LIGHT :/");
  }
  delay(1000);
  Serial.println("Humidity =");
  Serial.println(h);
  Serial.println("Temperature = ");
  Serial.println(t);
  delay(1000);
}
