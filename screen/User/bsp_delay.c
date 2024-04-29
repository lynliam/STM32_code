//
// Created by Quan2 on 2023/4/23.
//

#include  "bsp_delay.h"

void Delay_us(uint32_t nus)
{
    uint16_t counter = 0;
    __HAL_TIM_SetAutoreload(&htim7, nus);		//设置定时器自动加载值
    __HAL_TIM_SetCounter(&htim7, counter); 		//设置定时器初始值
    HAL_TIM_Base_Start(&htim7); 				//启动定时器

    while(counter != nus) //直到定时器计数从0计数到us结束循环,刚好是所需要的时间
    {
        counter = __HAL_TIM_GetCounter(&htim7); // 获取定时器当前计数
    }
    HAL_TIM_Base_Stop(&htim7); // 停止定时器
}
void delay_us(uint32_t nus)
{
    Delay_us(nus);
}

void Delay_ms(uint32_t nms) {
    Delay_us(1000 * nms);
}

int delay_ms(uint32_t nms)
{
    //delay_ms(1000000) -----一秒;
    if(nms>6)
    {
        Delay_ms(6);
    }
    else
    {
        Delay_ms(nms);
        return 1;
    }
    return delay_ms(nms-6);
}



