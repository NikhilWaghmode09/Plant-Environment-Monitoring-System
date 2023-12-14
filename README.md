# PlantFitBit: Plant Soil Moisture and Environment Monitoring System

## Overview🌟

PlantFitBit is an ESP32-based soil moisture and environment monitoring system designed to provide real-time data on the plant growth related parameters like soil moisture, light intensity, temperature and humidity. This project utilizes the capacitive soil moisture sensor, DHT11 temperature/humidity sensor and LDR module, connecting to the Blynk platform for remote monitoring.

## Features🚨

- **Soil Moisture:** The capacitive soil moisture sensor works on the principle of capacitance unlike the other sensors which work on resitivity, and gives very precise readings.
- **Temperature and Humidity Monitoring:** DHT11 sensor measures temperature and humidity.
- **Remote Monitoring:** Data is sent to the Blynk platform for real-time monitoring and control through Web Interface or Mobile Application.
- **Light Intensity Detection:** The amount of light entering the room is detected using LDR module to determine whether it is day-time or night-time.
- **Serial Monitor:** Real-Time reading are displayed on the Arduino IDE's Serial Monitor and can be used for configuring the system.
- **...**

## Hardware Requirements🔨

- ESP32 microcontroller
- Capacitive Soil Moisture Sensor
- DHT11 Temperature/Humidity Sensor
- LDR Module
- Breadboard and Jumper Wires

## Software Requirements💻

- Arduino IDE
- Blynk App (for remote monitoring)

## Installation and Setup🚀

1. Clone the repository to your local machine.
2. Open the Arduino IDE and install the necessary libraries (Blynk and DHT).
3. Configure your Blynk authentication token, Wi-Fi credentials, and other settings in the code.
4. Connect the sensors and components to the ESP32 according to the wiring diagram.
5. Upload the code to your ESP32.

## Usage☄️

1. Open the Blynk app on your mobile device.
2. Create a new project and obtain the authentication token.
3. Configure the Blynk app with the necessary widgets for temperature, humidity, and moisture level display.
4. Run the ESP32 with the uploaded code.
5. Monitor the gas levels, temperature, and humidity in real-time through the Blynk app.

## Wiring Diagram🔌

![Wiring Diagram](https://github.com/NikhilWaghmode09/Plant-Environment-Monitoring-System/blob/7ee0653dc717d612eae6bd4f7df4bab148dbe6f1/Final%20Circuit%20Fig%20(1).jpg)

## Troubleshooting🛑

- In case of problem realted to WiFi connectivity try using an open WiFi.
- While uploading the code to ESP32 make sure you disconnect DHT11 sensor to avoid upload errors.
- If you encounter issues with moisture readings, check the soil moisture sensor connections.
- For temperature/humidity issues, verify the DHT11 sensor connections.
- Ensure a stable internet connection for Blynk communication through Serial Monitor of Arduino IDE.

## Connect with me👨‍💻

:rocket:[Connect with me on LinkedIn](https://www.linkedin.com/in/nikhil-waghmode-b182b6208/)

:rocket:[Follow me on Twitter](https://twitter.com/NikhilWaghmode_)

:rocket:[Check out my Instagram](https://www.instagram.com/nikhilwaghmode._/?igshid=YmMyMTA2M2Y%3D)

## Contributing🐛

If you'd like to contribute to the SecureSense project, please fork the repository and submit a pull request :)
