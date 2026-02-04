/********************************************************************
 * File: OtaManager.h
 * Description: A C++ helper class for managing Wi-Fi connection and
 *              Over-The-Air (OTA) firmware updates on ESP32 devices.
 *              This class provides a simple static interface to
 *              initialize OTA services and handle OTA events during
 *              runtime.
 *
 * Dependencies:
 *  - Arduino.h
 *
 * Created by: Heverton Souza - February 4, 2026
 ********************************************************************/

#pragma once

#include <Arduino.h>

class OtaManager
{
public:
    /**
     * @brief Initializes Wi-Fi and enables OTA updates.
     *
     * This method must be called once inside the setup() function.
     * It connects the ESP32 to the specified Wi-Fi network and
     * configures the OTA service with optional hostname and password.
     *
     * Example usage:
     * @code
     * OtaManager::begin(
     *     "MyWiFiNetwork",
     *     "MyWiFiPassword",
     *     "esp32-robot",
     *     "ota_password"
     * );
     * @endcode
     *
     * @param wifi_ssid  Wi-Fi network SSID.
     * @param wifi_pass  Wi-Fi network password.
     * @param hostname   Device hostname on the network (optional).
     *                   If nullptr, a default hostname will be used.
     * @param ota_pass   OTA update password (optional).
     */
    static void begin(
        const char* wifi_ssid,
        const char* wifi_pass,
        const char* hostname = nullptr,
        const char* ota_pass = nullptr
    );

    /**
     * @brief Handles OTA events.
     *
     * This method must be called repeatedly inside the loop() function.
     * It is non-blocking and allows OTA updates to be received while
     * the application is running.
     */
    static void handle();

private:
    /**
     * @brief Connects the ESP32 to a Wi-Fi network.
     *
     * @param ssid Wi-Fi network SSID.
     * @param pass Wi-Fi network password.
     */
    static void setup_wifi(const char* ssid, const char* pass);
};
