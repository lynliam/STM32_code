//
// Created by liam on 2023/10/4.
//

#ifndef UNITREE_M8010_UNITREE_USER_H
#define UNITREE_M8010_UNITREE_USER_H

#include "motor_control.h"


typedef struct{
    MOTOR_send cmd;
    MOTOR_recv data;
}UnitreeMotor;


extern UnitreeMotor Unitree_Motor[1];

HAL_StatusTypeDef Unitree_init(UnitreeMotor *MotorInstance);

HAL_StatusTypeDef Unitree_UART_tranANDrev(UnitreeMotor *MotorInstance, unsigned char motor_id,
                                          unsigned char mode, float T,float W,
                                          float Pos, float K_P, float K_W);

#endif //UNITREE_M8010_UNITREE_USER_H
