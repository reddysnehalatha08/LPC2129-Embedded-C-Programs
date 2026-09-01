#include <LPC21xx.h>

int count = 0;

int main()
{
    IODIR0 |= (0xFF << 8);              // LEDs Output
    IODIR0 &= ~((1<<16) | (1<<17));     // SW1 & SW2 Input

    while(1)
    {
        // SW1 : Increment
        if(!(IOPIN0 & (1<<16)))
        {
            while(!(IOPIN0 & (1<<16)));   // Wait for release

            if(count < 255)
                count++;

            IOPIN0 = (IOPIN0 & ~(0xFF<<8)) | ((count ^ 0x0F) << 8);
        }

        // SW2 : Decrement
        else if(!(IOPIN0 & (1<<17)))
        {
            while(!(IOPIN0 & (1<<17)));   // Wait for release

            if(count > 0)
                count--;

            IOPIN0 = (IOPIN0 & ~(0xFF<<8)) | ((count ^ 0x0F) << 8);
        }
    }
}
