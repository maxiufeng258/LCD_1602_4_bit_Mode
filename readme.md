**LCD1602 display use parallel 4bit mode, Based On STM32 **

**This Project use stm32cubeIde build (STM32CubeIDE Version: 1.8.0)**

**A total of 7 wires are used (RS RW E D4 D5 D6 D7)**

- **The following definitions are changed according to the actual setup of the output pins and timer peripherals.   [LCD1602_4_bit.h]**

```c
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
```

- **The following methods are provided to control LCD display operation  **

```c
/**
 * LCD1602 function declaration.
 */
void LCD1602_Init(void);
void LCD1602_Write_Cmd(uint8_t cmd);
void LCD1602_Clear(void);
void LCD1602_Set_Cursor(uint8_t row, uint8_t col);
void LCD1602_Write_Data(uint8_t data);
void LCD1602_Write_String(char *str);
```

- **Add LCD1602_4_bit.h/.c files to the project to drive LCD1602 display.**
