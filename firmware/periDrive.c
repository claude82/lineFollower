/********************************************************************************/
/* Name: periDrive.c                                                            */
/* Author: ENEL300 Group 16                                                     */
/* Claude Meffan                                                                */
/* Copyright: Open Source                                                       */
/* Date: 2/07/2013                                                              */
/* Brief: Intialisation funcitons for the PWM module and optical Sensors for a  */
/* line following robot.                                                        */
/********************************************************************************/

#include "../../ucfk4/drivers/avr/timer0.h"
#include "../../ucfk4/drivers/avr/pio.h"
#include "periDrive.h"
#include "AI.h"

void buttonIntialise(void)
{
    pio_config_set (GP_BUTTON, PIO_INPUT);
}



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

int motorSpeedSet (int percent, int channelSelect)
{
    int value;
    int rv = 0;
    value = ((100-percent)*255)/100;
    
    
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
    
    if (sensor == 0)
    {
        if (pio_input_get (SENS_ONE) == 0)
        {
            rv = 1;
        }
    }
    
    
    else if (sensor == 1)
    {
        if ((pio_input_get (SENS_TWO) == 0))
        {
            rv = 1;
        }
    }
    
    else if (sensor == 2)
    {
        if (pio_input_get (SENS_THREE) == 0)
        {
            rv = 1;
        }
    }
    
    
    return rv;
}

void motorsInit (void)
{
    
    pwmOutputInit ();
    pwmFrequencySet (5000);

    motorSpeedSet (0, 2);
    pio_config_set (MOTOR_TWO_ENABLE, PIO_OUTPUT_LOW);
    pio_config_set (MOTOR_TWO_A, PIO_OUTPUT_LOW);
    pio_config_set (MOTOR_ONE_ENABLE, PIO_OUTPUT_LOW);
    pio_config_set (MOTOR_ONE_B, PIO_OUTPUT_LOW);
}

int motorState (int motor, int state)
{
    int rv = 1;
    
    if (motor == 0)
    {
        pio_output_set (MOTOR_ONE_ENABLE, state);
    }
    
    else if (motor == 1)
    {
        pio_output_set (MOTOR_TWO_ENABLE, state);
    }
    
    else if (motor == 2)
    {
        pio_output_set (MOTOR_ONE_ENABLE, state);
        pio_output_set (MOTOR_TWO_ENABLE, state);
    }
    
    else
    {
        rv = 0;
    }
    
    return rv;
}

void updateSensors (intelligence_t *mrRoboto)
{
    int sample;
    int sensor;
    //four samples is the debounce delay
    int good = 1;
    int reading = 0;

    for (sensor = 0; sensor < 3; sensor++)
    {
        int lastSensorState = onLine (sensor);
        
        for (sample = 0; sample <= 6; sample++)
        {
            reading = onLine (sensor);
            
            if (reading != lastSensorState)
            {
                //good = 0;
            }
            
            // If the sample as been there for longer than the required delay,
            // it is actually there so  re-write the sensor state
        }
        if (good == 1)
        {
            if (sensor == 0)
            {
                mrRoboto->sensor1 = lastSensorState;
            }
            else if (sensor == 1)
            {
                mrRoboto->sensor2 = lastSensorState;
            }
            else if (sensor == 2)
            {
                mrRoboto->sensor3 = lastSensorState;
            }
        }
        else
        {
            sensor--;
        }
    }
}

