#pragma once

#ifndef PARAMETERS_
#define PARAMETERS_

#include "static_parameters.h"


// 物理パラメータ (値はまだテキトー)

#define ENC_RES_MAX (48) //ロータリエンコーダーの分解能
#define TIRE_DIAMETER	(88.0f)				//タイヤの直径	[mm]
#define TIRE_RADIUS	(TIRE_DIAMETER/2.0f)		//タイヤの半径	[mm]
#define TIRE_TRED (364.0f) //左右タイヤ接地面の中心間の距離[mm]
#define MMPP 		(TIRE_DIAMETER*PI)/(ENC_RES_MAX)	//エンコーダ1パルスあたりに進む距離[mm]
#define RADPP 		MMPP/TIRE_TRED	//エンコーダ1パルスあたりの回転角[rad]

#define MAX_PWM (1.0f) //PWM上限

#define MAX_SPEED (1000.0f)   //目標最高速度	[mm/s]


//PID制御のゲイン (値はまだテキトー) 今はPだけにしてある
#define SPEED_KP (0.001f) //速度調整のPゲイン
#define SPEED_KI (0.0f) //速度調整のIゲイン
#define SPEED_KD (0.0f) //速度調整のDゲイン

#define SPEED_UNIT (0.001f) //速度1mm/sあたりの出力PWM


#define STRAIGHT_KP (0.0f) //直進時左右の速度差のPゲイン (未使用)
#define STRAIGHT_KI (0.0f) //直進時左右の速度差のIゲイン (未使用)
#define STRAIGHT_KD (0.0f) //直進時左右の速度差のDゲイン (未使用)

#define ROTATE_KP (0.005f) //旋回のPゲイン
#define ROTATE_KI (0.0f) //旋回のIゲイン
#define ROTATE_KD (0.0f) //旋回のDゲイン

#endif