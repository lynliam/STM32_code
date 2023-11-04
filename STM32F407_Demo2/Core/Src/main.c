/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp_GPIO_ENABLE.h"
#include "retarget.h"
#include <stdio.h>
#include "motor_control.h"
#include "bsp_delay.h"
#include "bsp_ps2.h"
#include "bsp_Mecanum.h"
#include "bsp_beep.h"
#include "Show_oled_num.h"
#include "wit_c_sdk.h"
#include "wit_callback.h"
#include "bsp_encoder.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
uint8_t key=0;

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM9_Init();
  MX_TIM10_Init();
  MX_TIM11_Init();
  MX_TIM6_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM1_Init();
  MX_TIM7_Init();
  MX_TIM13_Init();
  MX_UART4_Init();
  MX_TIM14_Init();
  /* USER CODE BEGIN 2 */
    //GPIO初始化
    MY_GPIO_Init();
    //重定向
    RetargetInit(&huart4);

    /*   motor Init   */
    char Data[10]="3";
    motor_init(0,htim2,htim10,TIM_CHANNEL_1,htim11,TIM_CHANNEL_1);
    motor_init(1,htim3,htim9,TIM_CHANNEL_1,htim9,TIM_CHANNEL_2);
    motor_init(2,htim4,htim1,TIM_CHANNEL_1,htim1,TIM_CHANNEL_2);
    motor_init(3,htim5,htim1,TIM_CHANNEL_3,htim1,TIM_CHANNEL_4);
    motor_start(0);
    motor_start(1);
    motor_start(2);
    motor_start(3);
    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_Base_Start_IT(&htim7);
    /*   motor Init   */

    /*   OLED Init   */
    SPI_PIN_Init();
    OLED_Init();
    start_beep();
    /*   OLED Init   */

    /*    IMU INit    */
    Usart2Init(115200);

    __HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
    uint8_t tempdata;
    HAL_UART_Receive_IT(&huart3,&tempdata,1);

    /*蓝牙初始化*/
    __HAL_UART_ENABLE_IT(&huart4,UART_IT_RXNE);
    uint8_t tempdata_4;
    HAL_UART_Receive_IT(&huart4,&tempdata_4,1);

    WitInit(WIT_PROTOCOL_NORMAL, 0x50);
    WitSerialWriteRegister(SensorUartSend);
    WitRegisterCallBack(SensorDataUpdata);
    WitDelayMsRegister(Delayms);
    printf("\r\n********************** wit-motion normal example  ************************\r\n");
    //AutoScanSensor();

    /*    IMU Init    */

    //HAL_TIM_Base_Start_IT(&htim14);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      trans_float();
      //printf("ddd\n");
      //printf("%d",sizeof(float));
      //printf("\r\n%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\r\n",temp[0],temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7], temp[8], motor[0].actual_speed,motor[1].actual_speed,motor[2].actual_speed,motor[3].actual_speed);
      /*接收imu数据*/
      //数据将在TIM7定时中断回调函数中处理
      /*
      HAL_UART_Receive_DMA(&huart2, rx_buffer, 11);
      for (int i = 0; i < 11; i++) {
          WitSerialDataIn(rx_buffer[i]);
          //printf("%X",rx_buffer[i]);
      }
      */
      /*接收imu数据*/


      //oled显示
      draw_speed(&motor[0]);
      //ps2读取数据
      PS2_Read_Data();

      car_speed[0]=5.0/128.0*PS2_Data.Rocker_LY;
      car_speed[1]=5.0/128.0*PS2_Data.Rocker_RX;
      if(PS2_Data.Key_L1 != 0)
        car_speed[2]=PS2_Data.Key_L1*0.003;
      else if(PS2_Data.Key_L2!=0)
        car_speed[2]=PS2_Data.Key_R1*0.003;
      else{
          car_speed[2]=0.0;
      }
      //car_speed[2] = 0;

      while(!HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3))
      {
          if (key==0)
          {
              motor_stop(0);
              motor_stop(1);
              motor_stop(2);
              motor_stop(3);
              HAL_TIM_Base_Stop(&htim6);
              key=1;
          }
      }
      if(key==1)
      {
          motor_init(0,htim2,htim10,TIM_CHANNEL_1,htim11,TIM_CHANNEL_1);
          motor_init(1,htim3,htim9,TIM_CHANNEL_1,htim9,TIM_CHANNEL_2);
          motor_init(2,htim4,htim1,TIM_CHANNEL_1,htim1,TIM_CHANNEL_2);
          motor_init(3,htim5,htim1,TIM_CHANNEL_3,htim1,TIM_CHANNEL_4);
          motor_start(0);
          motor_start(1);
          motor_start(2);
          motor_start(3);
          HAL_TIM_Base_Start_IT(&htim6);
          key=0;
      }
        if(PS2_Data.A_D==1)
        {
            cal_motor_speed(cal_matrix,motor_w,car_speed,MOTOR_R);

            set_pid_target(&motor[0].motor_pid,motor_w[0]*37.5/5.5*1000.0);
            set_pid_target(&motor[1].motor_pid,motor_w[3]*37.5/5.5*1000.0);
            set_pid_target(&motor[2].motor_pid,motor_w[2]*37.5/5.5*1000.0);
            set_pid_target(&motor[3].motor_pid,motor_w[1]*37.5/5.5*1000.0);
        }
        //printf("%f,%f,%f\n",car_speed[0],car_speed[1],car_speed[2]);
        //printf("%f,%f,%f,%f\n",)
        //printf("%f,%f,%f,%f\n",motor[0].motor_pid.target,motor[0].motor_pid.target,motor[0].motor_pid.target,motor[0].motor_pid.target);
        printf("%f,%f,%f,%f\n",motor[0].actual_speed,motor[1].actual_speed,motor[2].actual_speed,motor[3].actual_speed);
        //printf("%f,%f,%f,%f\n",motor[0].motor_overflow_counter.Capture_Count,motor[1].motor_overflow_counter.Capture_Count,motor[2].motor_overflow_counter.Capture_Count,motor[3].motor_overflow_counter.Capture_Count);
        //printf("%d,%d,%d,%d,%d,%d,%f\n",PS2_Data.A_D,PS2_Data.Rocker_LX,PS2_Data.Rocker_LY,PS2_Data.Rocker_RX,PS2_Data.Rocker_RY,PS2_Data.Key_L1,car_speed[2]);
        //printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",PS2data[0],PS2data[1],PS2data[2],PS2data[3],PS2data[4],PS2data[5],PS2data[6],PS2data[7],PS2data[8]);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
      break;
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
