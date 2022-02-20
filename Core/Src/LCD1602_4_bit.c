/*
 * LCD1602_4_bit.c
 *
 *  Created on: Feb 19, 2022
 *      Author: Maxiufeng
 */

#include "LCD1602_4_bit.h"

extern TIM_HandleTypeDef LCD1602_timer;

/* Used to indicate data or commands */
typedef enum {
	flag_cmd  = 0,
	flag_data = 1,
}dataorcmd_flag_TypeDef;


/*  LCD1602 function implementation */
/* #####################################################
 * @brief us delay used for lcd1602
 * @param us: [in] delay time
 */
static void LCD1602_usDelay(uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&LCD1602_timer, 0);
	while (__HAL_TIM_GET_COUNTER(&LCD1602_timer) < us);
}

/* #####################################################
 * @brief write data or command to LCD1602
 * @param data: [in] data or cmd	length is 4bit
 * @param Data_or_Cmd: [in] 1: data    0: command  -> RS_pin
 */
static void LCD1602_Send_Data_Cmd(uint8_t data, dataorcmd_flag_TypeDef Data_or_Cmd_flag)
{
	HAL_GPIO_WritePin(LCD1602_RS_GPIO_Port, LCD1602_RS_Pin, Data_or_Cmd_flag);

	/* write data/cmd to GPIO_Pin Dx */
	HAL_GPIO_WritePin(LCD1602_D7_GPIO_Port, LCD1602_D7_Pin, ((data>>3)&0x01));
	HAL_GPIO_WritePin(LCD1602_D6_GPIO_Port, LCD1602_D6_Pin, ((data>>2)&0x01));
	HAL_GPIO_WritePin(LCD1602_D5_GPIO_Port, LCD1602_D5_Pin, ((data>>1)&0x01));
	HAL_GPIO_WritePin(LCD1602_D4_GPIO_Port, LCD1602_D4_Pin, ((data>>0)&0x01));

	/* set EN_Pin to 1, send the data */
	HAL_GPIO_WritePin(LCD1602_EN_GPIO_Port, LCD1602_EN_Pin, GPIO_PIN_SET);
	/* if the HCLK > 100MHz, use 20 us delay
	 * if the LCD still doesn't work, increase the delay to 50 80 or 100 us */
	LCD1602_usDelay(20);
	HAL_GPIO_WritePin(LCD1602_EN_GPIO_Port, LCD1602_EN_Pin, GPIO_PIN_RESET);
	LCD1602_usDelay(20);
}


/* #####################################################
 * @brief write cmd to lcd1602
 * @param cmd: [in] command byte
 */
void LCD1602_Write_Cmd(uint8_t cmd)
{
	uint8_t datatosend;

	/* send upper 4bit */
	datatosend = (cmd >> 4) & 0x0F;
	LCD1602_Send_Data_Cmd(datatosend, flag_cmd);

	/* send lower 4bit */
	datatosend = cmd & 0x0f;
	LCD1602_Send_Data_Cmd(datatosend, flag_cmd);
}


/* #####################################################
 * @brief write data to LCD1602
 * @param data: [in] data byte
 */
void LCD1602_Write_Data(uint8_t data)
{
	uint8_t datatosend;

	/* send upper 4bit */
	datatosend = (data >> 4) & 0x0F;
	LCD1602_Send_Data_Cmd(datatosend, flag_data);

	/* send lower 4bit */
	datatosend = data & 0x0f;
	LCD1602_Send_Data_Cmd(datatosend, flag_data);
}


/* #####################################################
 * @brief clear LCD1602
 */
void LCD1602_Clear(void)
{
	LCD1602_Write_Cmd(0x01);
	LCD1602_usDelay(2);
}


/* #####################################################
 * @brief set cursor position (row, col)
 * @param row: [in] row value [0,1]
 * @param col: [in] col value [0,1,2,3,4....,15]
 */
void LCD1602_Set_Cursor(uint8_t row, uint8_t col)
{
	if (col < 0 || col > 15)
		col = 0;

	switch (row) {
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
		default:
			col |= 0x80;
			break;
	}

	LCD1602_Write_Cmd(col);
}


/* #####################################################
 * @brief initialization and configuration LCD1602
 */
void LCD1602_Init(void)
{
	/* start timers */
	HAL_TIM_Base_Start(&LCD1602_timer);

	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	LCD1602_Write_Cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	LCD1602_Write_Cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	LCD1602_Write_Cmd (0x30);
	HAL_Delay(10);
	LCD1602_Write_Cmd (0x20);  // 4bit mode
	HAL_Delay(10);

	/* display initialization
	 * function set -> DL=0(4bit mode), N = 1(2 line display) F=0(5x8 characters) */
	LCD1602_Write_Cmd(0x28);
	HAL_Delay(1);
	/* display on/off control -> D=0,C=0,B=0  -> display off */
	LCD1602_Write_Cmd(0x08);
	HAL_Delay(1);
	/* clear lcd display */
	LCD1602_Write_Cmd(0x01);
	HAL_Delay(2);
	/* entry mode set -> I/D=1(increment cursor) & S = 0 (no shift) */
	LCD1602_Write_Cmd(0x06);
	HAL_Delay(1);
	/* display on/off control -> D=1, C and B = 0.(Cursor and blink, last two bits) */
	LCD1602_Write_Cmd(0x0C);
}


/* #####################################################
 * @brief write string data to LCD1602 display
 * 		based on LCD1602_Write_Data()
 */
void LCD1602_Write_String(char *str)
{
	while (*str)
	{
		LCD1602_Write_Data(*str++);
	}
}














