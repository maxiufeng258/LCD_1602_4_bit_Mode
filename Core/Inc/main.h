/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define LCD1602_D4_Pin GPIO_PIN_10
#define LCD1602_D4_GPIO_Port GPIOB
#define LD1_Red_Pin GPIO_PIN_10
#define LD1_Red_GPIO_Port GPIOH
#define LD2_Green_Pin GPIO_PIN_11
#define LD2_Green_GPIO_Port GPIOH
#define LD3_Blue_Pin GPIO_PIN_12
#define LD3_Blue_GPIO_Port GPIOH
#define LCD1602_RS_Pin GPIO_PIN_8
#define LCD1602_RS_GPIO_Port GPIOC
#define LCD1602_RW_Pin GPIO_PIN_9
#define LCD1602_RW_GPIO_Port GPIOC
#define LCD1602_EN_Pin GPIO_PIN_10
#define LCD1602_EN_GPIO_Port GPIOC
#define LCD1602_D5_Pin GPIO_PIN_11
#define LCD1602_D5_GPIO_Port GPIOC
#define LCD1602_D7_Pin GPIO_PIN_12
#define LCD1602_D7_GPIO_Port GPIOC
#define LCD1602_D6_Pin GPIO_PIN_2
#define LCD1602_D6_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
