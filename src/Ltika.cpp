/*
#include <mbed.h>
#include <stdio.h>
#include <math.h>
float pi =3.141592653589793;
AnalogIn X_axis(A3);
AnalogIn Y_axis(A4);

float target_speed,target_direction;
float x,y,t,v;

x:ジョイスティックx方向の入力(-1~1)
y:ジョイスティックy方向の入力(-1~1)
t:ジョイスティックの角度(x軸方向から反時計回りに0~2pi)
v:速度の絶対値（0~1)


void Joystick_Getvalue(){
   x = (X_axis-0.5)*2;
   y = (Y_axis-0.5)*2;
   printf("X: %f, Y: %f\n", x, y);
}



void Joystick(){
    float r,cost,sint,t;
    //make cost,sint with value of x,y
    r = sqrt(x*x+y*y);
    cost = x/r;
    sint = y/r;
    
    //convert cost,sint to radian
    
    if (sint >=0){
    t= acos(cost);
    }else{
    t= 2*pi-acos(cost);
    }
    target_speed=r*1000;
    target_direction=t;



}



int main()
{

    while (true) {
        Joystick_Getvalue();
        Joystick();
    }
}
*/