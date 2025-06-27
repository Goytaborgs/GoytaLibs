/********************************************************************
 * File: Motor_TB6612FNG.h
 * Description: A specific C++ library for controlling motors using 
 *              the TB6612FNG H-bridge driver. Also compatible with 
 *              other motor drivers that share a similar pin 
 *              configuration. This library handles pinMode setup 
 *              for control and PWM pins, but it does not manage the 
 *              TB6612FNG's STBY pin.
 * 
 * Dependencies:
 *  - Arduino.h
 * 
 * Created by: Marllon Batista - November 5, 2024
********************************************************************/


#ifndef MOTOR_TB6612FNG_H
#define MOTOR_TB6612FNG_H

#include <Arduino.h>

class Motor {
private:
    uint8_t pin_in1;
    uint8_t pin_in2;
    uint8_t pin_pwm;
    uint8_t pwm_channel;

public:
    /**
     * @brief Configures the motor control pins and PWM channel.
     * 
     * This function sets the direction and PWM pins as outputs 
     * and initializes the PWM channel using the ledc functions 
     * (ESP32).
     * 
     * @param in1     Pin connected to IN1 (motor direction control)
     * @param in2     Pin connected to IN2 (motor direction control)
     * @param pwm     Pin connected to PWM signal (motor speed control)
     * @param channel PWM channel used by ledcWrite
     * 
     * @return None
     */
    void configure(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t channel);

    /**
     * @brief Runs the motor at the specified speed and direction.
     * 
     * Positive values rotate the motor forward, negative values rotate 
     * it backward, and zero stops the motor. The function automatically 
     * handles direction logic and PWM writing.
     * 
     * @param speed Motor speed (-255 to 255)
     * 
     * @return None
     */
    void run(int16_t speed);

    /**
     * @brief Immediately stops the motor (brake mode).
     * 
     * Sets both control pins to LOW and PWM to 0, effectively braking 
     * the motor.
     * 
     * @param None
     * @return None
     */
    void stop();
};

#endif // MOTOR_TB6612FNG_H
