/*****************************************************/
/* Name: main.c                                      */
/* Author: ENEL300 Group 16                          */
/* Claude Meffan                                     */
/* Copyright: Open Source                            */
/* Brief: Line Follower Robot; Main execution Loop.  */
/*****************************************************/

#include "periDrive.h"
#include "../../ucfk4/drivers/avr/pio.h"



int main(void)
{
        
    pwmOutputInit ();
    pwmFrequencySet (5000);
    pwmDutySet (50, 2);
    
    while (1)
    {
        //Do Nothing! In Theory the PWM hardware should be doing everything.
    }
    return 0;               /* never reached */
}