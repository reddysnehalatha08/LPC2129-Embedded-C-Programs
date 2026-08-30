#include<lpc21xx.h>
#include"types.h"
#include"uart.h"
main(){
UART0_Init();
U0_TXstr("Welcome to Vector");
  while(1);
  }
