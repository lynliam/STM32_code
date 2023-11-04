//
// Created by Quan2 on 2023/5/16.
//

#ifndef FANS_STM32F103_MOTOR_H
#define FANS_STM32F103_MOTOR_H

#include "stm32f1xx.h"
#include "main.h"
#include "tim.h"
#include "inv_mpu_dmp_motion_driver.h"
void PWM_update(unsigned int Motor1,unsigned int Motor2,unsigned int Motor3,unsigned int Motor4);
void MPU_Get_Gyroscope(short *Gyro_x,short *Gyro_y , short *Gyro_z);

#endif //FANS_STM32F103_MOTOR_H
