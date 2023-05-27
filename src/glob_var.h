#pragma once

#ifndef GLOB_VAR_
#define GLOB_VAR_

// モーター関連
float encoder_updated_time_r;
float encoder_updated_time_l;

float distance_r; // 右モーターの累積回転距離 [mm]
float distance_l; // 左モーターの累積回転距離 [mm]

float speed_r; // 右モーターの回転速度 [m/s]
float speed_l; // 左モーターの回転速度 [m/s]

float position_x; // ロボットのx座標 [m] (まだ未使用)
float position_y; // ロボットのy座標 [m] (まだ未使用)
float direction; // ロボットの方向 [deg] (まだ未使用)

#endif