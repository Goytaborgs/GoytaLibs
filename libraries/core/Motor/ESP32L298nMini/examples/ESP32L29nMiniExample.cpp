#include <ESP32L298nMini.h>

// ------------ Motors Instaces and Definitions ----------------//
ESP32L298nMini motor_r;
ESP32L298nMini motor_l;

uint8_t motor_l_front = 18;
uint8_t motor_l_back  = 4;
uint8_t motor_l_channel1 = 2; //PWM channel for left motor
uint8_t motor_l_channel2 = 3; //PWM channel for left motor

uint8_t motor_r_front = 21;
uint8_t motor_r_back  = 19;
uint8_t motor_r_channel1 = 0; //PWM channel for right motor
uint8_t motor_r_channel2 = 1; //PWM channel for right motor

uint8_t pwmResolution = 8; //PWM channel resolution

void setup() {
  motor_l.configure(motor_l_front, motor_l_back , motor_r_channel1, motor_l_channel2,pwmResolution);
  motor_r.configure(motor_r_front, motor_r_back , motor_r_channel1, motor_r_channel2,pwmResolution);
}

void loop() {
  motor_l.run(50);
  motor_r.run(-50);
  delay(1000);
  motor_l.run(-50);
  motor_r.run(50);
  delay(1000);
  motor_l.stop();
  motor_r.stop();
  delay(1000);
}
