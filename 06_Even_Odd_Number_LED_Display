#include <LPC21xx.h>
#include "delay.h"
int even = 0;
int odd  = 1;


int main()
{
    IODIR0 |= (0xFF<<8);              // LEDs
    IODIR0 &= ~((1<<16)|(1<<17));     // SW1 SW2

    while(1)
    {
        // SW1 : Even Numbers
        if(!(IOPIN0&(1<<16)))
        {
            while(IOPIN0&(1<<17))
            {
                IOPIN0=(IOPIN0&~(0xFF<<8))|((even^0x0F)<<8);

                delay_ms(1);

                even += 2;

                if(even > 254)
                    even = 0;
            }
        }

        // SW2 : Odd Numbers
        if(!(IOPIN0&(1<<17)))
        {
            while(IOPIN0&(1<<16))
            {
                IOPIN0=(IOPIN0&~(0xFF<<8))|((odd^0x0F)<<8);

                delay_us(1);

                odd += 2;

                if(odd > 255)
                    odd = 1;
            }
        }
    }
}
