/* Name: main.c
 * Author: ENEL300 Group 16
 * Claude Meffan
 * Copyright: Open Source
 * Breif: Line Follower Robot; Main execution Loop.
 */

#include <avr/io.h>
#include "../../ucfk4/drivers/avr/pio.h"
#include "../../ucfk4/drivers/avr/timer0.h"

#define PWM_A PIO_DEFINE (PORT_D, 0)

#define PWM_B PIO_DEFINE (PORT_B, 7)

#define PERIOD 20000

int main(void)
{
    pio_config_set (PWM_A, PIO_OUTPUT_LOW);
    pio_config_set (PWM_B, PIO_OUTPUT_LOW);
    
    //Intialising the timer
    timer0_init ();
    timer0_mode_set (TIMER0_MODE_PWM);
    timer0_output_set (TIMER0_OUTPUT_A, TIMER0_OUTPUT_MODE_SET);
    timer0_output_set (TIMER0_OUTPUT_B, TIMER0_OUTPUT_MODE_SET);
    timer0_period_set (PERIOD);
    
    OCR0A = 128;
    OCR0B = 128;
    
    timer0_start ();
    
    while (1)
    {
        //Do Nothing! In Theory the PWM hardware should be doing everything.
        // Yay! It works.
    }
    return 0;               /* never reached */
}