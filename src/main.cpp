#include <mbed.h>
#include <stdio.h>
#include <math.h>
#include "glob_var.h"
#include "parameters.h"
#include "hardware.h"
#include "pid.h"


// 右エンコーダーのインクリメント
void r_encoder_increment(){
    if (encoder_r_B.read() == 0){
        distance_r += MMPP;
        speed_r = MMPP/(root_timer.read() - encoder_updated_time_r);
        direction += RADPP;
        position_x += (MMPP/2)*cos(direction);
        position_y += (MMPP/2)*sin(direction);
    }else{
        distance_r -= MMPP;
        speed_r = - MMPP/(root_timer.read() - encoder_updated_time_r);
        direction -= RADPP;
        position_x -= (MMPP/2)*cos(direction);
        position_y -= (MMPP/2)*sin(direction);
    }
    encoder_updated_time_r = root_timer.read();
}

// 左エンコーダーのインクリメント
void l_encoder_increment(){
    if (encoder_l_B.read() == 0){
        distance_l += MMPP;
        speed_l = MMPP/(root_timer.read() - encoder_updated_time_l);
        direction -= RADPP;
        position_x += (MMPP/2)*cos(direction);
        position_y += (MMPP/2)*sin(direction);
    }else{
        distance_l -= MMPP;
        speed_l = - MMPP/(root_timer.read() - encoder_updated_time_l);
        direction += RADPP;
        position_x -= (MMPP/2)*cos(direction);
        position_y -= (MMPP/2)*sin(direction);
    }
    encoder_updated_time_l = root_timer.read();
}


//モーターの制御
void motor_interval(){
    float u_turn, u_speed;
    u_turn = 0;
    u_speed = 0;

    if(run_mode==STRAIGHT_MODE || run_mode==TURN_MODE){
        //左右モーターの平均のスピードをPID制御で調整する．
        float speed;
        speed = (speed_r+speed_l)/2;

        //操作量 = 速度目標*係数 + PID補正
        u_speed = SPEED_UNIT * target_speed + pid_speed.kp * (target_speed - speed) + pid_speed.ki * pid_speed.integral - pid_speed.kd * ((target_speed - speed) - pid_speed.before);
        pid_speed.before = target_speed - speed;
        pid_speed.integral += target_speed - speed;
    }

    if(run_mode==STRAIGHT_MODE){
        //直進時のモーターの左右のPWM比に関する制御
        //とりあえずつねに左右差0とする
        //これで曲がったりしたらspeed_r-speed_l→0となるようにPID制御する(pid_straight)
        u_turn=0;
    }else if(run_mode==TURN_MODE){
        //目標の進行方向との差についてPID制御する.
        float e; //偏差
        e = fmod(fmod(target_direction - direction + PI, 2*PI) + 2*PI, 2*PI) - PI; //-π ~ πに調整．
        u_turn = pid_rotate.kp * e + pid_rotate.ki * pid_rotate.integral - pid_rotate.kd * (e - pid_rotate.before);
        pid_rotate.before = e;
        pid_rotate.integral += e;
    }

    //ここからPWM書き込み
    float u_r, u_l;
    u_r = u_speed*(1+u_turn);
    u_l = u_speed*(1-u_turn);

    if(u_r > MAX_PWM){
        pwm_r = MAX_PWM;
        pwm_r_dir = 1;
    }else if(u_r < -MAX_PWM){
        pwm_r = MAX_PWM;
        pwm_r_dir = 0;
    }else if(u_r > 0){
        pwm_r = u_r;
        pwm_r_dir = 1;
    }else{
        pwm_r = -u_r;
        pwm_r_dir = 0;
    }

    if(u_l > MAX_PWM){
        pwm_l = MAX_PWM;
        pwm_l_dir = 1;
    }else if(u_l < -MAX_PWM){
        pwm_l = MAX_PWM;
        pwm_l_dir = 0;
    }else if(u_l > 0){
        pwm_l = u_l;
        pwm_l_dir = 1;
    }else{
        pwm_l = -u_l;
        pwm_l_dir = 0;
    }
}

void start_straight(float t_speed){
    pid_speed = {SPEED_KP,SPEED_KI,SPEED_KD,0,0}; //PIDコントローラーを初期化
    target_speed = t_speed;
    //pid_straight = {STRAIGHT_KP,STRAIGHT_KI,STRAIGHT_KD,0,0,0}; //直進 (未使用)
    run_mode=STRAIGHT_MODE; 
}

void start_turn(float t_direction){
    pid_speed = {ROTATE_KP,ROTATE_KI,ROTATE_KD,0,0}; //速度
    target_direction = t_direction;
    run_mode=TURN_MODE;
}


void init(){
    //タイマー
    root_timer.start();

    //エンコーダー
    encoder_updated_time_r = 0.0f;
    encoder_updated_time_l = 0.0f;
    distance_r = 0.0f;
    distance_l = 0.0f;

    //モーター
    pwm_r = 0;
    pwm_l = 0;

    //現在位置
    position_x=0;
    position_y=0;
    direction=0;

    //目標
    target_speed=0;
    target_direction=0;


    //とりあえずPIDゲインを初期化しておく
    pid_speed = {SPEED_KP,SPEED_KI,SPEED_KD,0,0}; //速度
    //pid_straight = {STRAIGHT_KP,STRAIGHT_KI,STRAIGHT_KD,0,0,0}; //直進 (未使用)
    pid_rotate = {ROTATE_KP,ROTATE_KI,ROTATE_KD,0,0}; //回転

    run_mode=STOP_MODE; //停止

    encoder_r_A.rise(&r_encoder_increment);
    encoder_l_A.rise(&l_encoder_increment);
};


//using rtos::ThisThread::sleep_for;

int main() {
    init();
    start_straight(100);
    while(1){
        motor_interval();
    }
}