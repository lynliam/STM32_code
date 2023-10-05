//
// Created by liam on 2023/7/24.
//
#include "MyMain.h"



void Mymain()
{
    RetargetInit(&huart1);
    ServoMotor servo1 = ServoMotor(huart2);
    for(;;)
    {
        //printf("ddd\n");
        servo1.WritePosEx(-2000, 100, 50);//以速度225步/秒 加速度50*（50*100步/秒^2）,运行至4095 4096为一圈0.088°一步
        HAL_Delay(2270);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
        //servo1.WritePosEx(2000, 100, 50);//以速度225步/秒 加速度50*（50*100步/秒^2）,运行至4095 4096为一圈0.088°一步
        //HAL_Delay(2270);//[(P1-P0)/V]*1000+[V/(A*100)]*1000

        //servo1.WritePosEx(1, 100, 50);
        //HAL_Delay(2270);//[(P1-P0)/V]*1000+[V/(A*100)]*1000
        //servo1.read_data(0x38,0x02);
        int a = servo1.search_state();
        printf("%d",a);
    }
}
