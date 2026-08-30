#include<lpc21xx.h>
#include"types.h"
#include"uart.h"
#define MAX_LEN 50
main(){
	u8 pwd[MAX_LEN];
	u8 i=0, ch;
	u8 hasdigit=0,haslower=0,hasupper=0,hasspecial=0,hasspace=0,hasslash=0;
	UART0_Init();
	while(1){
	U0_TXstr((u8*)"Enter Password:\r\n");
	do{
		ch=U0_RX();
		if(ch!='\r'&&ch!='\n'&&i<MAX_LEN-1){
			pwd[i++]=ch;
			U0_TX(ch);
			
		}
	}
	while(ch!='\r'&&ch!='\n');
	
	pwd[i]='\0';
	for(i=0;pwd[i]!='\0';i++)
	{
		ch=pwd[i];
		if(ch>='0'&&ch<='9')
			hasdigit=1;
		else if(ch>='a'&&ch<='z')
			haslower=1;
		else if(ch>='A'&&ch<='Z')
			hasupper=1;
		else if(ch==' ')
			hasspace=1;
		else if(ch=='/')
			hasslash=1;
		else
			hasspecial=1;
	}
	U0_TXstr((u8*)"\r\n");
if(i>=8&&hasdigit&&haslower&&hasupper&&hasspecial&&!hasspace&&!hasslash){
	U0_TXstr((u8*)"valid password\r\n");
}
else{
	U0_TXstr((u8*)"Invalid password\r\n");
}
}
}

	
	
