/*
 * stm32f070xx.h
 *
 *  Created on: Feb 10, 2025
 *      Author: z3546658
 *      Test_3
 *      Test_4
 */

#ifndef INC_STM32F070XX_H_
#define INC_STM32F070XX_H_

#include<stdint.h>

#define __vo volatile 			//Definition of __vo as volatile

/*
 * Define addresses for SRAM and FLASH memories
 */
#define FLASH_BASEADDR			0x08000000U
#define SRAM_BASEADDR			0x20000000U
#define ROM_BASEADDR			0x1FFFC800U


/*
 * Define APB and AHB bus peripheral base addresses
 */
#define AHB1_BASEADDR			0x40020000U
#define AHB2_BASEADDR			0x48000000U
#define APB_BASEADDR			0x40000000U
#define RCC_BASEADDR			0x40021000U

/*
 * Define the base addresses of peripherals which are hanging on AHB2
 */
#define GPIOA_BASEADDR			0x48000000U
#define GPIOB_BASEADDR			0x48000400U
#define GPIOC_BASEADDR			0x48000800U
#define GPIOD_BASEADDR			0x48000D00U
#define GPIOF_BASEADDR			0x48001400U


/*
 * Define the base addresses of peripherals which are hanging on APB
 */
#define I2C1_BASEADDR			0x40005400U
#define I2C2_BASEADDR			0x40005800U
#define SPI1_BASEADDR			0x40013000U
#define SPI2_BASEADDR			0x40003800U
#define USART1_BASEADDR			0x40013800U
#define USART2_BASEADDR			0x40004400U
#define USART3_BASEADDR			0x40004800U
#define USART4_BASEADDR			0x40004C00U

#define EXTI_BASEADDR			0x40010400U
#define SYSCFG_BASEADDR			0x40010400U


/*
 *********************  Peripheral register definition structures   ************************
 *********************  Using volatile due to the nature of the variable... ****************
 */
// *********************  GPIO PORT MODE REGISTER						********************
typedef struct
{
	__vo uint32_t MODER;			//Address offset: 0x00
	__vo uint32_t OTYPER;			//Address offset: 0x04
	__vo uint32_t OSPEEDR;			//   :
	__vo uint32_t PUPDR;			//   :
	__vo uint32_t IDR;				//   :
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];			// Array of [1] Low reg [2] High reg
	__vo uint32_t BRR;
}GPIO_RegDef_t;

// *********************  RCC PORT MODE REGISTER					********************
typedef struct
{
	__vo uint32_t CR;			//Address offset: 0x00
	__vo uint32_t CFGR;			//Address offset: 0x04
	__vo uint32_t CIR;			//Address offset: 0x08
	__vo uint32_t APB2RSTR;		//Address offset: 0x0C
	__vo uint32_t APB1RSTR;		//Address offset: 0x10
	__vo uint32_t AHBENR;		//Address offset: 0x14
	__vo uint32_t APB2ENR;		//Address offset: 0x18
	__vo uint32_t APB1ENR;		//Address offset: 0x1C
	__vo uint32_t BDCR;			//Address offset: 0x20				if double"high and low" then: Array of [1] Low reg [2] High reg
	__vo uint32_t CSR;			//Address offset: 0x24
	__vo uint32_t AHBRSTR;		//Address offset: 0x28
	__vo uint32_t CFGR2;
	__vo uint32_t CFGR3;
	__vo uint32_t CR2;			//Address offset: 0x34
//  __vo uint32_t RESERVED1 OR RESERVED1[2], etc;	//This happens when there are memory locations reserved.
}RCC_RegDef_t;




//*********************************************************************************************

/*
 ********************* 	Peripheral definitions (Peripheral base addresses typecasted to xxx_RefDef_t)
 */

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)

#define RCC	  ((RCC_RegDef_t*)RCC_BASEADDR)


//#################		Clock enable macros		##########################################
//**************  GPIO 	*******************
#define GPIOA_PCLK_EN()			(RCC->AHBENR |= (1 << 17))
#define GPIOB_PCLK_EN()			(RCC->AHBENR |= (1 << 18))
#define GPIOC_PCLK_EN()			(RCC->AHBENR |= (1 << 19))
#define GPIOD_PCLK_EN()			(RCC->AHBENR |= (1 << 20))
#define GPIOF_PCLK_EN()			(RCC->AHBENR |= (1 << 22))
//************** I2C 	*******************
#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1 << 22))
//**************  SPI 	*******************
#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1 << 14))
//**************  USARTX *******************
#define USART1_PCLK_EN()		(RCC->APB2ENR |= (1 << 14))
#define USART2_PCLK_EN()		(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()		(RCC->APB1ENR |= (1 << 18))
#define USART4_PCLK_EN()		(RCC->APB1ENR |= (1 << 19))
//************** SYSCONFIG *******************
#define SYSCFR_PCLK_EN()		(RCC->APB2ENR |= (1 << 0))
//##########################################################################################


//#################		Clock disable macros		##########################################
//**************  GPIO 	*******************
#define GPIOA_PCLK_DI()			(RCC->AHBENR &= ~(1 << 17))
#define GPIOB_PCLK_DI()			(RCC->AHBENR &= ~(1 << 18))
#define GPIOC_PCLK_DI()			(RCC->AHBENR &= ~(1 << 19))
#define GPIOD_PCLK_DI()			(RCC->AHBENR &= ~(1 << 20))
#define GPIOF_PCLK_DI()			(RCC->AHBENR &= ~(1 << 22))
//************** I2C 	*******************
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 22))
//**************  SPI 	*******************
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 14))
//**************  USARTX *******************
#define USART1_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 14))
#define USART2_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 18))
#define USART4_PCLK_DI()		(RCC->APB1ENR &= ~(1 << 19))
//************** SYSCONFIG *******************
#define SYSCFR_PCLK_DI()		(RCC->APB2ENR &= ~(1 << 0))
//##########################################################################################


/*
 * Macros to reset GPIOx Peripherals
 */
#define GPIOA_REG_RESET()		do{ (RCC->AHBRSTR |= (1 << 17)); (RCC->AHBRSTR &= ~(1 << 17)); }while(0)
#define GPIOB_REG_RESET()		do{ (RCC->AHBRSTR |= (1 << 18)); (RCC->AHBRSTR &= ~(1 << 18)); }while(0)
#define GPIOC_REG_RESET()		do{ (RCC->AHBRSTR |= (1 << 19)); (RCC->AHBRSTR &= ~(1 << 19)); }while(0)
#define GPIOD_REG_RESET()		do{ (RCC->AHBRSTR |= (1 << 20)); (RCC->AHBRSTR &= ~(1 << 20)); }while(0)
#define GPIOF_REG_RESET()		do{ (RCC->AHBRSTR |= (1 << 22)); (RCC->AHBRSTR &= ~(1 << 22)); }while(0)



/*################################
 *	 Some generic macros
 ###############################*/

#define ENABLE			1
#define DISABLE			0
#define SET 			ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

#include "stm32f070xx_gpio_driver.h"

#endif /* INC_STM32F070XX_H_ */
