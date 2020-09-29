/**
  ******************************************************************************
  * @file    GPIO/GPIO_Blink/main.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-October-2010
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


void GPIO_Blink(void)
{ 
    int i;
    /* Initialize Leds mounted on STM32 board */
    GPIO_InitTypeDef  GPIO_InitStructure;
    /* Initialize LED which connected to PC6,9, Enable the Clock*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOB, ENABLE);
    /* Configure the GPIO_LED pin */


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_8|GPIO_Pin_9;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_15;
    GPIO_Init(GPIOA, &GPIO_InitStructure);


    while (1)
    {

    	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET){
    		GPIOB->ODR ^= GPIO_Pin_8;
    	}
    	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == Bit_SET){
       		GPIOB->ODR ^= GPIO_Pin_9;
    	}

        GPIOB->ODR ^= GPIO_Pin_6;
        GPIOB->ODR ^= GPIO_Pin_7;


       
        GPIOC->ODR ^= GPIO_Pin_13;

        /* delay */
        for(i=0;i<0x100000;i++);
    }
}
