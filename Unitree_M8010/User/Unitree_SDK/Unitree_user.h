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

const float ReductionRate = 6.33;

#endif //UNITREE_M8010_UNITREE_USER_H
