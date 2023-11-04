//
// Created by Quan2 on 2023/4/11.
//

#ifndef STM32F103_DEMO1_BSP_SPI_H
#define STM32F103_DEMO1_BSP_SPI_H

#include "stm32f1xx.h"
#include "spi.h"

#define ENABLE_GPIO_Port GPIOA
#define ENABLE_Pin GPIO_PIN_8

void PS2_Get(void);
void delay_us(unsigned int Delay);

extern uint8_t PS2data[9];  //存储手柄返回数据

#endif //STM32F103_DEMO1_BSP_SPI_H
