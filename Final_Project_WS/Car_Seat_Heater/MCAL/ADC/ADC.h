/*
 * ADC.h
 *
 *  Created on: Aug 11, 2024
 *      Author: Mark
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "std_types.h"
#include "Common_Macros.h"
#include "gpio.h"
/*****************************************************
 * Channels Definition                               *
 *****************************************************/
#define ADC_AIN0            0
#define ADC_AIN1            1
#define ADC_AIN2            2
#define ADC_AIN3            3
#define ADC_AIN4            4
#define ADC_AIN5            5
#define ADC_AIN6            6
#define ADC_AIN7            7
#define ADC_AIN8            8
#define ADC_AIN9            9
#define ADC_AIN10           10
#define ADC_AIN11           11

#define ERROR_SAMPLE        0xBEE

#define ADC_MAX_VALUE       4096
#define ADC_REF_VOLTAGE     (3.3f)
/*****************************************************
 * Type Definition                                   *
 *****************************************************/
typedef struct{

    uint8 port;
    uint8 pin;
    uint8 channelNum;
}ADC_ChannelType;

extern const ADC_ChannelType ADC_channels[12];
/*****************************************************
 * Function Declaration                                  *
 *****************************************************/
void ADC0_init(const ADC_ChannelType* channel);
boolean ADC0_busy();
void ADC0_startConversion();
uint16 ADC0_readValue();
void ADC0_changeChannel(const ADC_ChannelType* channel);




#endif /* MCAL_ADC_ADC_H_ */
