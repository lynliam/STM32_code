#include "mode2control.h"

uint8_t start_cmd[6] = {0xAA,0x07,0x02,0x00,0x01,0xB4};
uint8_t resume_cmd[4] = {0xAA,0x02,0x00,0xAC};
uint8_t pause_cmd[4] = {0xAA,0x03,0x00,0xAD};
uint8_t next_cmd[4] = {0xAA,0x05,0x00,0xAF};
uint8_t last_cmd[4] = {0xAA,0x06,0x00,0xB0};
uint8_t check_path_cmd[4] = {0xAA,0X09,0X00,0XB3};
uint8_t check_path_cmd_[4] = {0xAA,0X0A,0X00,0XB4};
uint8_t set_path_cmd[5] = {0xAA,0x0B,0x01,0x01,0xB7};

uint8_t check_song_cmd[4] = {0xAA,0x0C,0x00,0xB6};
uint8_t check_state_cmd[4] = {0xAA,0x01,0x00,0xAB};

void song_resume()
{
    for(int i=0;i<4;i++)
        HAL_UART_Transmit(&huart2,&resume_cmd[i],1*sizeof(uint8_t),0xf);
}

void song_start()
{
    for(int i=0;i<6;i++)
        HAL_UART_Transmit(&huart2,&start_cmd[i],1*sizeof(uint8_t),0xf);
}

void song_pause()
{
    for(int i=0;i<4;i++)
        HAL_UART_Transmit(&huart2,&pause_cmd[i],1*sizeof(uint8_t),0xf);
}

void next_song()
{
    for(int i=0;i<4;i++)
        HAL_UART_Transmit(&huart2,&next_cmd[i],1*sizeof(uint8_t),0xf);
}

void last_song()
{
    for(int i=0;i<4;i++)
        HAL_UART_Transmit(&huart2,&last_cmd[i],1*sizeof(uint8_t),0xf);
}

void check_path()
{
        for(int i=0;i<4;i++)
            HAL_UART_Transmit(&huart2,&check_path_cmd[i],1*sizeof(uint8_t),0xf);
}

void check_path_()
{
        for(int i=0;i<4;i++)
            HAL_UART_Transmit(&huart2,&check_path_cmd_[i],1*sizeof(uint8_t),0xf);
}

void set_path()
{
        for(int i=0;i<5;i++)
            HAL_UART_Transmit(&huart2,&set_path_cmd[i],1*sizeof(uint8_t),0xf);
}

void check_song()
{
        for(int i=0;i<4;i++)
            HAL_UART_Transmit(&huart2,&check_song_cmd[i],1*sizeof(uint8_t),0xf);
}

void check_state()
{
    for(int i=0;i<4;i++)
    HAL_UART_Transmit(&huart2,&check_state_cmd[i],1*sizeof(uint8_t),0xf);
}

