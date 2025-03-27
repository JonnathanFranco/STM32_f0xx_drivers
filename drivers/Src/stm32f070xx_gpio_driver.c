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
	uint32_t temp = 0;	//temp register
	//1. Configure the mode
	if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));/////////// If problem, change -> for . in (fig->GPIO_)
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);		//Clearing
		pGPIOHandle->pGPIOx->MODER |= temp;															//Setting

	}else
	{
		//####################################this part for later
	}
	temp = 0;
	//2. configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;

	//3. configure the pull up and pull down
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;

	//4. configure the output type
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp = 0;

	//5. alternate functionality
	if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber /8;
		temp2 = pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber %8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig->GPIO_PinAltFunMode  << (4 * temp2));
	}

}




/*************************************************************************************
 * @fn				- GPIO
 *
 * @brief			-  GPIO port
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

	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}else if (pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
}

/*
 * Data Read and Qrite
 */
/*************************************************************************************
 * @fn				- GPIO
 *
 * @brief			-  GPIO port
 *
 * @param[in]		- Base Address of the GPIO PRERIPHERAL
 * @param[in]		-
 * @param[in]		-
 *
 * @return			- 0 or 1
 *
 * @Note			- None
 *
 *
 **************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t) ((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t) pGPIOx->IDR;

	return value;
}



void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		//write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}


}




void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	//
	pGPIOx->ODR = Value;
}




void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR	^=	(1 << PinNumber);
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

