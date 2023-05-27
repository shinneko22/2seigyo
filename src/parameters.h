#pragma once

#ifndef PARAMETERS_
#define PARAMETERS_

#include "static_parameters.h"




// 物理パラメータ (値はまだテキトー)

#define ENC_RES_MAX (4096) //ロータリエンコーダーの分解能
#define TIRE_DIAMETER	(1000)				//タイヤの直径	[mm]
#define TIRE_RADIUS	(TIRE_DIAMETER/2.0)		//タイヤの半径	[mm]
#define TIRE_TRED (5000) //左右タイヤ接地面の中心間の距離[mm]
#define MMPP 		(TIRE_DIAMETER*PI)/(ENC_RES_MAX)	//エンコーダ1パルスあたりに進む距離[mm]
#define RADPP 		MMPP/TIRE_TRED	//エンコーダ1パルスあたりの回転角[rad]

#define MAX_PWM (1) //PWM上限


//PID制御のゲイン (値はまだテキトー) 今はPだけにしてある
#define SPEED_KP (1.0) //速度のPゲイン
#define SPEED_KI (0.0) //速度のIゲイン
#define SPEED_KD (0.0) //速度のDゲイン

#define STRAIGHT_KP (0.0) //直進時左右の速度差のPゲイン (未使用)
#define STRAIGHT_KI (0.0) //直進時左右の速度差のIゲイン (未使用)
#define STRAIGHT_KD (0.0) //直進時左右の速度差のDゲイン (未使用)

#define ROTATE_KP (1.0) //旋回のPゲイン
#define ROTATE_KI (0.0) //旋回のIゲイン
#define ROTATE_KD (0.0) //旋回のDゲイン

#endif