#ifndef _SDRAM_H
#define _SDRAM_H
#include "def_config.h"
#include "stm32h7xx.h"

extern SDRAM_HandleTypeDef SDRAM_Handler;//SDRAM句柄
#define Bank5_SDRAM_ADDR    ((u32)(0XC0000000)) //SDRAM开始地址

//SDRAM配置参数
#define SDRAM_MODEREG_BURST_LENGTH_1             ((u16)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((u16)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((u16)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((u16)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((u16)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((u16)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((u16)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((u16)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((u16)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((u16)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((u16)0x0200)

void SDRAM_Init(void);
void SDRAM_MPU_Config(void);
u8 SDRAM_Send_Cmd(SDRAM_HandleTypeDef *hsdram,u8 bankx,u8 cmd,u8 refresh,u16 regval);
void FMC_SDRAM_WriteBuffer(u8 *pBuffer,u32 WriteAddr,u32 n);
void FMC_SDRAM_ReadBuffer(u8 *pBuffer,u32 ReadAddr,u32 n);
void SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram);
#endif