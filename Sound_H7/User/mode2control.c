#include "mode2control.h"

uint8_t resume_cmd[4] = {0xAA,0x02,0x00,0xAC};
uint8_t pause_cmd[4] = {0xAA,0x03,0x00,0xAD};
uint8_t next_cmd[4] = {0xAA,0x05,0x00,0xAF};
uint8_t last_cmd[4] = {0xAA,0x06,0x00,0xB0};

void song_resume()
{
    for(int i=0;i<4;i++)
        HAL_UART_Transmit(&huart2,&resume_cmd[i],1*sizeof(uint8_t),0xf);
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