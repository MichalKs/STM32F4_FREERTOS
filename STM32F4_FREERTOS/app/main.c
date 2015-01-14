/**
 * @file    main.c
 * @brief   LED test
 * @date    9 kwi 2014
 * @author  Michal Ksiezopolski
 *
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

#include <stdio.h>
#include <string.h>
#include <led.h>

#define DEBUG

#ifdef DEBUG
#define print(str, args...) printf(""str"%s",##args,"")
#define println(str, args...) printf("MAIN--> "str"%s",##args,"\r\n")
#else
#define print(str, args...) (void)0
#define println(str, args...) (void)0
#endif


#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

/**
 * @brief Task for blinking an LED
 * @param param
 */
void BlinkerTask(void* param) {

  LED_Init(LED0); // Add an LED
  LED_Init(LED1); // Add an LED
  LED_Init(LED2); // Add an LED
  LED_Init(LED3); // Add an LED
  LED_Init(LED5); // Add nonexising LED for test


  while (1) {

    LED_Toggle(LED0);
    LED_Toggle(LED1);
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
  xTaskCreate(BlinkerTask, "LED", 128, NULL,
      tskIDLE_PRIORITY+1, NULL);

  // Start the scheduler
  vTaskStartScheduler();

  while (1) {

  }

}


void vApplicationMallocFailedHook (void) {

}

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName ) {

}

