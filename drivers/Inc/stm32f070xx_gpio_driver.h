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
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;



}GPIO_PinConfig_t;


/*
 * Handle structure for GPIO pin
 */

typedef struct
{
	//Pointer to holder base address of the GPIO PERIPHERAL
	GPIO_RegDef_t *pGPIOx;					//base address of GPIO port
	GPIO_PinConfig_t *GPIO_PinConfig;		//GPIO Pin conf settings

}GPIO_Handle_t;

/*****************************************************************************************
 * 					API SUPPORTED
 *****************************************************************************************/
/*
 * Peripheral Clock Settings
 */
void GPIO_PeriClockControl(void);

/*
 * Init and De-Init
 */
void GPIO_Init(void);
void GPIO_DeInit(void);

/*
 * Data Read and Qrite
 */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRWHandling(void);





#endif /* INC_STM32F070XX_GPIO_DRIVER_H_ */
