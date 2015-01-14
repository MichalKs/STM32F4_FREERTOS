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
#include <FreeRTOS.h>
#include <task.h>
#include <led.h>
#include <comm.h>
#include <malloc.h>
#include <utils.h>

#define DEBUG

#ifdef DEBUG
#define print(str, args...) printf(""str"%s",##args,"")
#define println(str, args...) printf("MAIN--> "str"%s",##args,"\r\n")
#else
#define print(str, args...) (void)0
#define println(str, args...) (void)0
#endif

void blinkerTask(void* param);
void printerTask(void* param);

/**
 * @brief Main
 * @return None
 */
int main(void) {

  COMM_Init(115200);

  // Create an example task
  xTaskCreate(blinkerTask, "LED", 256, NULL,
      tskIDLE_PRIORITY+1, NULL);

  xTaskCreate(printerTask, "COM", 256, NULL,
      tskIDLE_PRIORITY+2, NULL);

  // Start the scheduler
  vTaskStartScheduler();

  // shouldn't reach here
  while (1);

}

/**
 * @brief Task for blinking an LED
 * @param param
 */
void blinkerTask(void* param) {

  LED_Init(LED0); // Add an LED
  LED_Init(LED1); // Add an LED
  LED_Init(LED2); // Add an LED
  LED_Init(LED3); // Add an LED
  LED_Init(LED5); // Add nonexising LED for test

  char* ptr = (char*)malloc(501);

  if (ptr) {
    for (int i = 0; i < 512; i++) {
      ptr[i] = i;
    }
    hexdump(ptr, 512);
  }


  while (1) {


    LED_Toggle(LED0);
    LED_Toggle(LED1);
    vTaskDelay(1000);
  }
}
/**
 * @brief Task for printing strings to terminal.
 * @param param
 */
void printerTask(void* param) {

  while (1) {

    println("Hello World from STM32F4");
    vTaskDelay(1000);
  }

}

/**
 *
 */
void vApplicationMallocFailedHook(void) {
  println("+++++++++++++++++++ Malloc failed");
}
/**
 *
 * @param pxTask
 * @param pcTaskName
 */
void vApplicationStackOverflowHook(xTaskHandle *pxTask,
    signed char *pcTaskName ) {
  println("******************* Stack overflow");
}

