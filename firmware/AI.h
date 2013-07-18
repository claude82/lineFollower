/********************************************************************************/
/* Name: AI.h                                                                   */
/* Author: ENEL300 Group 16                                                     */
/* Claude Meffan                                                                */
/* Copyright: Open Source                                                       */
/* Date: 2/07/2013                                                              */
/* Brief: The AI for the line follwoing robot. Makes decisions and executes     */
/* using the peripheral driving module periDrive.c                              */
/********************************************************************************/
#ifndef _AI_h
#define _AI_h

typedef struct {
    int state;
    int sensor1;
    int sensor2;
    int sensor3;
    
} intelligence_t;



/* Turns the BOT aproximately 90 degrees to the left. The BOT will adjust    */
/* based on readings from its sensors to re-center itself on the line         */
/* This approach is essentially open loop.                                    */                                                 
void turnLeft (void);


/* Turns the BOT aproximately 90 degrees to the right. The BOT will adjust    */
/* based on readings from its sensors to re-center itself on the line         */
/* This approach is essentially open loop.                                    */
void turnRight (void);




/* This functions adjusts the heading of the robot so it is realigned with the line */
void adjustHeading (void);




/*Blinks the LED indicating, and waits for the general purpose button to set the BOT */
/* in motion. It will also update the bot intelligence states                        */
void waitForStart (intelligence_t *mrRoboto);


/* Sets the motors to drive forward */
void driveForward (void);


/*Turns the robot around by approximately 180 degrees */
void spin180 (void);

#endif
