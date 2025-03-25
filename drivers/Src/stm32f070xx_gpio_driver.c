/*
 * stm32f070xx_gpio_driver.c
 *
 *  Created on: Mar 25, 2025
 *      Author: z3546658
 */


#include "stm32f070xx_gpio_driver.h"

/*************************************************************************************
 * @fn				- GPIO Peripheral Control
 *
 * @brief			- Enables or disables peripheral clock for the given GPIO
 *
 * @param[in]		- Base Address of the GPIO PRERIPHERAL
 * @param[in]		- Enable or disable macros
 * @param[in]		-
 *
 * @return			- None
 *
 * @Note			- None
 *
 *
 **************************************************************************************/
/*
 * Peripheral Clock Settings
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
	}else if (pGPIOx == GPIOB)
	{
		GPIOB_PCLK_EN();
	}else if (pGPIOx == GPIOC)
	{
		GPIOC_PCLK_EN();
	}else if (pGPIOx == GPIOD)
	{
		GPIOD_PCLK_EN();
	}else if (pGPIOx == GPIOF)
	{
		GPIOF_PCLK_EN();
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
	else if (pGPIOx == GPIOB)
	{
		GPIOB_PCLK_DI();
	}else if (pGPIOx == GPIOC)
	{
		GPIOC_PCLK_DI();
	}else if (pGPIOx == GPIOD)
	{
		GPIOD_PCLK_DI();
	}else if (pGPIOx == GPIOF)
	{
		GPIOF_PCLK_DI();
	}

	}

}

/*
 * Init and De-Init
 */
/*************************************************************************************
 * @fn				- GPIO Init
 *
 * @brief			- Initializes the GPIO port
 *
 * @param[in]		- Base Address of the GPIO PRERIPHERAL
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- None
 *
 * @Note			- None
 *
 *
 **************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. Configure the mode

	//2. configure the speed

	//3. configure the pull up and pull down

	//4. configure the output type

	//5. alternate functionality

}








/*************************************************************************************
 * @fn				- GPIO Init
 *
 * @brief			- Initializes the GPIO port
 *
 * @param[in]		- Base Address of the GPIO PRERIPHERAL
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- None
 *
 * @Note			- None
 *
 *
 **************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}

/*
 * Data Read and Qrite
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOX, uint8_t PinNumber)
{

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOX)
{

}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOX, uint8_t PinNumber, uint8_t Value)
{

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOX, uint16_t Value)
{

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOX, uint8_t PinNumber)
{

}

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}

