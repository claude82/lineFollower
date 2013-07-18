/********************************************************************************/
/* Name: periDrive.h                                                            */
/* Author: ENEL300 Group 16                                                     */
/* Claude Meffan                                                                */
/* Copyright: Open Source                                                       */
/* Date: 2/07/2013                                                              */
/* Brief: Intialisation funcitons for the PWM module and optical Sensors for a  */
/* line following robot.                                                        */
/********************************************************************************/

#ifndef _periDrive_h
#define _periDrive_h

#include "../../ucfk4/drivers/avr/pio.h"
#include "AI.h"

//Pin definitions

//PORT B pins

#define MOTOR_TWO_ENABLE PIO_DEFINE (PORT_B, 4)

#define MOTOR_ONE_B PIO_DEFINE (PORT_B, 6)

#define PWM_B PIO_DEFINE (PORT_B, 7)

//PORT C pins

#define SENS_ONE PIO_DEFINE (PORT_C, 2)

#define SENS_TWO PIO_DEFINE (PORT_C, 4)

#define SENS_THREE PIO_DEFINE (PORT_C, 5)

//PORT D pins

#define PWM_A PIO_DEFINE (PORT_D, 0)

#define MOTOR_TWO_A PIO_DEFINE (PORT_D, 2)

#define MOTOR_ONE_ENABLE PIO_DEFINE (PORT_D, 4)

#define GP_LED PIO_DEFINE (PORT_D, 5)

#define GP_BUTTON PIO_DEFINE (PORT_D, 7)




/* Sets the genreal purpose button configured on PD7 as an input   */
/* Used for signaling the bot to start the maze                     */

void buttonIntialise (void);


/*This fucntion sets all the timer0 register (TCCR01) to
 /the approriate values for phase correct PWM. */
void pwmOutputInit (void);


/*This function sets the frequency of the PWM waveforms.
 / the input is the period of the PWM waveform in clock ticks
 void output*/
void pwmFrequencySet(int period);


/* pwmDutySet sets the duty cycle of the two PWM channels
 / the input is the desired Duty Cycle in percent, and the
 / desired channel ouput to set the Duty cycle of.
 /(0 = OCR0A, 1 = OCR0B, 2 = OCR0B && OCR0B)
 */
int motorSpeedSet (int percent, int channelSelect);


/*Sets the input pins for Optocouplers as inputs,
 It may also configure the analog comparator also... maybe*/
void sensorConfigure (void);


/*Takes a number between 1-3 for which sensor to check and returns 1 if the sensor is
 *over a white space (May be adjusted for more logical solution) */
int onLine (int sensor);


/* Configureds the PWM module and sets the duty cycle for both motors to zero. To drive 
 *the motors the MOTOR_(1,2)_ENABLE needs to be brought high, and the duty cycle needs to 
 be increased from zero */

void motorsInit (void);


/*Enable or disables the motors, "motor" is an an integer 0 = Motor One, 
 * 1 = Motor Two, 2 = Both. State is a boolean 0 = Off, 1 = On.
 */
int motorState (int motor, int state);


/*Updates, and debounces the optical sensor readings */
/*Takes the AI structure as input                    */

void updateSensors (intelligence_t *mrRoboto);




#endif
