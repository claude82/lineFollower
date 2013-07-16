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


//The consistent samples before a action is made
//should allow the bot to drive over the small "road gaps"
#define LINE_DEBOUNCE 40

//Number of left turns executed before the BOT determines it is in a loop
//After four lefts it will execute a right turn to break the loop.
#define ANTI_LOOP 4

typedef enum
{
        BOT_INACTIVE = 0, FOLLOWING_LINE, TURN_AROUND, TURN_LEFT, TURN_RIGHT
    
} intelligence_states_t;
    
    
    
void turnLeft(void)
{
    
    /*TODO adjust the delay until the BOT is turning through the appropriate
     * ammount */
    motorSpeedSet (0, 0);
    motorSpeedSet (50, 1);
    _delay_ms (50);
    motorSpeedSet (0,2);
}
    
    
    


