#include "./bsp_GPIO_ENABLE.h"

void MY_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_LED_Init;

/*
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_LED_Init.Pin=GPIO_PIN_13;
	GPIO_LED_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_LED_Init.Speed=GPIO_SPEED_FREQ_LOW;
	GPIO_LED_Init.Pull=GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOC,&GPIO_LED_Init);

    //motor 1st
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_LED_Init.Pin=GPIO_PIN_8;
    GPIO_LED_Init.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_LED_Init.Speed=GPIO_SPEED_FREQ_LOW;
    GPIO_LED_Init.Pull=GPIO_NOPULL;

    HAL_GPIO_Init(GPIOB,&GPIO_LED_Init);

    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_LED_Init.Pin=GPIO_PIN_9;
    GPIO_LED_Init.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_LED_Init.Speed=GPIO_SPEED_FREQ_LOW;
    GPIO_LED_Init.Pull=GPIO_NOPULL;

    HAL_GPIO_Init(GPIOB,&GPIO_LED_Init);
*/
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_LED_Init.Pin=GPIO_PIN_12;
    GPIO_LED_Init.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_LED_Init.Speed=GPIO_SPEED_FREQ_HIGH;
    GPIO_LED_Init.Pull=GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA,&GPIO_LED_Init);

}


/*
uint8_t Key_Scan(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin)
{
    if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin)==GPIO_PIN_SET)
    {
        while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin)==GPIO_PIN_SET);
        return KEY_ON;
    }
    else
    {
        return KEY_OFF;
    }

}
*/
