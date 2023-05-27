#pragma once

#ifndef PARAMETERS_
#define PARAMETERS_

#include "static_parameters.h"


#define ENC_RES_MAX (4096) //ロータリエンコーダーの分解能

// 物理パラメータ (仮)
#define TIRE_DIAMETER	(1000)				//タイヤの直径	[mm]
#define TIRE_RADIUS	(TIRE_DIAMETER/2.0)		//タイヤの半径	[mm]
#define MMPP 		(TIRE_DIAMETER*PI)/(ENC_RES_MAX)	//エンコーダ1パルスあたりに進む距離[mm](TIRE_DIAMETER*PI)/(ENC_MAX)

#endif