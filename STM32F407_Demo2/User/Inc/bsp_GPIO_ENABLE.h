#ifndef __BSP_LED_H_
#define __BSP_LED_H_

#include "stm32f4xx.h"

#define  SPI_CLK_PIN         GPIO_PIN_14
#define  SPI_CLK_PORT        GPIOD

#define  SPI_MOSI_PIN        GPIO_PIN_13
#define  SPI_MOSI_PORT       GPIOD

#define GPIO_LED_ON            do{HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);}while(0)
#define GPIO_LED_OFF           do{HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);}while(0)
#define GPIO_LED_SPARK         do{HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);}while(0)
#define KEY_ON        1;
#define KEY_OFF       0;

/*uint8_t Key_Scan(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin);*/
void MY_GPIO_Init();



#endif