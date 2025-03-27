/*
 * 001ledtoggle.c
 *
 *  Created on: Mar 26, 2025
 *      Author: PC-1
 */

#include "stm32f070xx.h"
//#include "stm32f070xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i=0 ; i<500000 ; i++);
}



int main(void)
{

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;

	GpioLed.GPIO_PinConfig->GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig->GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLed.GPIO_PinConfig->GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NO_PUPD;



	GPIO_PeriClockControl (GPIOA, ENABLE);

	GPIO_Init(&GpioLed);

	while(1)
	{

		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}

	return 0;
}
