/**
 * @file: 	main.c
 * @brief:  FREE RTOS test project.
 * @date: 	9 kwi 2014
 * @author: Michal Ksiezopolski
 *
 * This is a very simple library for controlling
 * LEDs.
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
 *
 */


#include "FreeRTOS.h"
#include "task.h"
#include "led.h"
#include "uart.h"
#include <stdio.h>

/**
 * @brief Task for blinking an LED
 * @param param
 */
void BlinkerTask(void* param) {

	LED_TypeDef led;
	led.nr = LED0;
	led.gpio = GPIOD;
	led.pin = 12;
	led.clk = RCC_AHB1Periph_GPIOD;

	LED_Add(&led); // Add an LED

	while (1) {

		LED_Toggle(LED0); // Toggle LED
		uint32_t i = 3000000;
		while (i--); // delay
	}
}

/**
 *
 * @return
 */
int main(void)
{

	// Create an example task
	xTaskCreate( BlinkerTask, "Blink", configMINIMAL_STACK_SIZE, NULL, 1, NULL );

	// Start the scheduler
	vTaskStartScheduler();

	while (1) {

	}

}


void vApplicationMallocFailedHook (void) {

}

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName ) {

}


