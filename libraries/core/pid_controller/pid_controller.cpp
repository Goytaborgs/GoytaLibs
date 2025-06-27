#include <pid_controller.h>

pid_controller::pid_controller(float kp, float ki, float kd)
{
    _kp = kp;
    _ki = ki;
    _kd = kd;
    _integral = 0.0f;
    _previous_error = 0.0f;
    _u = 0;
}
void pid_controller::set_kp(float kp) {
    _kp = kp;
}

void pid_controller::set_ki(float ki) {
    _ki = ki;
}

void pid_controller::set_kd(float kd) {
    _kd = kd;
}

void pid_controller::set_parameters(float kp, float ki, float kd) {
    _kp = kp;
    _ki = ki;
    _kd = kd;
}

int pid_controller::pid_calculation(float setpoint, float feedback, float delta_time)
{
    float error = setpoint - feedback;

    if (error > 180)
    {
        error -= 360;
    }
    else if (error < -180)
    {
        error += 360;
    }
    

    _integral += error * delta_time;
    float derivative = (error - _previous_error) / delta_time;
    
    float output = (_kp * error) + (_ki * _integral) + (_kd * derivative);

    _previous_error = error;
    _u = static_cast<int>(output);
    return _u;
}

int16_t pid_controller::right_motor_speed(int16_t min_speed, uint16_t max_speed, int16_t motor_bias, int u)
{
    int16_t speed = motor_bias + u;
    if (speed > max_speed) speed = max_speed;
    if (speed < min_speed) speed = min_speed;
    return speed;
}

int16_t pid_controller::left_motor_speed(int16_t min_speed, uint16_t max_speed, int16_t motor_bias, int u)
{
    int16_t speed = motor_bias - u;
    if (speed > max_speed) speed = max_speed;
    if (speed < min_speed) speed = min_speed;
    return speed;
}