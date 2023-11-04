//
// Created by liam on 2023/11/4.
//

#ifndef ODM_BUFFER_H
#define ODM_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "malloc.h"

typedef struct
{
    uint8_t  Head_1;              //帧头
    uint8_t  Head_2;              //帧头
    float   pos_x;              //x坐标
    float   pos_y;              //y坐标
    float   z_angle;            //俯仰角
    float   x_angle;            //横滚角
    float   y_angle;            //偏航角
    float   w_z;                //角速度
    uint8_t Tail_1;              //帧尾
    uint8_t Tail_2;              //帧尾
}OPS_Data_t;

typedef struct
{
    OPS_Data_t *base;     // 初始化的动态分配存储空间
    int front_p;   //头指针
    int rear_p;    // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;


SqQueue* Q_Init();
void Q_Destroy(SqQueue *Q);
void Q_Clear(SqQueue *Q);
int Q_Empty(SqQueue Q);
int Q_Length(SqQueue Q);
int Q_GetHead(SqQueue Q, OPS_Data_t *e);
int Q_Put(SqQueue *Q, OPS_Data_t *e);
int Q_Poll(SqQueue *Q, OPS_Data_t *e);


#define MAX_QSIZE 20 //最大队列长度


#ifdef __cplusplus
}
#endif

#endif //ODM_BUFFER_H
