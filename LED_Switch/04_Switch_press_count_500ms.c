#include<LPC21xx.h>
#include "delay.h"

int count,t;
int main()
{
	IODIR0|=255<<8;
	while(1)
	{
		count=0;
		while(((IOPIN0 >> 16)& 1)==1);
		while(((IOPIN0 >> 16)& 1)==0);
		count=1;
		for(t=0;t<500;t++)
		{
	if(((IOPIN0 >>16) & 1)==0)
	{
		while(((IOPIN0 >> 16) &1)==0);
		count++;
		if(count>=255)
			count=255;
	}
	delay_ms(1);
}
	IOPIN0=((IOPIN0 & ~(255<<8) )| count<<8);
	
	}
	}
