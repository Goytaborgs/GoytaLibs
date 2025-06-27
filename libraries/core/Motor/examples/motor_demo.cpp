#include <Motor_TB6612FNG.h>

// ------------ Motors Instaces and Definitions ----------------//
Motor motor_r;
Motor motor_l;

uint8_t motor_l_front = 25;
uint8_t motor_l_back  = 33;
uint8_t motor_l_pwm   = 32;
uint8_t motor_l_channel = 0; //PWM channel for left motor

uint8_t motor_r_front = 27;
uint8_t motor_r_back  = 14;
uint8_t motor_r_pwm   = 13;
uint8_t motor_r_channel = 1; //PWM channel for right motor

#define STBY 26

void setup() {
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  motor_l.configure(motor_l_front, motor_l_back , motor_l_pwm, motor_l_channel);
  motor_r.configure(motor_r_front, motor_r_back , motor_r_pwm, motor_r_channel);

}

void loop() {
  motor_l.run(150);
  motor_r.run(-150);
  delay(1000);
  motor_l.run(-150);
  motor_r.run(150);
  delay(1000);
  motor_l.stop();
  motor_r.stop();
  delay(1000);
}