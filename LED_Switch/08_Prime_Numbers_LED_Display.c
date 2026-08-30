#include <LPC21xx.h>
#include "delay.h"
int IsPrime(int n)
{
    int i;
    if(n < 2)
        return 0;
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int i;
    IODIR0 |= 0xFF;          
    while(1)
    {
        for(i = 0; i <= 50; i++)
        {
            if(IsPrime(i))
            {
                IOPIN0 = i ^ 0xF0;   
                delay_us(5);        
            }
        }
    }
}

