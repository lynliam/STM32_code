#include "buffer.h"

SqQueue* Q_Init()
{
  SqQueue *Q = (SqQueue*)malloc(sizeof(SqQueue));
  Q->base = (OPS_Data_t *)malloc(MAX_QSIZE * sizeof(OPS_Data_t));
  Q->front_p = Q->rear_p = 0;
  return Q;
}

// 销毁队列Q，Q不再存在
void Q_Destroy(SqQueue *Q) {
    if (Q->base)
        free(Q->base);
    Q->base = NULL;
    Q->front_p = Q->rear_p = 0;
    free(Q);
}
 
// 将Q清为空队列
void Q_Clear(SqQueue *Q) {
    Q->front_p = Q->rear_p = 0;
}

// 若队列Q为空队列，则返回1；否则返回-1
int Q_Empty(SqQueue Q) {
    if (Q.front_p == Q.rear_p) // 队列空的标志
        return 1;
    else
        return -1;
}

// 返回Q的元素个数，即队列的长度
int Q_Length(SqQueue Q) {
    return (Q.rear_p - Q.front_p + MAX_QSIZE) % MAX_QSIZE;
}
 
// 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
int Q_GetHead(SqQueue Q, OPS_Data_t *e) {
    if (Q.front_p == Q.rear_p) // 队列空
        return -1;
    *e = Q.base[Q.front_p];
    return 1;
}
 
// 插入元素e为Q的新的队尾元素
int Q_Put(SqQueue *Q, OPS_Data_t *e) {
    if ((Q->rear_p + 1) % MAX_QSIZE == Q->front_p) // 队列满
        return -1;
    Q->base[Q->rear_p] = *e;
    Q->rear_p = (Q->rear_p + 1) % MAX_QSIZE;
    return 1;
}
 
// 若队列不空，则删除Q的队头元素，用e返回其值，并返回1；否则返回-1
int Q_Poll(SqQueue *Q, OPS_Data_t *e) {
    if (Q->front_p == Q->rear_p) // 队列空
        return -1;
    *e = Q->base[Q->front_p];
    Q->front_p = (Q->front_p + 1) % MAX_QSIZE;
    return 1;
}
