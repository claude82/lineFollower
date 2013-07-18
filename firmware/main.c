/*****************************************************/
/* Name: main.c                                      */
/* Author: ENEL300 Group 16                          */
/* Claude Meffan                                     */
/* Copyright: Open Source                            */
/* Brief: Line Follower Robot; Main execution Loop.  */
/*****************************************************/

#include "periDrive.h"
#include "AI.h"
#include <util/delay.h>


int main(void)
{
    intelligence_t *mrRoboto;
    motorsInit ();
    motorState(2, 1);
    buttonIntialise ();
    waitForStart (mrRoboto);
    int greyLine = 0;
    
    while ( greyLine == 0 )
    {
        
        //Check sensors, and up the update the sensor values
        updateSensors (mrRoboto);
        if ((mrRoboto->sensor3) == 1)
        {
            pio_output_set (GP_LED, 1);
        }
        else
        {
            pio_output_set (GP_LED, 0);
        }
        //decideAction ();
        //executeAction ();
        
        
    }
    
    
    return 0;               /* never reached */
}