/*CODES FOR THE DEVICE "TEST BLYNK" #define BLYNK_TEMPLATE_ID "TMPL3TwzXJHWX"
#define BLYNK_TEMPLATE_NAME "TEST BLYNK"
#define BLYNK_AUTH_TOKEN "KL1nVMXMcmJSxDLfMNBPsNFZ9OVWtZBc"*/

#define BLYNK_TEMPLATE_ID          "TMPL3TwzXJHWX"
#define BLYNK_DEVICE_NAME           "TEST BLYNK"
#define BLYNK_AUTH_TOKEN            "KL1nVMXMcmJSxDLfMNBPsNFZ9OVWtZBc"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin("realme C11", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize Blynk
//  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi.SSID().c_str(), WiFi.psk().c_str());
}

void loop() {
  Blynk.run();
  Blynk.virtualWrite(V0, 123);
  delay(1000);
}
