/*****************************************************/
/* Name: sensorInput.c                               */
/* Author: ENEL300 Group 16                          */
/* Claude Meffan                                     */
/* Copyright: Open Source                            */
/* Brief: Line Follower Robot; Main execution Loop.  */
/*****************************************************/

#include "../../ucfk4/drivers/avr/pio.h"
#include "sensorInput.h"

void sensorConfigure (void)
{
    pio_config_set (SENS_ONE, PIO_INPUT);
    pio_config_set (SENS_TWO, PIO_INPUT);
    pio_config_set (SENS_THREE, PIO_INPUT);
    
    //TODO for sensor one I need to set a few bits to enable the analog comparator.
    //This should allow us to sense the grey line.
    //possibly may need to implement a bandgap comparator
    //if not just figure out something else
    
}



int onLine (int sensor)
{
    int rv = 0;
    
    if (sensor == 1)
    {
        if (pio_input_get (SENS_ONE) == 1)
        {
            rv = 1;
        }
    }
    
    
    else if (sensor == 2)
    {
        if (pio_input_get (SENS_TWO) == 1)
        {
            rv = 1;
        }
    }
    
    else if (sensor = 3)
    {
        if (pio_input_get (SENS_THREE) == 1)
        {
            rv = 1;
        }
    }
    
    
    return rv;
}
