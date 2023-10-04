//
// Created by liam on 2023/7/24.
//
#include "MyMain.h"


void Mymain()
{
    RetargetInit(&huart1);
    ServoMotor servo1 = ServoMotor(huart2);
    servo1.LimitAngleMAX(4094);
    servo1.LimitAngleMIM(3088);
    for(;;)
    {

        servo1.WritePosEx(4095, 254, 250);//以速度225步/秒 加速度50*（50*100步/秒^2）,运行至4095 4096为一圈0.088°一步
        HAL_Delay(2270);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
        servo1.WritePosEx(0, 254, 250);
        HAL_Delay(2270);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
    }
}
