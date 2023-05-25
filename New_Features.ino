/*CODES FOR THE DEVICE "TEST BLYNK" #define BLYNK_TEMPLATE_ID "TMPL3TwzXJHWX"
#define BLYNK_TEMPLATE_NAME "TEST BLYNK"
#define BLYNK_AUTH_TOKEN "KL1nVMXMcmJSxDLfMNBPsNFZ9OVWtZBc"*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels    //sda d21 sck d22
#define SCREEN_HEIGHT 64 // OLED height, in pixels
// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define BLYNK_TEMPLATE_ID "TMPL3tReFI-np"
#define BLYNK_DEVICE_NAME "ESP32 Plant Watering"
#define BLYNK_AUTH_TOKEN "hIJU5YHeXJDSRVPGevsgFwQ5g5QXWOWg"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define SensorPin       34  //D34 
int     sensorVal;
int     moistper;
bool    autoval;
#include "DHT.h"
#define DHTPIN 18     //D18
#define DHTTYPE DHT11
#define relayPin 32    //D32

DHT dht(DHTPIN, DHTTYPE);

float dht11_temp;
float dht11_humi;

BLYNK_WRITE(V5) {
  bool rvalue = param.asInt();
  if (rvalue == 1) {
    digitalWrite(relayPin, LOW);
  } 
  else {
    digitalWrite(relayPin, HIGH);
  }
}

 //FOR AUTO WATER SUPPLY
 BLYNK_WRITE(V4) {
   autoval = param.asInt();
   
 }


// Define the calibration values
const int dryReading = 4095;  // Sensor value when in air
const int wetReading = 0;  // Sensor value when in a wet condition

// Function to map sensor readings to moisture percentage
float mapToMoisturePercentage(int sensorVal) {
  // Clamp the sensor reading within the range of dry and wet readings
  sensorVal = constrain(sensorVal, wetReading, dryReading);
  
  // Calculate the moisture percentage using linear interpolation
  float moisturePercentage = 100.0 - ((float)(sensorVal - wetReading) / (dryReading - wetReading)) * 100.0;
  
  // Clamp the moisture percentage within the range of 0-100%
  moisturePercentage = constrain(moisturePercentage, 0, 100);
  
  return moisturePercentage;
}

// Function to map sensor readings to moisture value
float mapToMoistureValue(int  sensorVal) {
  // Clamp the sensor reading within the range of dry and wet readings
  sensorVal = constrain( sensorVal, wetReading, dryReading);

  // Calculate the moisture value using linear interpolation
  float moistureValue = (float)(dryReading -  sensorVal);

  // Clamp the moisture value within the range of 0-4095
  moistureValue = constrain(moistureValue, 0, 4095);

  return moistureValue;
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  Serial.begin(115200);
  delay(100);
  WiFi.begin("Nikhil's A51", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  dht.begin();
  // Initialize Blynk
//  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi.SSID().c_str(), WiFi.psk().c_str());
   
}

void loop() {
  Blynk.run();
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  sensorVal = analogRead(SensorPin);
  // Map the sensor reading to moisture value
  float moistureValue = mapToMoistureValue(sensorVal);

  // Map the sensor reading to moisture percentage
  float moisturePercentage = mapToMoisturePercentage(sensorVal);
  
  // Display the moisture value
  Serial.print("Moisture Value: ");
  Serial.print(moistureValue);
  Serial.println();

  // Display or use the moisture percentage as needed
  Serial.print("Moisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
  Blynk.virtualWrite(V1, moistureValue);
  
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 10);       // set position to display
  oled.print("Moisture Value: ");
  oled.print(moistureValue);
  oled.println();

  oled.print("Moisture Percentage: ");
  oled.print(moisturePercentage);
  oled.println("%");

  //Serial.println(autoval);
  if(autoval == 1){
     if(moistureValue<1000){
      digitalWrite(relayPin, LOW);// put your main code here, to run repeatedly:
     }
     else{
       digitalWrite(relayPin, HIGH);
     }
   }
   else{
     digitalWrite(relayPin, HIGH);
   }
  // set text
  oled.display();              // display on OLED
  delay(1000);
  
  
}
