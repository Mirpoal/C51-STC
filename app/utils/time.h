#ifndef __TIME_H_
#define __TIME_H_

#if 12MHZ
void sleepMS(s32 c)
{
	u8 a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
}
#endif

#if 11MHZ
void sleepMS(s32 c)
{
	u8 a,b;
	for (; c>0; c--)
	{
		 for (b=110;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
}
#endif

#endif
