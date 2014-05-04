/**
 * @file: 	FreeRTOSConfig.h
 * @brief:	   
 * @date: 	12 kwi 2014
 * @author: Michal Ksiezopolski
 * 
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the 
 * accompanying materials are made available 
 * under the terms of the GNU Public License 
 * v3.0 which accompanies this distribution, 
 * and is available at 
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */

#ifndef FREERTOSCONFIG_H_
#define FREERTOSCONFIG_H_

#include <stm32f4xx.h>

#define configUSE_PREEMPTION			1 ///< 1 - preemptive scheduler, 0 - cooperative scheduler
#define configUSE_IDLE_HOOK				0 ///< 1 - use an IDLE hook (called in IDLE task)
#define configUSE_TICK_HOOK				0 ///< 1 - use TICK hook function (called in tick interrupt)
#define configCPU_CLOCK_HZ				( SystemCoreClock ) ///< CPU core clock
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 ) ///< SysTick rate in Hz
#define configMAX_PRIORITIES			( 5 ) ///< Maximum number of priotities
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 60 ) ///< Size of stack used by IDLE task (in words, not bytes!)
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 6500 ) ) ///< Heap size for use of the kernel
#define configMAX_TASK_NAME_LEN			( 5 ) ///< Maximum length of task name (including the '\0' terminating byte)
#define configUSE_TRACE_FACILITY		1 ///< Some debugging bullshit?
#define configUSE_16_BIT_TICKS			0 ///< 16 bit (1) or 32 bit (0) tick counter
#define configIDLE_SHOULD_YIELD			1 ///< IDLE yields immediately if any other task with same priority as IDLE is ready to run
#define configUSE_MUTEXES				1 ///< WTF?
#define configUSE_COUNTING_SEMAPHORES	1 ///< 1 - use counting semaphores
#define configCHECK_FOR_STACK_OVERFLOW	2 ///< 0 - no overflow check, 1 - method 1, 2 - method 2
#define configQUEUE_REGISTRY_SIZE		8 ///< For debugging - useless
#define configUSE_RECURSIVE_MUTEXES		1
#define configUSE_MALLOC_FAILED_HOOK	1 ///< 1 - use a malloc failed hook
#define configUSE_APPLICATION_TASK_TAG	0
#define configGENERATE_RUN_TIME_STATS	0
#define configMAX_SYSCALL_INTERRUPT_PRIORITY	5

#define configUSE_CO_ROUTINES 			0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

#define configUSE_TIMERS				1
#define configTIMER_TASK_PRIORITY		( 2 )
#define configTIMER_QUEUE_LENGTH		5
#define configTIMER_TASK_STACK_DEPTH	( 80 )

#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	1
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#define vPortSVCHandler 		SVC_Handler
#define xPortPendSVHandler 		PendSV_Handler
#define xPortSysTickHandler 	SysTick_Handler

#endif /* FREERTOSCONFIG_H_ */
