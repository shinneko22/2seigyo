#pragma once

#include <mbed.h>

#ifndef HARDWARE_
#define HARDWARE_

InterruptIn encoder_r_A(PA_4);
DigitalIn encoder_r_B(PA_5);

InterruptIn encoder_l_A(PA_6);
DigitalIn encoder_l_B(PA_7);

Timer root_timer;

#endif
