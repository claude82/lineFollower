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
    motorsInit ();
    motorState(2, 1);
    
    while (1)
    {
        //The main execution loop of the robot.
    }
    return 0;               /* never reached */
}