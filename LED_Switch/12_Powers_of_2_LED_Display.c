#include <LPC21xx.h>
#include"delay.h"
#define LED 0x000000FF

void delay(unsigned int);

int main()
{
    unsigned int a = 2;
    unsigned int b = 5;
    unsigned int i;
    unsigned int result = 1;

    IODIR0 |= LED;

    // Calculate a^b
    for(i = 0; i < b; i++)
    {
        result = result * a;
    }

    // Display lower 8 bits
    IOCLR0 = LED;
    IOSET0 = result & LED;

    delay_ms(5);

    while(1);
}
