//
// Created by Quan2 on 2023/5/16.
//
#include "motor.h"

void PWM_update(unsigned int Motor1,unsigned int Motor2,unsigned int Motor3,unsigned int Motor4)
{
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,Motor1);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,Motor2);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,Motor3);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,Motor4);
}

void MPU_Get_Gyroscope(short *Gyro_x,short *Gyro_y , short *Gyro_z)
{
    float q0=1.0f,q1=0.0f,q2=0.0f,q3=0.0f;
    unsigned long sensor_timestamp;
    short gyro[3], accel[3], sensors;
    unsigned char more;
    long quat[4];
    dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,&more);
    *Gyro_x=gyro[0];
    *Gyro_y=gyro[1];
    *Gyro_z=gyro[2];
}
