/*
 * RGB_LED.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Mark
 */
#include "RGB_LED.h"
#include "gpio.h"

void rgb_init(rgb_ledType* led)
{
    uint8 i;
    for(i=0;i<3;i++)
    {
        GPIO_setupPinDirectionAndMode(led->portNum, led->PinNums[i], PIN_OUTPUT, PORT_MODE_DIO, NO_RESISTOR);
    }
}

void rgb_redLedON(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[0], led->portNum, LOGIC_HIGH);
}
void rgb_greenLedON(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[1], led->portNum, LOGIC_HIGH);
}
void rgb_blueLedON(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[2], led->portNum, LOGIC_HIGH);
}
void rgb_redLedOFF(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[0], led->portNum, LOGIC_LOW);
}
void rgb_greenLedOFF(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[1], led->portNum, LOGIC_LOW);
}
void rgb_blueLedOFF(rgb_ledType* led)
{
    GPIO_writePin(led->PinNums[2], led->portNum, LOGIC_LOW);;
}
void rgb_redLedToggle(rgb_ledType* led)
{
    GPIO_togglePin(led->portNum, led->PinNums[0]);
}
void rgb_greenLedToggle(rgb_ledType* led)
{
    GPIO_togglePin(led->portNum, led->PinNums[1]);
}
void rgb_blueLedToggle(rgb_ledType* led)
{
    GPIO_togglePin(led->portNum, led->PinNums[2]);
}
void rgb_allLedsOff(rgb_ledType* led)
{
    uint8 i;
       for(i=0;i<3;i++)
       {
           GPIO_writePin(led->PinNums[i], led->portNum, LOGIC_LOW);
       }

}
