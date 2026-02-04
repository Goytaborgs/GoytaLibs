#include "OTA_ESP32.h"
#include <WiFi.h>
#include <ArduinoOTA.h>

void OtaManager::setup_wifi(const char* ssid, const char* pass)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);

    uint32_t start = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(300);
        if (millis() - start > 10000)
        {
            Serial.println("WiFi timeout, OTA disabled");
            return;
        }
    }

    Serial.print("WiFi OK, IP: ");
    Serial.println(WiFi.localIP());
}

void OtaManager::begin(
    const char* wifi_ssid,
    const char* wifi_pass,
    const char* hostname,
    const char* ota_pass)
{
    setup_wifi(wifi_ssid, wifi_pass);

    if (hostname)
        ArduinoOTA.setHostname(hostname);
    else
        Serial.println("NO HOSTNAME SET! DEFAULT SET AS 'ESP32-OTA'\n");
        ArduinoOTA.setHostname("ESP32-OTA");

    if (ota_pass)
        ArduinoOTA.setPassword(ota_pass);

    ArduinoOTA
        .onStart([]() {
            Serial.println("OTA Start");
        })
        .onEnd([]() {
            Serial.println("\nOTA End");
        })
        .onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("OTA: %u%%\r", (progress * 100) / total);
        })
        .onError([](ota_error_t error) {
            Serial.printf("OTA Error[%u]\n", error);
        });

    ArduinoOTA.begin();
    Serial.println("OTA Ready");
}

void OtaManager::handle()
{
    ArduinoOTA.handle();
}
