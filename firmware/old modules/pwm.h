/***************************************************/
/* Name: pwm.h                                     */
/* Author: ENEL300 Group 16                        */
/* Claude Meffan                                   */
/* Copyright: Open Source                          */
/* Date: 2/07/2013                                 */
/* Brief: Header File for the PWM Module           */
/***************************************************/

#ifndef _pwm_h
#define _pwm_h

#include "../../ucfk4/drivers/avr/pio.h"

#define PWM_A PIO_DEFINE (PORT_D, 0)

#define PWM_B PIO_DEFINE (PORT_B, 7)



/*This fucntion sets all the timer0 register (TCCR01) to 
 /the approriate values for phase correct PWM. */
void pwmOutputInit (void);


/*This function sets the frequency of the PWM waveforms.
 / the input is the period of the PWM waveform in clock ticks
 void output*/
void pwmFrequencySet(int period);


/* pwmDutySet sets the duty cycle of the two PWM channels
 / the input is the desired Duty Cycle in percent, and the 
 / desired channel ouput to set the Duty cycle of.
 /(0 = OCR0A, 1 = OCR0B, 2 = OCR0B && OCR0B)
 */
int pwmDutySet (int percent, int channelSelect);



#endif
