//
// Created by liam on 2023/11/4.
//

#ifndef ODM_OPS_LOCATION_H
#define ODM_OPS_LOCATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "usart.h"
#include "buffer.h"

#include <stdio.h>

#define  huart_  huart8

HAL_StatusTypeDef Servo_Get_Data(SqQueue *OPS);
SqQueue* OPS_init();

#ifdef __cplusplus
}
#endif

#endif //ODM_OPS_LOCATION_H
