/*****************************************************/
/* Name: sensorInput.h                               */
/* Author: ENEL300 Group 16                          */
/* Claude Meffan                                     */
/* Copyright: Open Source                            */
/* Brief: Line Follower Robot; Main execution Loop.  */
/*****************************************************/


#ifndef _sensorInput_h
#define _sensorInput_h

//Pin definitions

#define SENS_ONE PIO_DEFINE (PORT_C, 2)
#define SENS_TWO PIO_DEFINE (PORT_C, 3)
#define SENS_THREE PIO_DEFINE (PORT_C, 4)


/*Sets the input pins for Optocouplers as inputs,
It may also configure the analog comparator also... maybe*/
void sensorConfigure (void);


/*Takes a number between 1-3 for which sensor to check and returns 1 if the sensor is
*over a white space (May be adjusted for more logical solution) */
int onLine (int sensor);


#endif
