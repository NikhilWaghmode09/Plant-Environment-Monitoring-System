#include "DHT.h"
#define DHTPIN  18
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int ldrpin = 4;
float dht11_temp;
float dht11_humi;

int sensorVal = 0; 
const int soilPin = 34;
void setup() {
  Serial.begin(115200);
  delay(100);
  dht.begin();// put your setup code here, to run once:

}

void loop() {
  sensorVal= analogRead(soilPin);
  Serial.println("Soil Moisture Value =");
  Serial.println(sensorVal);
  delay(100);
  float l = digitalRead(ldrpin);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(1000);
  if(l == 0)
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
  Serial.println();
  delay(5000);
  // put your main code here, to run repeatedly:

}
