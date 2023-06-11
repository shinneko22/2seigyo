#pragma once

#include <mbed.h>

#ifndef HARDWARE_
#define HARDWARE_

//エンコーダー
InterruptIn encoder_r_A(PA_4);
DigitalIn encoder_r_B(PA_5);

InterruptIn encoder_l_A(PA_6);
DigitalIn encoder_l_B(PA_7);

PwmOut pwm_r(PA_9); // 右モーターpwm
PwmOut pwm_l(PA_10); // 左モーターpwm

DigitalOut pwm_r_dir(PB_6); // 左モーターpwm方向
DigitalOut pwm_l_dir(PB_7); // 左モーターpwm方向


AnalogIn X_axis(PA_0); //joystick x
AnalogIn Y_axis(PA_1); //joystick y



Timer root_timer;

#endif
