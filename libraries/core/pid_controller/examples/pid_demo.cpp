#include "pid_controller.h"
#include <Arduino.h>

// --- PID controller instance (Kp, Ki, Kd) ---
pid_controller pid(1.0f, 0.5f, 0.1f);

// --- Motor parameters ---
const int16_t  MIN_SPEED   = 0;
const uint16_t MAX_SPEED   = 255;
const int16_t  MOTOR_BIAS  = 100;   // Offset to compensate mechanical asymmetry

// --- Desired set‑point (angle, speed, distance) ---
float setpoint = 50.0f;

// --- Fake sensor variable (replace with real encoder/IMU reading) ---
float feedback = 0.0f;

// --- Timing helpers ---
unsigned long last_time = 0;

void setup()
{
    Serial.begin(115200);
    delay(500);
    Serial.println("\n=== PID Controller Demo ===");

    // Example of changing gains on the fly
    pid.set_parameters(1.2f, 0.4f, 0.05f);
    Serial.println("PID gains updated via setParameters().");
}

void loop()
{
    unsigned long current_time = millis();
    float delta_time = (current_time - last_time) / 1000.0f;   // Convert to seconds

    /* ----------------------------------------------
       Simulate a sensor reading.
       Replace this block with your real sensor logic:
       e.g., encoder counts, IMU yaw angle, etc.
    ---------------------------------------------- */
    feedback += random(-3, 4);   // Adds a small random variation

    // --- Compute PID control signal ---
    int control = pid.pid_calculation(setpoint, feedback, delta_time);

    // --- Translate control signal into motor speeds ---
    int16_t right_speed = pid.right_motor_speed(MIN_SPEED, MAX_SPEED, MOTOR_BIAS, control);
    int16_t left_speed  = pid.left_motor_speed (MIN_SPEED, MAX_SPEED, MOTOR_BIAS, control);

    /* ----------------------------------------------
       Here you would actually drive your motors:
       motorR.run(right_speed);
       motorL.run(left_speed);
    ---------------------------------------------- */

    // --- Debug output over Serial ---
    Serial.print("SP: ");  Serial.print(setpoint);
    Serial.print(" | FB: "); Serial.print(feedback);
    Serial.print(" | Error: "); Serial.print(setpoint - feedback);
    Serial.print(" | Ctrl: ");  Serial.print(control);
    Serial.print(" | R: ");     Serial.print(right_speed);
    Serial.print(" | L: ");     Serial.println(left_speed);

    last_time = current_time;
    delay(50);   // Small pacing delay (adjust as needed)
}
