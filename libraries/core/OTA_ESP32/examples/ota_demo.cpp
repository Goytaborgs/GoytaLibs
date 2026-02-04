#include <Arduino.h>
#include <WiFi.h>
#include "OTA_ESP32.h"

/* =========================================================
 * CONFIGURATION
 * ========================================================= */

// Wi-Fi credentials
const char* WIFI_SSID     = "your_wifi_ssid";
const char* WIFI_PASSWORD = "your_wifi_password";

// OTA configuration
const char* DEVICE_HOSTNAME = "esp32-device";
const char* OTA_PASSWORD    = "ota_password";   // Optional

// On-board LED (change if needed)
#define LED_PIN 2

/* =========================================================
 * SETUP
 * ========================================================= */

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);   // LED ON during boot

    Serial.begin(115200);
    delay(1000);

    Serial.println("\nBooting ESP32 OTA example");

    /*
     * Initialize Wi-Fi and OTA services.
     * This must be called once during setup().
     */
    OtaManager::begin(
        WIFI_SSID,
        WIFI_PASSWORD,
        DEVICE_HOSTNAME,
        OTA_PASSWORD
    );

    digitalWrite(LED_PIN, LOW);    // LED OFF after setup
}

/* =========================================================
 * LOOP
 * ========================================================= */

void loop()
{
    /*
     * OTA handler must be called continuously.
     * It is non-blocking and allows firmware updates
     * while the application is running.
     */
    OtaManager::handle();

    // Simple heartbeat to show the firmware is running
    static uint32_t last_toggle = 0;
    if (millis() - last_toggle > 1000)
    {
        last_toggle = millis();
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        Serial.println("Device running...");
    }
}
