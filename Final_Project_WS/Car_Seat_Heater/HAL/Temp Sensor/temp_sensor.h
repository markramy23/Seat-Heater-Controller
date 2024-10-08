/*
 * temp_sensor.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Mark
 */

#ifndef HAL_TEMP_SENSOR_TEMP_SENSOR_H_
#define HAL_TEMP_SENSOR_TEMP_SENSOR_H_

#include "std_types.h"
#include "ADC.h"

/***********************************************************
 * Definitions
 ***********************************************************/
#define TEMP_SENSOR_MAX_VOLT (3.3f)
#define TEMP_SENSOR_MAX_TEMP (45U)

/*********************************************
 * Type Definition
 *********************************************/
typedef struct{
    ADC_ChannelType* adc_channel;
}tempSensor_sensortype;
/*********************************************
 * Function Declaration
 *********************************************/
uint8 tempSensor_readTemp(tempSensor_sensortype* sensor);

#endif /* HAL_TEMP_SENSOR_TEMP_SENSOR_H_ */
