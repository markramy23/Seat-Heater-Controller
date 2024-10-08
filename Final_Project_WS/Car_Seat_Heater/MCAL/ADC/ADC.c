/*
 * ADC.c
 *
 *  Created on: Aug 11, 2024
 *      Author: Mark
 */

#include "ADC.h"
#include "tm4c123gh6pm_registers.h"

const ADC_ChannelType ADC_channels[12] = { GPIO_PORTE,PIN3_ID,ADC_AIN0,
                                           GPIO_PORTE,PIN2_ID,ADC_AIN1,
                                           GPIO_PORTE,PIN2_ID,ADC_AIN2,
                                           GPIO_PORTE,PIN0_ID,ADC_AIN3,
                                           GPIO_PORTD,PIN3_ID,ADC_AIN4,
                                           GPIO_PORTD,PIN2_ID,ADC_AIN5,
                                           GPIO_PORTD,PIN1_ID,ADC_AIN6,
                                           GPIO_PORTD,PIN0_ID,ADC_AIN7,
                                           GPIO_PORTE,PIN5_ID,ADC_AIN8,
                                           GPIO_PORTE,PIN4_ID,ADC_AIN9,
                                           GPIO_PORTB,PIN4_ID,ADC_AIN10,
                                           GPIO_PORTB,PIN5_ID,ADC_AIN11
};
void ADC0_init(const ADC_ChannelType* channel)
{
    SET_BIT(SYSCTL_RCGCADC_REG,0); /*Enabling clock for ADC0*/
    GPIO_setupPinDirectionAndMode(channel->port, channel->pin, PIN_INPUT, PORT_MODE_ANALOG, NO_RESISTOR);
    CLEAR_BIT(ADC0_ACTSS_R,3); /*Disable sequencer 3 before configuration*/
    ADC0_EMUX_R &= ~(0xF << 12); /* Triggering ADC using Software */
    ADC0_SSMUX3_R = channel->channelNum; /*initial channel for sample sequencer 3 to use*/
    SET_BIT(ADC0_SSCTL3_R,1); /*This bit must be set before initiating a single sample sequence.*/
    SET_BIT(ADC0_SSCTL3_R,2); /*The raw interrupt signal (INR0 bit) is asserted at the end of this sample's conversion.*/
    SET_BIT(ADC0_ACTSS_R,3); /*Enabling Sample sequencer 3 */

}

boolean ADC0_busy()
{
    if(GET_BIT(ADC0_RIS_R,3) == LOGIC_HIGH)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void ADC0_startConversion()
{
    SET_BIT(ADC0_PSSI_R,3);
}

uint16 ADC0_readValue()
{
    if(FALSE==ADC0_busy())
    {
        SET_BIT(ADC0_ISC_R,3);
        return (uint16)ADC0_SSFIFO3_R; /*Return the value only if the adc finished conversion*/

    }
    else
    {
        return (uint16) ERROR_SAMPLE; /* return ERROR code if coversion is not fnished*/
    }
}

void ADC0_changeChannel(const ADC_ChannelType* channel)
{
    CLEAR_BIT(ADC0_ACTSS_R,3); /*Disable sequencer 3 before configuration*/
    GPIO_setupPinDirectionAndMode(channel->port, channel->pin, UNDEFINED, PORT_MODE_ANALOG, NO_RESISTOR);
    ADC0_SSMUX3_R = channel->channelNum;
    SET_BIT(ADC0_ACTSS_R,3); /*Enabling Sample sequencer 3 */

}
