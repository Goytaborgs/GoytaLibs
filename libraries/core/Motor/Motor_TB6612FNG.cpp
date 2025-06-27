#include <Motor_TB6612FNG.h>

// ********** PWM **********
const uint16_t pwm_freq = 1000;
const uint8_t pwm_resolution = 8;

// forward_pin, backward_pin, pwm_pin, pwm_channel
void Motor::configure(uint8_t in1, uint8_t in2, uint8_t pwm, uint8_t channel) {
    pin_in1 = in1;
    pin_in2 = in2;
    pin_pwm = pwm;
    pwm_channel = channel;

    pinMode(pin_in1, OUTPUT);
    pinMode(pin_in2, OUTPUT);
    pinMode(pin_pwm, OUTPUT);

    // PWM setup
    ledcAttachPin(pin_pwm, pwm_channel);
    ledcSetup(pwm_channel, pwm_freq, pwm_resolution);

    stop();
}

void Motor::run(int16_t speed) {
    if (speed > 0) {
        digitalWrite(pin_in1, HIGH);
        digitalWrite(pin_in2, LOW);
        ledcWrite(pwm_channel, speed);
    } else if (speed < 0) {
        speed = -speed;
        digitalWrite(pin_in1, LOW);
        digitalWrite(pin_in2, HIGH);
        ledcWrite(pwm_channel, speed);
    } else {
        stop();
    }
}

void Motor::stop() {
    digitalWrite(pin_in1, LOW);
    digitalWrite(pin_in2, LOW);
    ledcWrite(pwm_channel, 0);
}

