//
// Created by liam on 2023/7/24.
//

#ifndef TEST_STEPPING_MYMAIN_H
#define TEST_STEPPING_MYMAIN_H

#ifdef __cplusplus
extern "C" {
#endif
    /**--------------------------C-----------------------------**/
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "retarget.h"

void Mymain();

#ifdef __cplusplus
};
/**-----------------------------C++---------------------------**/
#include "Servo_uart.hpp"
#endif
#endif //TEST_STEPPING_MYMAIN_H
