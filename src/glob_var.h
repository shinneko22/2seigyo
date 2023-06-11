
#pragma once

#ifndef GLOB_VAR_
#define GLOB_VAR_

#include "pid.h"

// モーター関連
float encoder_updated_time_r;
float encoder_updated_time_l;

float distance_r; // 右モーターの累積回転距離 [mm]
float distance_l; // 左モーターの累積回転距離 [mm]

float speed_r; // 右モーターの回転速度 [m/s]
float speed_l; // 左モーターの回転速度 [m/s]

float position_x; // ロボットのx座標 [m] (まだ未使用)
float position_y; // ロボットのy座標 [m] (まだ未使用)
float direction; // ロボットの方向 [rad] (まだ未使用)

float target_speed; // モーター目標速度 [m/s]
float target_direction; // 目標方向 [rad]

unsigned int run_mode; // 0:停止 1:直進 2:カーブ (3:信地旋回 4:超信地旋回)

//PIDコントローラー
PIDcontroller pid_speed; //速度
PIDcontroller pid_straight; //直進 (未使用)
PIDcontroller pid_rotate; //回転

// 今は変数にしてるけどあとでanalogout, digitaloutにしてhardware.hにつっこむやつら
float pwm_r; // 右モーターpwm
float pwm_l; // 左モーターpwm
unsigned int pwm_r_dir; // 左モーターpwm方向
unsigned int pwm_l_dir; // 左モーターpwm方向


#endif