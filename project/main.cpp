#include "mpu.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "delay.hpp"
#include "w25qxx.h"
#include "sdram.h"
#include "gpio.hpp"
#include "usart.hpp"
#include "rcc.hpp"
#include "systeminit.hpp"
#include "led.hpp"
#include "iwdg.hpp"


int main(void)
{
    if(!hwInit())
    {
        while(1);
    }
    LED led(GPIOC, GPIO_NUM_13);
    // GPIO d0(GPIOB, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
    // d0.registerInterruptCb([](GPIO* g, GPIONumBit p){
    //     printf("d0 pin %d isr\r\n",p);
    // });
    // d0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    
    // GPIO A0(GPIOA, GPIO_NUM_0|GPIO_NUM_1|GPIO_NUM_3|GPIO_NUM_11|GPIO_NUM_12, GPIO_MODE_INPUT, GPIO_SPEED_FAST, GPIO_PUPD_PU);
    //     A0.registerInterruptCb([](GPIO* g, GPIONumBit p){
    //     printf("a0 pin %d isr\r\n",p);
    // });
    // A0.enableIsr(GPIO_MODE_IT_FALLING,2,0);
    while(1)
    {
        led.on();
        delayTick(20);
        led.off();
        delayTick(20);
    }
    return 0;
}