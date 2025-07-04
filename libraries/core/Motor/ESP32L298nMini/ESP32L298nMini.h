/********************************************************************
 * File: ESP32L298nMini.h
 * Description: A specific C++ library for controlling motors using 
 *              the L298N Mini  H-bridge driver. Also compatible with 
 *              other motor drivers that share a similar pin 
 *              configuration.
 * Dependencies:
 *  - Arduino.h
 * 
 * Created by: Marllon Batista - November 5, 2024
********************************************************************/

#ifndef ESP32L298nMini_H 
#define ESP32L298nMini_H 

#include <Arduino.h>

class ESP32L298nMini {
  public:
    /**
      * @brief Configures the motor control pins and PWM channel.
      * 
      * This function sets the direction and pins as outputs 
      * and initializes the PWM channel using the ledc functions 
      * (ESP32).
      * 
      * @param in1     Pin connected to IN1 (motor direction control)
      * @param in2     Pin connected to IN2 (motor direction control)
      * @param pwmChannel1  PWM channel to pin in1
      * @param pwmChannel2  PWM channel to pin in2
      * @param resolution   PWM channel resolution
      * 
      * @return None
     */
    void configure(uint8_t in1, uint8_t in2, uint8_t pwmChannel1, uint8_t pwmChannel2, uint8_t resolution);
     /**
     * @brief Runs the motor at the specified speed and direction.
     * 
     * Positive values rotate the motor forward, negative values rotate 
     * it backward, and zero stops the motor. The function automatically 
     * handles direction logic and PWM writing.
     * 
     * @param speed Motor speed 
     * 
     * @return None
     */
    void run(int speed);
     /**
     * @brief Immediately stops the motor (brake mode).
     * 
     * Sets both pins to LOW, effectively braking 
     * the motor.
     * 
     * @param None
     * @return None
     */
    void stop();
 
  private:
    uint8_t _pinIn1;
    uint8_t _pinIn2;
    uint8_t _pwmChannel1;//pwm channel to pin in1
    uint8_t _pwmChannel2;//pwm channel to pin in2
    uint8_t _resolution;//pwm channel resolution
    int _maximumPwm;
    
};
#endif