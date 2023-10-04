//
// Created by lynliam on 23-4-8.
//
#include "bsp_encoder.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim==&htim4)
    {
        motor_pid_control(&motor[0]);
        //motor_pid_control(&motor[1]);
        //motor_pid_control(&motor[2]);
        //motor_pid_control(&motor[3]);
    }
    /*
    else if(htim==&(motor[0].TIM_EncoderHandle))
    {
        if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&htim2))
            motor[0].motor_overflow_counter.Encoder_Overflow_Count--;
        else
            motor[0].motor_overflow_counter.Encoder_Overflow_Count++;
    }


    else if(htim==&(motor[1].TIM_EncoderHandle))
    {
        if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&motor[1].TIM_EncoderHandle))
            motor[1].motor_overflow_counter.Encoder_Overflow_Count--;
        else
            motor[1].motor_overflow_counter.Encoder_Overflow_Count++;
    }else if(htim==(&motor[2].TIM_EncoderHandle))
    {
        if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&motor[2].TIM_EncoderHandle))
            motor[2].motor_overflow_counter.Encoder_Overflow_Count--;
        else
            motor[2].motor_overflow_counter.Encoder_Overflow_Count++;
    }
    else if(htim==(&motor[3].TIM_EncoderHandle))
    {
        if(__HAL_TIM_IS_TIM_COUNTING_DOWN(&motor[3].TIM_EncoderHandle))
            motor[3].motor_overflow_counter.Encoder_Overflow_Count--;
        else
            motor[3].motor_overflow_counter.Encoder_Overflow_Count++;
    }
    int a =__HAL_TIM_GET_COUNTER(&htim2);
    //printf("%d\n",a);
     */
    //printf("%f,%f,%d,%f,%ld\n",motor[0].motor_pid.target,motor[0].motor_pid.fdb,motor[0].dutyfactor,motor[0].actual_speed,motor[0].motor_overflow_counter.Capture_Count);
}
