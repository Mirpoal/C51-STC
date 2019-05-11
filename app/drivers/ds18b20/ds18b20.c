#include "ds18b20.h"

#include "../../conf.c"
#include "../../utils/time.h"
#include "../../utils/log.h"

#ifndefine DSPORT
#define DSPORT P3^7
#endif

#if LOAD_DS18B20_MODULE

u8 Ds18b20Init()
{
	s32 i;
    EA = 0;
	DSPORT=0;			 
	i=70;	
	while(i--);
	DSPORT=1;			
	i=0;
    EA = 1;
	while(DSPORT)	
	{
		i++;
		if(i>5000) {
			ALOGE("init ds18b20 failed");
			return 0;
		}
	}
	ALOGI("ds18b20 module initd");
	return 1;
}


void Ds18b20WriteByte(u8 dat)
{
	s32 i,j;
    EA = 0;
	for(j=0;j<8;j++)
	{
		DSPORT=0;			
		i++;
		DSPORT=dat&0x01;
		i=6;
		while(i--); 
		DSPORT=1;	
		dat>>=1;
	}
    EA = 1;
}

u8 Ds18b20ReadByte()
{
	u8 byte,bi;
	s32 i,j;
    EA = 0;	
	for(j=8;j>0;j--)
	{
		DSPORT=0;
		i++;
		DSPORT=1;
		i++;
		i++;
		bi=DSPORT;	
		
		byte=(byte>>1)|(bi<<7);						  
		i=4;		
		while(i--);
	}
    EA = 1;				
	return byte;
}

void  Ds18b20ChangTemp()
{
	Ds18b20Init();
	sleepMS(1);
	Ds18b20WriteByte(0xcc);			 
	Ds18b20WriteByte(0x44);	    
	//sleepMS(100);	
   
}

void  Ds18b20ReadTempCom()
{	

	Ds18b20Init();
	sleepMS(1);
	Ds18b20WriteByte(0xcc);	 
	Ds18b20WriteByte(0xbe);	 
}

s32 Ds18b20ReadTemp()
{
	s32 temp=0;
	u8 tmh,tml;
	Ds18b20ChangTemp();			 	
	Ds18b20ReadTempCom();			
	tml=Ds18b20ReadByte();		
	tmh=Ds18b20ReadByte();		
	temp=tmh;
	temp<<=8;
	temp|=tml;
	return temp;
}

#else
	
u8 Ds18b20Init() {
	ALOGW("please load ds18b20 module driver, set conf.c file to load it");
}
s32 Ds18b20ReadTemp() {
	ALOGW("please load ds18b20 module driver, set conf.c file to load it");
}

#endif
