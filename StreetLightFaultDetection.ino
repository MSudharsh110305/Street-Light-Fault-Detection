
#define BLYNK_PRINT Serial  
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define your Blynk Template ID and Auth Token here
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "AUTOMATIC STREET LIGHT"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

char auth[] = BLYNK_AUTH_TOKEN;

// Define your WiFi credentials
const char* ssid = "Your_SSID"; 
const char* password = "Your_WIFI_Password";

#include <LCD_I2C.h>
LCD_I2C lcd(0x27); 

// Pin definitions
#define ldr11 34
#define ldr22 35
#define ldr33 32
#define ldr44 33

#define led1 27 
#define led2 14 
#define led3 12 
#define led4 19 
#define led5 5
#define led6 18

#define pwm1 26
#define pwm2 16
#define pwm3 17

int ldr1, ldr2, ldr3, ldr4;

void setup() {
    Serial.begin(9600);
    
    pinMode(ldr11, INPUT);
    pinMode(ldr22, INPUT);
    pinMode(ldr33, INPUT);
    pinMode(ldr44, INPUT);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);

    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(pwm3, OUTPUT);

    lcd.begin();         
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("STREET LIGHT");
    lcd.setCursor(0, 1);
    lcd.print("FAULT SYSTEM");

    Blynk.begin(auth, ssid, password, "blynk.cloud", 80);
    lcd.clear();
}

void loop() {
    ldr1 = analogRead(ldr11);
    ldr2 = analogRead(ldr22);
    ldr3 = analogRead(ldr33);
    ldr4 = analogRead(ldr44);

    ldr1 = map(ldr1, 0, 4095, 0, 100);
    ldr2 = map(ldr2, 0, 4095, 0, 100);
    ldr3 = map(ldr3, 0, 4095, 0, 100);
    ldr4 = map(ldr4, 0, 4095, 0, 100);

    if (ldr4 > 40 && ldr4 < 60) {
        analogWrite(pwm1, 50);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);

        analogWrite(pwm2, 50);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);

        analogWrite(pwm3, 50);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);

        Serial.println("6 o'clock ");
        Blynk.virtualWrite(V1, "6 O'CLOCK");
    } else if (ldr4 > 61 && ldr4 < 80) {
        analogWrite(pwm1, 100);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);

        analogWrite(pwm2, 100);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);

        analogWrite(pwm3, 100);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        
        Serial.println("7 o'clock ");
        Blynk.virtualWrite(V1, "7 O'CLOCK");
    } else if (ldr4 > 81 && ldr4 <= 100) {
        analogWrite(pwm1, 180);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);

        analogWrite(pwm2, 180);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);

        analogWrite(pwm3, 180);
        digitalWrite(led5, HIGH);
        digitalWrite(led6, LOW);
        
        Serial.println("8 o'clock ");
        Blynk.virtualWrite(V1, "8 O'CLOCK");
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        
        Blynk.virtualWrite(V1, " ");
    }

    if (ldr1 > 90 && ldr4 > 40) {
        Serial.println("Light 1 fault");
        Blynk.virtualWrite(V0, "LIGHT 1 FAULT");
        Blynk.logEvent("msg", "LIGHT 1 FAULT");
        lcd.setCursor(0, 0);
        lcd.print("LIGHT 1 FAULT");
        lcd.setCursor(0, 1);
        lcd.print(" ");
        delay(4000);
        lcd.clear();
    }

    if (ldr2 > 90 && ldr4 > 40) {
        Serial.println("Light 2 fault");
        Blynk.virtualWrite(V0, "LIGHT 2 FAULT");
        Blynk.logEvent("msg", "LIGHT 2 FAULT");
        lcd.setCursor(0, 0);
        lcd.print("LIGHT 2 FAULT");
        lcd.setCursor(0, 1);
        lcd.print(" ");
        delay(4000);
        lcd.clear();
    }

    if (ldr3 > 90 && ldr4 > 40) {
        Serial.println("Light 3 fault");
        Blynk.virtualWrite(V0, "LIGHT 3 FAULT");
        Blynk.logEvent("msg", "LIGHT 3 FAULT");
        lcd.setCursor(0, 0);
        lcd.print("LIGHT 3 FAULT");
        lcd.setCursor(0, 1);
        lcd.print(" ");
        delay(4000);
        lcd.clear();
    } else {
        Blynk.virtualWrite(V0, " ");
    }

    delay(700);
}
