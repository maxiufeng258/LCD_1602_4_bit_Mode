/*
 * LCD1602_4_bit.h
 *
 *  Created on: Feb 19, 2022
 *      Author: Maxiufeng
 */

#ifndef INC_LCD1602_4_BIT_H_
#define INC_LCD1602_4_BIT_H_

#include "stm32f4xx_hal.h"

/**
  * Define the LCD GPIO pins
  * 	RS	RW	EN	D4	D5	D6	D7	[Vss  Vdd]
  * 	these GPIO Pin use CubeMx configuration, low-level and output mode
  */
#define LCD1602_RS_Pin 			GPIO_PIN_8
#define LCD1602_RS_GPIO_Port 	GPIOC
#define LCD1602_RW_Pin 			GPIO_PIN_9
#define LCD1602_RW_GPIO_Port 	GPIOC
#define LCD1602_EN_Pin 			GPIO_PIN_10
#define LCD1602_EN_GPIO_Port 	GPIOC

#define LCD1602_D4_Pin 			GPIO_PIN_10
#define LCD1602_D4_GPIO_Port 	GPIOB
#define LCD1602_D5_Pin 			GPIO_PIN_11
#define LCD1602_D5_GPIO_Port 	GPIOC
#define LCD1602_D6_Pin 			GPIO_PIN_2
#define LCD1602_D6_GPIO_Port 	GPIOD
#define LCD1602_D7_Pin 			GPIO_PIN_12
#define LCD1602_D7_GPIO_Port 	GPIOC

/**
 * define the timer handler extern, Used for us delay
 */
#define	LCD1602_timer	htim6


/**
 * LCD1602 function declaration.
 */
void LCD1602_Init(void);
void LCD1602_Write_Cmd(uint8_t cmd);
void LCD1602_Clear(void);
void LCD1602_Set_Cursor(uint8_t row, uint8_t col);
void LCD1602_Write_Data(uint8_t data);
void LCD1602_Write_String(char *str);

#endif /* INC_LCD1602_4_BIT_H_ */
