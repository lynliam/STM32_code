/**
 * OPS 全场定位码盘
 * @file OPS_Location.c
 * @version 2.0
 * @author Liam (Quan.2003@outlook.com)
 * @date 2023-11-04
 */
//
// Created by liam on 2023/11/4.
//
#include "OPS_Location.h"

OPS_Data_t RxBuffer;
SqQueue RxData;

HAL_StatusTypeDef Servo_Get_Data(SqQueue *OPS) {
    OPS_Data_t OPSData;
    Q_Poll(OPS,&OPSData);
    //HAL_UART_Transmit(&huart6,(uint8_t *)&OPSData.Head_2,1,0xfff);
    //HAL_UART_Transmit(&huart6,(uint8_t *)&OPSData,28,0xfff);
    printf("%x%x",OPSData.Head_1,OPSData.Head_2);
    /*
    if(OPSData.Head_1 == 0x0D && OPSData.Head_2 == 0x0A && OPSData.Tail_1 == 0x0A && OPSData.Tail_2 == 0x0D)
    {
        //printf("%f,%f\n",OPSData.pos_x,OPSData.pos_y);
        return HAL_OK;
    }
    else{
        //printf("%.2f,%.2f\n",OPSData.pos_x,OPSData.pos_y);
        //printf("error\n");
        return HAL_ERROR;
    }*/
}

SqQueue* OPS_init()
{
    RxData.base = (OPS_Data_t *)malloc(MAX_QSIZE * sizeof(OPS_Data_t));
    RxData.front_p = 0;
    RxData.rear_p = 0;
    HAL_UARTEx_ReceiveToIdle_IT(&huart_, (uint8_t *) (&RxBuffer), 28);
    return &RxData;
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
    if (huart->Instance == UART8) {
        if(Size == 28)
        {
            Q_Put(&RxData,&RxBuffer);
            HAL_UARTEx_ReceiveToIdle_IT(&huart_, (uint8_t *) (&RxBuffer), 28);
        }
    }
}

