#include <LPC21xx.h>


int main()
{
    int num = 76543;
    int sum = 0;

    IO0DIR |= 0xFF;

    while(num > 0)
    {
        sum = sum + (num % 10);
        num = num / 10;
    }

    IOPIN0 = sum ^ 0xF0;

    while(1);
}
