# URBAN GLOW: Street Light Fault Detection and Control System


## Description

The **Urban Glow** is an **IoT-based** project designed to monitor and manage street lights automatically. The system detects faults in street lights and controls their operation based on the surrounding light conditions. The project utilizes an **ESP32** microcontroller, **LDR** sensors for light detection, and **Blynk** for real-time monitoring and control via a mobile application.

> [!NOTE]
> This project aims to improve energy efficiency and reduce maintenance costs for street lighting systems.

## Features

- **Automatic Light Control**: Adjusts the brightness of street lights based on ambient light levels.
- **Fault Detection**: Identifies faults in individual street lights and notifies the user.
- **Real-time Monitoring**: Uses Blynk for real-time monitoring and control of street lights through a mobile app.
- **Energy Efficient**: Reduces energy consumption by ensuring lights are only active when needed.

## Circuit Diagram

 ![WhatsApp Image 2024-05-08 at 20 08 18_20070f4b](https://github.com/MSudharsh110305/Urban-Glow/assets/145757061/f0e3b07d-b117-4bef-9c86-a5fd98fd9f57)



## Hardware Requirements

- **ESP32 Microcontroller**
- **Light Dependent Resistors (LDR)**
- **LEDs (for street lights simulation)**
- **LCD Display (I2C)**
- **Resistors** (for LED and LDR)
- **Breadboard and connecting wires**
- **Adapter: 240V AC to 12V DC**
- **Motor Driver: L298**


## Software Requirements

- **Arduino IDE**
- **Blynk Mobile Application** (available for iOS and Android)
- **Blynk Library for Arduino**
- **LCD_I2C Library for Arduino**

## Installation and Setup

### Clone the Repository

```bash
git clone https://github.com/MSudharsh110305/Urban-Glow
cd Urban-Glow
```
## Configure Blynk

- Install the Blynk app on your mobile device.
- Create a new project and note down the Auth Token.
- Add necessary widgets (e.g., LEDs, value displays) to your Blynk project.

## Configure WiFi and Blynk Credentials

Open street_light_fault_detection.ino in Arduino IDE.
Replace placeholders with your WiFi SSID, password, and Blynk Auth Token:
```bash
char auth[] = "Your_Blynk_Auth_Token";
const char* ssid     = "Your_SSID";
const char* password = "Your_WIFI_Password";
```

## Upload the Code

- Connect your ESP32 to your computer.
- Select the correct board and port in Arduino IDE.
- Upload the street_light_fault_detection.ino file to the ESP32.

## Usage

- Once the system is powered, it will automatically connect to the WiFi network.
- The street lights will be controlled based on ambient light levels detected by the LDR sensors.
- Faults in street lights will be detected and displayed on the LCD and notified via the Blynk app.

## Blynk Control

- Open the Blynk app and monitor the status of street lights.
- You can view real-time data and receive alerts for any detected faults.

>You can also control the street lights manually using the Blynk app.
