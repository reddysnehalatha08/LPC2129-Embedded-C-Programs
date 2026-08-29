#include<lpc21xx.h>
# define sw1 1<<16
# define sw2 1<<17
void delay_s(unsigned int tdly){
tdly*=12000000;
while(tdly--);
}
int count=0;
int main(){
	IODIR0|=0xFF<<8;
	IODIR0&=~(sw1|sw2);
	while(1){
		if(!(IOPIN0 &sw1)&& !(IOPIN0&sw2))
		{
		}
		else if(!(IOPIN0 & sw1))
		{
			while(!(IOPIN0 & sw2));
			if(count<255)
				count++;
			IOPIN0=(IOPIN0&~(0xFF<<8))|((count^0x0F)<<8);
delay_s(1);

		}
		else if(!(IOPIN0 & sw2))
		{
			while(!(IOPIN0 & sw1));
			if(count>0)
				count--;
			IOPIN0=(IOPIN0&~(0xFF<<8))|((count^0x0F)<<8);
    delay_s(1);
		}
	}
}
			
			
