#ifndef __STRATEGY_H_
#define __STRATEGY_H_

#include <reg51.h>
#include "utils/log.h"
#include "utils/cstddef.h"
#include "utils/time.h"
#include "conf.c"

void lcd1602display(char *class_name, s32 temp)
{
	static s32 cflag = 1;
	u8 i, datas[] = {0, 0, 0, 0, 0};
	float tp;  
	
	if (cflag) {
		ALOGI(class_name);
		cflag = 0;
	}
	
	if(temp< 0)				
  	{	 			 		
		LcdWriteCom(0x80);
		LcdWriteData('-'); 
		temp = temp-1;
		temp = ~temp;
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	
  	}
 	else
  	{			
		LcdWriteCom(0x80);
		LcdWriteData('+'); 					 
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
	datas[0] = temp / 10000;
	datas[1] = temp % 10000 / 1000;
	datas[2] = temp % 1000 / 100;
	datas[3] = temp % 100 / 10;
	datas[4] = temp % 10;

	LcdWriteCom(0x82);
	LcdWriteData('0'+datas[0]);
	
	LcdWriteCom(0x83);
	LcdWriteData('0'+datas[1]);

	LcdWriteCom(0x84);
	LcdWriteData('0'+datas[2]);

	LcdWriteCom(0x85);
	LcdWriteData('.'); 
 
	LcdWriteCom(0x86);
	LcdWriteData('0'+datas[3]);

	LcdWriteCom(0x87);
	LcdWriteData('0'+datas[4]);
}

void usartdisplay(char *class_name, s32 temp)
{
	static s32 cflag = 1;
	u8 i, datas[] = {0, 0, 0, 0, 0};
	float tp;  
	
	if (cflag) {
		SBUF = class_name;
		while(!TI);			         
		TI = 0;
		cflag = 0;
	}
	
	if(temp< 0)				
  	{	 
		SBUF = '-';
		while(!TI);			         
		TI = 0;						 		
		
		temp = temp-1;
		temp = ~temp;
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	
  	}
 	else
  	{			
		SBUF = '+';
		while(!TI);			        
		TI = 0;						 
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
	datas[0] = temp / 10000;
	datas[1] = temp % 10000 / 1000;
	datas[2] = temp % 1000 / 100;
	datas[3] = temp % 100 / 10;
	datas[4] = temp % 10;

	SBUF = '0'+datas[0];
	while (!TI);			         
	TI = 0;
	
	SBUF = '0'+datas[1];
	while (!TI);			        
	TI = 0;

	SBUF = '0'+datas[2];
	while (!TI);			         
	TI = 0;

	SBUF = '.';
	while (!TI);			        
	TI = 0;
 
	SBUF = '0'+datas[3];
	while (!TI);			         
	TI = 0;

	SBUF = '0'+datas[4];
	while (!TI);			         
	TI = 0;
	for(i=0; i<6; i++)
	{
	 	SBUF = CNCHAR[i];
		while (!TI);			         
		TI = 0;
	}
}

#endif