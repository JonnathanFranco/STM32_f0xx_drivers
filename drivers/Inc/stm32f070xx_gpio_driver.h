/*
 * stm32f070xx_gpio_driver.h
 *
 *  Created on: Mar 25, 2025
 *      Author: z3546658
 */

#ifndef INC_STM32F070XX_GPIO_DRIVER_H_
#define INC_STM32F070XX_GPIO_DRIVER_H_

#include "stm32f070xx.h"


typedef struct

{
	uint8_t GPIO_PinNumber;			//@GPIO_PIN_NUMBER
	uint8_t GPIO_PinMode;			//@GPIO_PIN_MODE Possible modes registers
	uint8_t GPIO_PinPuPdControl;	//@GPIO_OP_TYPE Pull up / pull down
	uint8_t GPIO_PinSpeed;			//@GPIO_SPEED Possible Output Speeds
	uint8_t GPIO_PinOPType;			//@GPIO_TYPE
	uint8_t GPIO_PinAltFunMode;



}GPIO_PinConfig_t;


/*
 * Handle structure for GPIO pin
 */

typedef struct
{
	//Pointer to holder base address of the GPIO PERIPHERAL
	GPIO_RegDef_t *pGPIOx;					//base address of GPIO port
	GPIO_PinConfig_t *GPIO_PinConfig;		//GPIO Pin configuration settings

}GPIO_Handle_t;


/////////////////////////////////////GPIO Pin Number registers
//@GPIO_PIN_NUMBER
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15



/////////////////////////////////////GPIO Possible modes registers
// @GPIO_PIN_MODE
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT 	4 	//INPUT FALLING EDGE
#define GPIO_MODE_IT_RT 	5 	//INPUT RISING EDGE
#define GPIO_MODE_IT_RFT 	6 	//INPUT RISING EDGE FALLING EDGE TRIGGER

/////////////////////////////////////GPIO Pull up / pull down
// @GPIO_OP_TYPE
#define GPIO_OP_TYPE_PP 	0	//Output push-pull (reset state)
#define GPIO_OP_TYPE_OD 	1	//Output open-drain

/////////////////////////////////////GPIO Possible Output Speeds
// @GPIO_SPEED
#define GPIO_SPEED_LOW 		0	//Low speed (x0)
#define GPIO_SPEED_MEDIUM 	1	//Medium speed (01)
#define GPIO_SPEED_HIGH 	3	//High speed (11)

/////////////////////////////////////GPIO port pull-up/pull-down registers
// @GPIO_TYPE
#define GPIO_NO_PUPD		0	//No pull-up, pull-down
#define GPIO_PIN_PU			1	//01: Pull-up
#define GPIO_PIN_PD			2	//10: Pull-down





/*****************************************************************************************
 * 					API SUPPORTED
 *****************************************************************************************/
/*
 * Peripheral Clock Settings
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-Init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Qrite
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F070XX_GPIO_DRIVER_H_ */
