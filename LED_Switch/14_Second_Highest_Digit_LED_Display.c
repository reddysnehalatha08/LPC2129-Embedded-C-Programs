#include <LPC21xx.h>
#include "delay.h"

int main()
{
    int num = 7392;      
    int digit;
    int max = -1, second = -1;

    IO0DIR |= 0xFF;          

    while(num > 0)
    {
        digit = num % 10;

        if(digit > max)
        {
            second = max;
            max = digit;
        }
        else if(digit > second && digit != max)
        {
            second = digit;
        }

        num = num / 10;
    }

  
    IOPIN0 = second ^ 0xF0;

    while(1);
}
