#include <mbed.h>
#include <stdio.h>
#include "glob_var.h"
#include "parameters.h"
#include "hardware.h"

// 右エンコーダーの読み取り
void r_encoder_increment(){
    if (encoder_r_B.read() == 0){
        distance_r += MMPP;
        speed_r = MMPP/(root_timer.read() - encoder_updated_time_r);
    }else{
        distance_r -= MMPP;
        speed_r = - MMPP/(root_timer.read() - encoder_updated_time_r);
    }
    encoder_updated_time_r = root_timer.read();
}

// 左エンコーダーの読み取り
void l_encoder_increment(){
    if (encoder_l_B.read() == 0){
        distance_l += MMPP;
        speed_l = MMPP/(root_timer.read() - encoder_updated_time_l);
    }else{
        distance_l -= MMPP;
        speed_l = - MMPP/(root_timer.read() - encoder_updated_time_l);
    }
    encoder_updated_time_l = root_timer.read();
}

void init(){
    //タイマー
    root_timer.start();

    //エンコーダー
    encoder_updated_time_r = 0.0f;
    encoder_updated_time_l = 0.0f;
    distance_r = 0.0f;
    distance_l = 0.0f;
    encoder_r_A.rise(&r_encoder_increment);
    encoder_l_A.rise(&l_encoder_increment);

}



using rtos::ThisThread::sleep_for;

int main() {
    init();
    while(1){
    }
}