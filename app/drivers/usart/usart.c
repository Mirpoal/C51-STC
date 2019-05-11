#include "usart.h"

#if 12MHZ
void UsartConfiguration(u32 baud)      
{
	SCON = 0x50; 
    TMOD &= 0x0F; 
    TMOD |= 0x20; 
    TH1 = 256 - (12000000/12/32) / baud; 
    TL1 = TH1; 
    ET1 = 0; 
    TR1 = 1; 					
}

void UsartSendData(char dat)
{
    ES=0;           
    SBUF=dat;           
    while(TI!=1);   
    TI=0;           
    ES=1;           
}

// overwrite putchar method
char putchar(char c)
{
    UsartSendData(c);
    return c;
}

#endif

#if 11MHZ
void UsartConfiguration(u32 baud)    
{
    SCON = 0x50; 
    TMOD &= 0x0F; 
    TMOD |= 0x20; 
    TH1 = 256 - (11059200/12/32) / baud; 
    TL1 = TH1; 
    ET1 = 0; 
    TR1 = 1; 
}


void UsartSendData(char dat)
{
    ES=0;           
    SBUF=dat;           
    while(TI!=1);   
    TI=0;           
    ES=1;           
}


// overwrite putchar method
char putchar(char c)
{
    UsartSendData(c);
    return c;
}

#endif