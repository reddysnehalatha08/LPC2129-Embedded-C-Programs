#include <LPC21xx.h>
#include "delay.h"

int main()
{
    int i, j;

    IODIR0|= 0xFF;

    for(j = 0; j < 5; j++)
    {
        // All LEDs OFF
        IOPIN0 = 0xF0;
        delay_us(1);          // Use 1-second delay function if required

        // Display the pattern
        for(i = 0; i < 4; i++)
        {
            IOPIN0 = ((1 << i) | (1 << (7 - i))) ^ 0xF0;
            delay_us(1);      // Replace with 1-second delay if needed
        }
    }

    while(1);     // Stop here after 5 repetitions
}
