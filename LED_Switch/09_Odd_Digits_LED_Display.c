#include <LPC21xx.h>
#include "delay.h"

int main()
{
    int num =9123;
    int digit, rev = 0;
    IODIR0 |= 0xFF;
    while(num > 0)
    {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }

    while(rev > 0)
    {
        digit = rev % 10;

        if(digit % 2 != 0)      // Odd digit
        {
            IOPIN0 = digit ^ 0xF0;
            delay_us(5);
        }

        rev = rev / 10;
    }

    while(1);
}
