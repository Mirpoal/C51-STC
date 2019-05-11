#include "lcd1602.h"
#include "../../conf.c"
#include "../../utils/time.h"
#include "../../utils/log.h"

#if LOAD_LCD1602_MODULE

#if LCD1602_4PINS

void LcdWriteCom(uchar com)	 
{
	LCD1602_E = 0;    
	LCD1602_RS = 0;	   
	LCD1602_RW = 0;	  
	
	LCD1602_DATAPINS = com;     
	sleepMS(1);		

	LCD1602_E = 1;	        
	sleepMS(5);	 
	LCD1602_E = 0;
}

void LcdWriteData(uchar dat)			
{
	LCD1602_E = 0;	
	LCD1602_RS = 1;	
	LCD1602_RW = 0;	

	LCD1602_DATAPINS = dat; 
	sleepMS(1);

	LCD1602_E = 1;  
	sleepMS(5);  
	LCD1602_E = 0;
}

void LcdInit()						 
{
 	LcdWriteCom(0x38);  
	LcdWriteCom(0x0c);  
	LcdWriteCom(0x06);  
	LcdWriteCom(0x01); 
	LcdWriteCom(0x80);  
}

#endif


#if LCD1602_8PINS

void LcdWriteCom(uchar com)	  
{
	LCD1602_E = 0;	 
	LCD1602_RS = 0;	
	LCD1602_RW = 0;	 

	LCD1602_DATAPINS = com;	
	sleepMS(1);

	LCD1602_E = 1;	 
	sleepMS(5);
	LCD1602_E = 0;

//	sleepMS(1);
	LCD1602_DATAPINS = com << 4; 
	sleepMS(1);

	LCD1602_E = 1;	
	sleepMS(5);
	LCD1602_E = 0;
}

void LcdWriteData(uchar dat)			
{
	LCD1602_E = 0;	  
	LCD1602_RS = 1;	  
	LCD1602_RW = 0;	  

	LCD1602_DATAPINS = dat;	
	sleepMS(1);

	LCD1602_E = 1;	 
	sleepMS(5);
	LCD1602_E = 0;

	LCD1602_DATAPINS = dat << 4; 
	sleepMS(1);

	LCD1602_E = 1;	  
	sleepMS(5);
	LCD1602_E = 0;
}

void LcdInit()						  
{
	LcdWriteCom(0x32);	 
	LcdWriteCom(0x28);	
	LcdWriteCom(0x0c);  
	LcdWriteCom(0x06);  
	LcdWriteCom(0x01);  
	LcdWriteCom(0x80);  
	ALOGI("lcd18b20 module initd");
}

#endif

#else
	
void LcdWriteCom(u8 com) {
	ALOGW("please load lcd1602 module driver, set conf.c file to load it");
}	
void LcdWriteData(u8 dat) {
	ALOGW("please load lcd1602 module driver, set conf.c file to load it");
}
void LcdInit() {
	ALOGW("please load lcd1602 module driver, set conf.c file to load it");
}

#endif
