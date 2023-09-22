#pragma once
#include "gpio.hpp"

class LED
{
public:
    LED(GPIO_TypeDef* GPIOx, uint32_t ioNum, bool bLowLevelOn = true)
    : bLowLevelOn_(bLowLevelOn), ledgpio_(GPIOx, ioNum, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_HIGH, bLowLevelOn_ ? GPIO_PUPD_PU : GPIO_PUPD_PD)
    {

    }
    ~LED()
    {
        
    }
    LED(const LED&) = delete;
    LED(LED&&) = delete;
    LED& operator=(const LED&) = delete;
    LED& operator=(LED&&) = delete;

    void on()
    {
        if(bLowLevelOn_)
        {
            ledgpio_.setLevel(GPIO_LEVEL_L);
        }
        else
        {
            ledgpio_.setLevel(GPIO_LEVEL_H);
        }
    }
    void off()
    {
        if(bLowLevelOn_)
        {
            ledgpio_.setLevel(GPIO_LEVEL_H);
        }
        else
        {
            ledgpio_.setLevel(GPIO_LEVEL_L);
        }
    }
private:
    bool bLowLevelOn_;
    GPIO ledgpio_;
};