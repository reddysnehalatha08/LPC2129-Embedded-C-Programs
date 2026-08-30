#include<lpc21xx.h>
#include"types.h"
#include"uart.h"
#include"delay.h"
#define SEG_MASK 0X0FF00000
#define SEG_SHIFT 20
#define SEL1 (1<<28)
#define SEL2 (1<<29)
u8 segcode[16]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X77,0X7C,0X39,0X5E,0X79,0X71};
void mux_display(u8 d1,u8 d2,u32 duration_ms){
	u32 elapsed=0;
	while(elapsed<duration_ms){
		IOCLR0=SEG_MASK|SEL1|SEL2;
		IOSET0=(segcode[d1]<<SEG_SHIFT)|SEL1;
		delay_ms(5);
		IOCLR0=SEG_MASK|SEL1;
		IOSET0=(segcode[d2]<<SEG_SHIFT)|SEL2;
		delay_ms(5);
		IOCLR0=SEL2;
		elapsed+=10;
	}
}
main(){
	u8 rx=0;
	u32 mode=0;
	UART0_Init();
	IODIR0|=SEG_MASK|SEL1|SEL2;
	while(1){
		if(((U0LSR>>0)&1))
			rx=U0_RX();
		if(mode==0)
			mux_display(rx/10,rx%10,500);
		else
			mux_display((rx>>4)&0x0F,rx&0x0F,500);
		mode^=1;
	}
}


		
