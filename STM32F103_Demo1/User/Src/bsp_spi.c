//
// Created by Quan2 on 2023/4/11.
//
#include "bsp_spi.h"


uint8_t cmd[3] = {0x01,0x42,0x00};  // 请求接受数据
uint8_t PS2data[9] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

void PS2_Get(void)    //接受ps2数据
{
    uint8_t i = 0;

    HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin,GPIO_PIN_RESET);  //拉高，开始通讯

    HAL_SPI_TransmitReceive(&hspi1,&cmd[0],&PS2data[0],1,0xffff); // 发送0x01，请求接受数据
    delay_us(10);
    HAL_SPI_TransmitReceive(&hspi1,&cmd[1],&PS2data[1],1,0xffff); // 发送0x42，接受0x01（PS2表示开始通信）
    delay_us(10);
    HAL_SPI_TransmitReceive(&hspi1,&cmd[2],&PS2data[2],1,0xffff); // 发送0x00，接受ID（红绿灯模式）
    delay_us(10);
    for(i = 3;i <9;i++)
    {
        HAL_SPI_TransmitReceive(&hspi1,&cmd[2],&PS2data[i],1,0xffff); // 接受数据
        delay_us(10);

    }

    HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin,GPIO_PIN_SET);  //拉低，准备下次通讯

}

/*
void delay_us(uint32_t nus)
{
    uint32_t ticks;
    uint32_t told,tnow,tcnt=0;
    uint32_t reload=SysTick->LOAD;				//LOAD的值	    	 
    ticks=nus*fac_us; 						//需要的节拍数 
    told=SysTick->VAL;        				//刚进入时的计数器值
    while(1)
    {
        tnow=SysTick->VAL;
        if(tnow!=told)
        {
            if(tnow<told)tcnt+=told-tnow;	//这里注意一下SYSTICK是一个递减的计数器就可以了.
            else tcnt+=reload-tnow+told;
            told=tnow;
            if(tcnt>=ticks)break;			//时间超过/等于要延迟的时间,则退出.
        }
    };
}
 */

/**
 * @bieaf 微秒延时函数
 * @detail 注意:由于指令执行需要时间, 实际的延时精度约为1微秒
 *
 * @param unsigned int Delay 延时的微秒
 */
void delay_us(unsigned int Delay)
{
    uint32_t tickstart = SysTick->VAL;                            ///<获取当前tick
    uint32_t tickNum = 0;
    uint32_t tickMax = SysTick->LOAD + 1;
    uint32_t delay_usvalue = (tickMax / 1000) * Delay;            ///<计算一共需要延时的tick
    while(1)
    {
        uint32_t cur_tick = SysTick->VAL;
        if (cur_tick > tickstart)                                 ///<进行了一次重载
        {
            tickNum = tickstart + (tickMax - cur_tick);
        }
        else                                                      ///<未进行过重载
        {
            tickNum = tickstart - cur_tick;
        }

        if (tickNum > delay_usvalue)                              ///<达到延时的tick数
        {
            return;
        }
    }
}
