//
// Created by Quan2 on 2023/4/23.
//

#ifndef STM32F407_DEMO2_BSP_DELAY_H
#define STM32F407_DEMO2_BSP_DELAY_H

#ifndef     __delay_H
#define     __delay_H

#include "stm32h7xx.h"  
#include "tim.h"
void Delay_Init(void);
void Delay_us(uint32_t nus);
void Delay_ms(uint32_t nms);
int delay_ms(uint32_t nms);
void delay_us(uint32_t nus);
#endif

#endif //STM32F407_DEMO2_BSP_DELAY_H
