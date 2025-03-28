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
	for(uint32_t i=0 ; i<50000 ; i++);
}

//memset(GpioLed, 0, sizeof (GPIO_Handle_t GpioLed));
//GPIO_Handle_t GpioLed = {};


int main(void)
{



	GPIO_Handle_t GpioLed;

	memset(GpioLed[], 0, sizeof(GpioLed));


	GpioLed.pGPIOx = GPIOA;

	GpioLed.GPIO_PinConfig->GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig->GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig->GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NO_PUPD;





	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&GpioLed);


	while(1)
	{

		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

		delay();

	}

	return 0;
}
