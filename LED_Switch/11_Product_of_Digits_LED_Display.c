#include <LPC21xx.h>
#include "delay.h"

int main()
{
    int num = 9876;
    int digit;
    int product = 1;

    IO0DIR |= 0xFF;

    while(num > 0)
    {
        digit = num % 10;
        product = product * digit;
        num = num / 10;
    }

    if(product <= 255)
    {
        IOPIN0 = product ^ 0xF0;
    }
    else
    {
        IOPIN0 = 0x5A;     
    }

    while(1);
}
