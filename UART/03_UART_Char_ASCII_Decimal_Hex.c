#include<lpc21xx.h>
#include"types.h"
#include"uart.h"
int main(void){
	u8 rx;
	UART0_Init();
	while(1){
		rx=U0_RX();
		U0_TXu32(rx);
		U0_TX(' ');
		U0_TXHex(rx);
		U0_TXstr("\r\n");
	}
}

