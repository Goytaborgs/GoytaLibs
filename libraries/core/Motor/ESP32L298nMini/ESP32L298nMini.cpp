#include "ESP32L298nMini.h"

// ********** PWM **********
const uint16_t freq = 1000; 

void ESP32L298nMini::configure(uint8_t in1, uint8_t in2, uint8_t pwmChannel1, uint8_t pwmChannel2, uint8_t resolution){
    _pinIn1 = in1;
    _pinIn2 = in2;
    _pwmChannel1 = pwmChannel1;
    _pwmChannel2 = pwmChannel2;
    _resolution = resolution;

    pinMode(_pinIn1,OUTPUT);
    pinMode(_pinIn2,OUTPUT);

    /* CONFIGURACAO DO PWM */
    ledcSetup(_pwmChannel1, freq, _resolution);
    ledcAttachPin(_pinIn1, _pwmChannel1);
    
    ledcSetup(_pwmChannel2, freq, _resolution);
    ledcAttachPin(_pinIn2, _pwmChannel2);
    

    _maximumPwm = (1 << _resolution)-1; // = (2^_resolution) -1

}
void ESP32L298nMini::run(int speed) {
    //pwm limit check
    if (speed > _maximumPwm){
        speed = _maximumPwm;
    }
    else if ( speed < -_maximumPwm){
        speed= - _maximumPwm;
    }
    
    if (speed > 0) {
        ledcWrite(_pwmChannel2, LOW);
        ledcWrite(_pwmChannel1, speed);
    } else {
        speed = -speed;
        ledcWrite(_pwmChannel1, LOW);
        ledcWrite(_pwmChannel2, speed);
    }
}

void ESP32L298nMini::stop() {
    ledcWrite(_pwmChannel2, LOW);
    ledcWrite(_pwmChannel1, LOW);
}
