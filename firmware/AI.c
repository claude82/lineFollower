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

#include <avr/io.h>

typedef enum
{
        BOT_INACTIVE = 0, FOLLOWING_LINE, FOUND_INTERSECTION, DEAD_END, TURN_AROUND
    
} intelligence_states_t;


