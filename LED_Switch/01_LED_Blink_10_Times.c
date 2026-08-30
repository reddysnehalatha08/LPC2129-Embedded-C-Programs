#include<lpc21xx.h>
#include "delay.h"
int main(){
	int i;
	IODIR0|=1<<0;
	for(i=0;i<10;i++){
		IOSET0|=1<<0;
		delay_us(1);
		IOCLR0|=1<<0;
		delay_us(1);
	}
	while(1);
}


		
		
