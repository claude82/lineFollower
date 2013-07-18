/***************************************************/
/* Name: AI.c                                      */
/*                                                 */
/* Author: ENEL300 Group 16                        */
/* Claude Meffan,                                  */
/* Copyright: Open Source                          */
/* Date: 2/07/2013                                 */
/*                                                 */
/* Brief: The artificial Intelligence module       */
/* for the line following robot, essentially a     */
/* state machine based on a few situations         */
/***************************************************/

#include <util/delay.h>
#include "periDrive.h"
#include "AI.h"
#include "../../ucfk4/drivers/avr/pio.h"


//The consistent samples before a action is made
//should allow the bot to drive over the small "road gaps"
#define LINE_DEBOUNCE 40

//Number of left turns executed before the BOT determines it is in a loop
//After four lefts it will execute a right turn to break the loop.
#define ANTI_LOOP 4

typedef enum
{
        BOT_INACTIVE = 0, FOLLOWING_LINE, TURN_AROUND, TURN_LEFT, TURN_RIGHT, BOT_LOST
    
} intelligence_states_t;
    
    
    
void turnLeft(void)
{
    /*TODO adjust the delay until the BOT is turning through the appropriate
     * ammount */
    motorSpeedSet (100, 2);
    _delay_ms (100);
    motorSpeedSet (0, 0);
    motorSpeedSet (100, 1);
    _delay_ms (130);
    motorSpeedSet (0,2);
}

void turnRight (void)
{
    motorSpeedSet (100, 2);
    _delay_ms (100);
    motorSpeedSet (0, 1);
    motorSpeedSet (100, 0);
    //turnign right seems to take a little longer. Probly due to the lack of wheels
    _delay_ms (130);
    motorSpeedSet (0,2);
}

void spin180 (void)
{
    //changes the driving direction of the motor
    pio_config_set (MOTOR_TWO_A, PIO_OUTPUT_HIGH);
    motorSpeedSet (100, 0);
    motorSpeedSet (0, 1);
    _delay_ms(145);
    motorSpeedSet(0,2);
    //resets the motor
    pio_config_set (MOTOR_TWO_A, PIO_OUTPUT_LOW);
    
}

void adjustHeading(void)
{
    int count = 0;
    
    while (onLine (1) == 0)
    {
        if (count < 50)
        {
            motorSpeedSet (50, 1);
            pio_output_set (MOTOR_TWO_A, 1);
            motorSpeedSet (50, 0);
        }
        else if ((count < 100) && (count > 50))
        {
            pio_output_set (MOTOR_TWO_A, 0);
            pio_output_set (MOTOR_ONE_B, 1);
        }
        else
        {
            pio_output_set (MOTOR_ONE_B, 0);
            pio_output_set (MOTOR_TWO_A, 1);
        }
        
        if ( count == 200)
        {
            count = 0;
        }
        
        
        
        motorSpeedSet (0, 0);
    }
}

void driveForward (void)
{
    motorSpeedSet (50, 2);
}




void waitForStart (intelligence_t *mrRoboto)
{
    long count = 0;
    mrRoboto->state = BOT_INACTIVE;
    
    while (pio_input_get(GP_BUTTON) == 0)
    {
        if (count == 10000)
        {
            pio_output_toggle (GP_LED);
            count = 0;
        }
        count ++;
    }
    
    pio_output_set (GP_LED, 0);
    mrRoboto->state = FOLLOWING_LINE;
}
    
    
    


