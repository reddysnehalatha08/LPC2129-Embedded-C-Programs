
#include<lpc21xx.h>
#include"types.h"
#include"uart_defines.h"
void UART0_Init(void){
	PINSEL0&=~15<<0;
	PINSEL0|=TXD0_PIN|RXD0_PIN;
	U0LCR=(1<<DLAB_BIT)|WORD_LEN;
	U0DLL=DIVISOR;
	U0DLM=DIVISOR>>8;
	U0LCR&=~(1<<DLAB_BIT);
}
void U0_TX(u8 sByte){
	U0THR=sByte;
	while(((U0LSR>>TEMT_BIT)&1)==0);
}
u8 U0_RX(void){
	while(((U0LSR>>DR_BIT)&1)==0);
	return U0RBR;
}
void U0_TXstr(s8 *p){
	while(*p)
		U0_TX(*p++);
}
void U0_TXu32(u32 num){
	u8 a[10];
	s32 i=0;
	if(num==0){
		U0_TX('0');
	}
	else{
		while(num>0){
			a[i++]=(num%10)+48;
			num/=10;
		}
		for(--i;i>=0;i--)
		U0_TX(a[i]);
	}
}
void U0_TXs32(s32 num){
	if(num<0)
	{
		U0_TX('-');
		num=-num;
	}
	U0_TXu32(num);
}
void U0_TXF32(f32 fNUM,u32 nDP)	{
	u32 num;
	s32 i;
	if(fNUM<0.0){
		U0_TX('-');
		fNUM=-fNUM;
	}
	num=fNUM;
	U0_TXu32(num);
	U0_TX('.');
	for(i=0;i<nDP;i++){
		fNUM=(fNUM-num)*10;
		num=fNUM;
		U0_TX(num+48);
	}
}
s8*U0_RXstr(void){
	static s8 rbuf[100];
	s32 i=0;
	while(1){
		rbuf[i]=U0_RX();
		U0_TX(rbuf[i]);
		if((rbuf[i]=='\n')||(rbuf[i]=='\r')){
			rbuf[i]='\0';
			break;
		}
		i++;
	}
	return rbuf;
}
void U0_TXHex(u32 num){
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	u8 a[8];
	s32 i=0;
	U0_TXstr((s8*)"0x");
	if(num==0){
		U0_TX('0');
		return;
	}
	while(num>0){
		a[i++]=hex[num%16];
		num=num/16;
	}
	for(--i;i>=0;i--)
	U0_TX(a[i]);
}
