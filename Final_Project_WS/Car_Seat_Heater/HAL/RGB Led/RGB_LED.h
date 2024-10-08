/*
 * RGB_LED.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Mark
 */

#ifndef HAL_RGB_LED_H_
#define HAL_RGB_LED_H_

#include "std_types.h"





/********************************************************************
 * TYPE DEFINITION
 ********************************************************************/
typedef struct{
    uint8 portNum;
    uint8 PinNums[3]; /*must be added in order red,green,blue*/
}rgb_ledType;





/*****************************************************************
 * Function Declaration
 *****************************************************************/
void rgb_init(rgb_ledType* led);
void rgb_redLedON(rgb_ledType* led);
void rgb_greenLedON(rgb_ledType* led);
void rgb_blueLedON(rgb_ledType* led);
void rgb_redLedOFF(rgb_ledType* led);
void rgb_greenLedOFF(rgb_ledType* led);
void rgb_blueLedOFF(rgb_ledType* led);
void rgb_redLedToggle(rgb_ledType* led);
void rgb_greenLedToggle(rgb_ledType* led);
void rgb_blueLedToggle(rgb_ledType* led);
void rgb_allLedsOff(rgb_ledType* led);



#endif /* HAL_RGB_LED_H_ */
