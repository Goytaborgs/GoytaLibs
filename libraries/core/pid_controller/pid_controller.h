/********************************************************************
 * File: pid_controller.h 
 * Description: Simple and efficient C++ PID control library 
 *              for robots with two motors (such as differential 
 *              or rear-wheel drive). Ideal for use with Arduino, 
 *              ESP32, and other embedded systems.
 * 
 * Dependencies: None
 *
 * Created by: Iarley Santos - June 04, 2025
 * Revised by: Heverton Souza
********************************************************************/

#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <cstdint>

class pid_controller
{
public:
    /**
     * @brief Constructor: Initializes the controller with PID constants.
     * 
     * @param kp Proportional gain
     * @param ki Integral gain
     * @param kd Derivative gain
     */
    pid_controller(float kp, float ki, float kd);

    /**
     * @brief Calculates the PID control signal.
     * 
     * Computes the control output based on the current setpoint, feedback, 
     * and time interval since the last calculation.
     * 
     * @param setpoint     Desired value (e.g., target angle or speed)
     * @param feedback     Measured value (e.g., actual angle or speed)
     * @param delta_time   Time interval since last update (in seconds)
     * 
     * @return PID control output (integer, may be positive or negative)
     */
    int pid_calculation(float setpoint, float feedback, float delta_time);

    /**
     * @brief Computes the left motor speed based on PID output and bias.
     * 
     * Applies saturation limits and bias compensation to the control signal.
     * 
     * @param min_speed    Minimum allowed speed (usually zero)
     * @param max_speed    Maximum allowed speed (e.g., 255 for 8-bit PWM)
     * @param motor_bias   Offset to compensate physical differences between motors
     * @param u            PID output value (from pid_calculation)
     * 
     * @return Speed value for the left motor
     */
    int16_t left_motor_speed(int16_t min_speed, uint16_t max_speed, int16_t motor_bias, int u);

    /**
     * @brief Computes the right motor speed based on PID output and bias.
     * 
     * Applies saturation limits and bias compensation to the control signal.
     * 
     * @param min_speed    Minimum allowed speed (usually zero)
     * @param max_speed    Maximum allowed speed (e.g., 255 for 8-bit PWM)
     * @param motor_bias   Offset to compensate physical differences between motors
     * @param u            PID output value (from pid_calculation)
     * 
     * @return Speed value for the right motor
     */
    int16_t right_motor_speed(int16_t min_speed, uint16_t max_speed, int16_t motor_bias, int u);

    // --- Setters for individual PID constants ---

    /**
     * @brief Sets a new proportional gain (Kp).
     * 
     * @param kp New Kp value
     */
    void set_kp(float kp);

    /**
     * @brief Sets a new integral gain (Ki).
     * 
     * @param ki New Ki value
     */
    void set_ki(float ki);

    /**
     * @brief Sets a new derivative gain (Kd).
     * 
     * @param kd New Kd value
     */
    void set_kd(float kd);

    /**
     * @brief Sets all PID gains at once.
     * 
     * @param kp New proportional gain
     * @param ki New integral gain
     * @param kd New derivative gain
     */
    void set_parameters(float kp, float ki, float kd);

private:
    /* PID Constants */
    float _kp;
    float _ki;
    float _kd;

    /* Internal state */
    float _integral;         // Accumulated integral error
    float _previous_error;   // Previous error for derivative calculation
    int _u;                  // Last computed control signal
};

#endif // PIDCONTROLLER_H
