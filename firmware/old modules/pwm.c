/********************************************************************************/
/* Name: pwm.c                                                                  */
/* Author: ENEL300 Group 16                                                     */
/* Claude Meffan                                                                */
/* Copyright: Open Source                                                       */
/* Date: 2/07/2013                                                              */
/* Brief: Intialisation funcitons for the PWM module of a line Following robot. */
/********************************************************************************/

#include "../../ucfk4/drivers/avr/timer0.h"
#include "../../ucfk4/drivers/avr/pio.h"
#include "pwm.h"

void pwmOutputInit (void)
{
    pio_config_set (PWM_A, PIO_OUTPUT_LOW);
    pio_config_set (PWM_B, PIO_OUTPUT_LOW);
    timer0_init ();
    timer0_mode_set (TIMER0_MODE_PWM);
    
    timer0_output_set (TIMER0_OUTPUT_A, TIMER0_OUTPUT_MODE_SET);
    timer0_output_set (TIMER0_OUTPUT_B, TIMER0_OUTPUT_MODE_SET);
    
    timer0_start ();
}

void pwmFrequencySet(int period)
{
    timer0_period_set (period);
}

int pwmDutySet (int percent, int channelSelect)
{
    int value;
    int rv = 0;
    value = (percent*255)/100;
    
    
    if (value > 255)
    {
        rv = 0;
    }
    
    else
    {
        if (channelSelect == 0)
        {
            OCR0A = value;
            rv = 1;
        }
        else if (channelSelect == 1)
        {
            OCR0B = value;
            rv = 1;
        }
        else if (channelSelect == 2)
        {
            OCR0A = value;
            OCR0B = value;
            rv = 1;
        }
    }
    return rv;
}
