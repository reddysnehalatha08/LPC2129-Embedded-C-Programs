#include<lpc21xx.h>
#include"types.h"
#include"uart.h"
main(){
u8 rx;
UART0_Init();
IODIR0|=0XFF<<8;
while(1){
rx=U0_RX();
IOPIN0=(IOPIN0 & ~(0X0F<<8))|((~rx & 0X0F)<<8);
IOPIN0=(IOPIN0 & ~(0X0F<<8))|((~rx & 0XF0)<<8);
}
}
