/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define change_mode_Pin GPIO_PIN_13
#define change_mode_GPIO_Port GPIOC
#define change_time_Pin GPIO_PIN_14
#define change_time_GPIO_Port GPIOC
#define set_time_Pin GPIO_PIN_15
#define set_time_GPIO_Port GPIOC
#define led_north_south_red_Pin GPIO_PIN_1
#define led_north_south_red_GPIO_Port GPIOA
#define led_north_south_yellow_Pin GPIO_PIN_2
#define led_north_south_yellow_GPIO_Port GPIOA
#define led_north_south_green_Pin GPIO_PIN_3
#define led_north_south_green_GPIO_Port GPIOA
#define led_east_west_red_Pin GPIO_PIN_4
#define led_east_west_red_GPIO_Port GPIOA
#define led_east_west_yellow_Pin GPIO_PIN_5
#define led_east_west_yellow_GPIO_Port GPIOA
#define led_east_west_green_Pin GPIO_PIN_6
#define led_east_west_green_GPIO_Port GPIOA
#define enable_0_Pin GPIO_PIN_0
#define enable_0_GPIO_Port GPIOB
#define enable_1_Pin GPIO_PIN_1
#define enable_1_GPIO_Port GPIOB
#define seg_north_south_a_Pin GPIO_PIN_2
#define seg_north_south_a_GPIO_Port GPIOB
#define seg_east_west_b_Pin GPIO_PIN_10
#define seg_east_west_b_GPIO_Port GPIOB
#define seg_east_west_c_Pin GPIO_PIN_11
#define seg_east_west_c_GPIO_Port GPIOB
#define seg_east_west_d_Pin GPIO_PIN_12
#define seg_east_west_d_GPIO_Port GPIOB
#define seg_east_west_e_Pin GPIO_PIN_13
#define seg_east_west_e_GPIO_Port GPIOB
#define seg_east_west_f_Pin GPIO_PIN_14
#define seg_east_west_f_GPIO_Port GPIOB
#define seg_east_west_g_Pin GPIO_PIN_15
#define seg_east_west_g_GPIO_Port GPIOB
#define seg_north_south_b_Pin GPIO_PIN_3
#define seg_north_south_b_GPIO_Port GPIOB
#define seg_north_south_c_Pin GPIO_PIN_4
#define seg_north_south_c_GPIO_Port GPIOB
#define seg_north_south_d_Pin GPIO_PIN_5
#define seg_north_south_d_GPIO_Port GPIOB
#define seg_north_south_e_Pin GPIO_PIN_6
#define seg_north_south_e_GPIO_Port GPIOB
#define seg_north_south_f_Pin GPIO_PIN_7
#define seg_north_south_f_GPIO_Port GPIOB
#define seg_north_south_g_Pin GPIO_PIN_8
#define seg_north_south_g_GPIO_Port GPIOB
#define seg_east_west_a_Pin GPIO_PIN_9
#define seg_east_west_a_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
