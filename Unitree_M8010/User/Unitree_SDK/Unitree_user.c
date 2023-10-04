//
// Created by liam on 2023/10/3.
//

#include "Unitree_user.h"

UnitreeMotor Unitree_Motor[1];               //电机实例化数组

/**
 * 电机初始化自检
 * @return
 */
HAL_StatusTypeDef Unitree_init(UnitreeMotor *MotorInstance)
{
    MotorInstance->cmd.id=0; 			//给电机控制指令结构体赋值
    MotorInstance->cmd.mode=1;
    MotorInstance->cmd.T=0;
    MotorInstance->cmd.W=0;
    MotorInstance->cmd.Pos=0;
    MotorInstance->cmd.K_P=0;
    MotorInstance->cmd.K_W=0.05;
    if(SERVO_Send_recv(&MotorInstance->cmd,&MotorInstance->data) == 0 && MotorInstance->data.MError == 0)
        return HAL_OK;
    else
        return HAL_ERROR;
}

/**
 * 电机自定义参数发送函数
 * @param MotorInstance  电机对象实例
 * @param motor_id       电机ID （0-14）
 * @param mode           电机工作模式 （0.锁定；1.FOC闭环；2.编码器校准）
 * @param T              电机转矩（-127.99 ~ 127.99  单位 N·m）
 * @param W              电机输出轴速度（-127.014 ~ 127.014  单位 rad/s）
 * @param Pos            电机输出轴输出位置（-65051.18 ~ 65051.18  单位 rad）
 * @param K_P            电机刚度系数/位置误差比例系数（0 ~ 25.599）
 * @param K_W            电机阻尼系数/速度误差比例（0 ~ 25.599）
 * @return               函数状态
 */
HAL_StatusTypeDef Unitree_UART_tranANDrev(UnitreeMotor *MotorInstance, unsigned char motor_id,
                                          unsigned char mode, float T,float W,
                                          float Pos, float K_P, float K_W)
{
    MotorInstance->cmd.id = motor_id;
    MotorInstance->cmd.mode = mode;
    MotorInstance->cmd.T = T;
    MotorInstance->cmd.W = W * ReductionRate;
    MotorInstance->cmd.Pos = Pos * ReductionRate;
    MotorInstance->cmd.K_P = K_P;
    MotorInstance->cmd.K_W = K_W;
    if(SERVO_Send_recv(&MotorInstance->cmd,&MotorInstance->data) == 0 && MotorInstance->data.MError == 0)
        return HAL_OK;
    else
        return HAL_ERROR;
}


