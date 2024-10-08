/*
 * temp_sensor.c
 *
 *  Created on: Aug 18, 2024
 *      Author: Mark
 */

#include "temp_sensor.h"

uint8 tempSensor_readTemp(tempSensor_sensortype* sensor)
{
    uint16 adcValue;
    float volt;
    uint8 temp;
    ADC0_changeChannel(sensor->adc_channel);
    ADC0_startConversion();
    while(ADC0_busy());
    adcValue = ADC0_readValue();
    volt = (float)(((double)adcValue*ADC_REF_VOLTAGE)/ADC_MAX_VALUE);
    temp= (uint8)(((double)volt*TEMP_SENSOR_MAX_TEMP)/TEMP_SENSOR_MAX_VOLT);
    return temp;
}


