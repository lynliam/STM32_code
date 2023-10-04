#include "./bsp_KEY.h"
/*

void KEY_GPIOA_Init()
{
	GPIO_InitTypeDef GPIO_KEY_Init;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_KEY_Init.Pin=GPIO_PIN_0;
	GPIO_KEY_Init.Mode=GPIO_MODE_INPUT;
	GPIO_KEY_Init.Speed=GPIO_SPEED_FREQ_LOW;
	GPIO_KEY_Init.Pull=GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOA,&GPIO_KEY_Init);
	
	
}
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
	

