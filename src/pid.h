#pragma once

#ifndef PID_
#define PID_

struct PIDcontroller {
    float kp; // Pゲイン
    float ki; // Iゲイン
    float kd; // Dゲイン
    float before; // 前の偏差
    float integral; // 偏差の積分値
};

#endif