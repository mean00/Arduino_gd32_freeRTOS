/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 */
#pragma once


/* Peripheral ADDRESS */

#define LN_DMA0_ADR     (0x40020000)
#define LN_DMA1_ADR     (0x40020400)
#define LN_USART0_ADR   (0x40013800)
#define LN_USART1_ADR   (0x40004400)
#define LN_USART2_ADR   (0x40004800)
#define LN_USART3_ADR   (0x40004C00)
#define LN_USART4_ADR   (0x40005000)
#define LN_SPI0_ADR     (0x40013000)
#define LN_SPI1_ADR     (0x40003800)
#define LN_SPI2_ADR     (0x40003C00)
#define LN_RCU_ADR      (0x40021000)



#define LN_I2C0_ADR     (0x40005400)
#define LN_I2C1_ADR     (0x40005800)

#define LN_EXTI_ADR     (0x40010400)

#define LN_TIMER0_ADR   (0x40012C00)
#define LN_TIMER1_ADR   (0x40000000)
#define LN_TIMER2_ADR   (0x40000400)

#define LN_TIMER5_ADR   (0x40001000)


#define LN_DAC_ADR      (0x40007400)

#define LN_ADC0_ADR      (0x40012400)
#define LN_ADC1_ADR      (0x40012800)

//
#define LN_FMC_ADR      (0x40022000)


//--------------------------------

#define LN_TIMER3_ADR   (0x40000800)
#define LN_TIMER4_ADR   (0x40000C00)

#define LN_TIMER6_ADR   (0x40001400)
#define LN_SYS_TIMER_ADR (0xd1000000)
#define LN_AFIO_ADR     (0x40010000)
#define LN_GPIOA_ADR    (0x40010800)
#define LN_GPIOB_ADR    (0x40010C00)
#define LN_GPIOC_ADR    (0x40011000)
#define LN_GPIOD_ADR    (0x40011400)
#define LN_GPIOE_ADR    (0x40011800)

#define LN_USBD0_ADR     (0x40005c00)
#define LN_USBD0_RAM_ADR (0x40006000)

// RISCV-GD32VF103

#define LN_ECLIC_ADR    (0xd2000000)

// ARM
#define LN_ARM_SCB_ADR  (0xE000ED00)