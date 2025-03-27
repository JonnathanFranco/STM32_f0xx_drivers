/*
 * 001ledtoggle.c
 *
 *  Created on: Mar 26, 2025
 *      Author: PC-1
 */

#include "stm32f070xx.h"
#include "stm32f070xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i=0 ; i<500000 ; i++);
}



int main(void)
{
	GPIO_Handle_t Gpioled;

	Gpioled.pGPIOx = GPIOA;


	Gpioled.GPIO_PinConfig->GPIO_PinNumber = GPIO_PIN_NO_5;
	Gpioled.GPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig->GPIO_PinSpeed = GPIO_SPEED_HIGH;
	Gpioled.GPIO_PinConfig->GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Gpioled.GPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl (GPIOA, ENABLE);

	GPIO_Init(&Gpioled);

	while(1)
	{

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_5);
		delay();
	}

	return 0;
}
