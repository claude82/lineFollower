/* Name: main.c
 * Author: ENEL300 Group 16
 * Claude Meffan
 * Copyright: Open Source
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../../ucfk4/drivers/avr/pio.h"

#define OPTO_PIO PIO_DEFINE (PORT_D, 0)
#define LED_PIO PIO_DEFINE (PORT_D, 1)

int main(void)
{
    pio_config_set (OPTO_PIO, PIO_INPUT);
    pio_config_set (LED_PIO, PIO_OUTPUT_LOW);
    while (1)
    {
        if (pio_input_get(OPTO_PIO) == 1)
        {
            pio_output_high (LED_PIO);
        }
        else
        {
            pio_output_low (LED_PIO);
        }
    }
    return 0;               /* never reached */
}