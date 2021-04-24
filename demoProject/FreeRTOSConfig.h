/*
 * FreeRTOS Kernel V10.1.1
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

// This is GD32/RISCV specific
#include "n200_timer.h"
#define configMTIME_BASE_ADDRESS    TIMER_CTRL_ADDR
#define configMTIMECMP_BASE_ADDRESS (TIMER_CTRL_ADDR+8)
#define configISR_STACK_SIZE_WORDS              (200)
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configSUPPORT_STATIC_ALLOCATION         0
#define configPRIO_BITS                         (4UL)
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			0x1
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	0xe
#define configKERNEL_INTERRUPT_PRIORITY                 ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configCPU_CLOCK_HZ			( ( uint32_t long ) SystemCoreClock) 
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )
#define configRTC_CLOCK_HZ                      ((uint32_t)TIMER_FREQ)


//
// FX #define uxTopReadyPriority uxTopUsedPriority // Makes openOCD happy 

/* Library includes. */
// MEANX Not needed for stm32duino #include "stm32f10x_lib.h"

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0
#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK			0
#define configUSE_TICK_HOOK			0 // MEANX
#define configMAX_PRIORITIES                    ( 31 )
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 6 * 1024 ) ) // WAS : 8
#define configAPPLICATION_ALLOCATED_HEAP        1
#define configMAX_TASK_NAME_LEN                 ( 16 )
#define configUSE_TRACE_FACILITY                0
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1
#define configUSE_MUTEXES			1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1

/* This is the value being used as per the ST library which permits 16
priority values, 0 to 15.  This must correspond to the
configKERNEL_INTERRUPT_PRIORITY setting.  Here 15 corresponds to the lowest
NVIC value of 255. */



#define configUSE_MUTEXES			1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_ALTERNATIVE_API 		0
#define configUSE_TIME_SLICING                  0
#define configCHECK_FOR_STACK_OVERFLOW          2
#define configUSE_RECURSIVE_MUTEXES		1
#define configQUEUE_REGISTRY_SIZE		0
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_TIMERS                        0
#if 0 // MEANX Needed ?
#define configCOM0_RX_BUFFER_LENGTH		128
#define configCOM0_TX_BUFFER_LENGTH		128
#define configCOM1_RX_BUFFER_LENGTH		128
#define configCOM1_TX_BUFFER_LENGTH		128


#endif

#endif /* FREERTOS_CONFIG_H */
