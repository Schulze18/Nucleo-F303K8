/**
  ******************************************************************************
  * @file    LED.c
  * @author  Lucas Schulze
  * @GitHub  /Schulze18/NUCLEO-F303K8
  * @version V1.0
  * @date    20-July-2017
  * @brief   Configure and Blink LED in STM32 Nucleo F303K8 with System Workbench for STM32
  ******************************************************************************
*/

#include "stm32f30x.h"

//Port and Pin of LED
#define PIN_LED		GPIO_Pin_3
#define PORT_LED	GPIOB

//Function prototype
void LED_setup(void);

int main(void)
{
	//Enable Clock from LED's Port
	RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE);

	//Call function to configure LED's Pin
	LED_setup();

	//Main Loop
	while (1){
		//Turn On LED
		GPIO_SetBits(PORT_LED, PIN_LED);
		//Turn Off LED
		GPIO_ResetBits(PORT_LED, PIN_LED);
	}

}

//Function to configure LED's Pin
void LED_setup(void){
	//Create GPIO Init Structure for  LED
	GPIO_InitTypeDef led;

	led.GPIO_Pin = PIN_LED;
	led.GPIO_Mode = GPIO_Mode_OUT;
	led.GPIO_OType = GPIO_OType_PP;
	led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	led.GPIO_Speed = GPIO_Speed_50MHz;

	//Initialize LED's structure
	GPIO_Init(PORT_LED, &led);

}
