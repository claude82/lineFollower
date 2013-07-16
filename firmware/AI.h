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


/* Turns the BOT aproximately 90 degrees. The BOT will then make adjustments */
/* based on readings from its sensor to re-center itself on the line         */
/* This approach is essentially open loop, however it significantly reduces  */
/* code complexity                                                           */

void turnLeft (void);

#endif
