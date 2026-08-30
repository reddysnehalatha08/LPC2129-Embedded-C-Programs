#include "types.h"
void UART0_Init(void);
void U0_TX(u8 sByte);
u8  U0_RX(void);
void U0_TXstr(s8*);
void U0_TXu32(u32);
void U0_TXs32(s32);
void U0_TXF32(f32,u32);
s8* U0_RXstr(void);
void  U0_TXHex(u32 num);
