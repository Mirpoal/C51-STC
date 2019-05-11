#ifndef __SYSTEMDEF_H_
#define __SYSTEMDEF_H_

#include <string.h>
#include "utils/cstddef.h"

// LCD1602 class
typedef struct Ds18b20Class {
	const char* class_name;
	
	s32 (*readtemp)();
	
}Ds18b20Class;


// LCD1602 class
typedef struct LCD1602Class {
	const char* class_name;
	
	void (*lcdInit)();
	
	// write command to lcd1602
	void (*writeCommand)(u8 com);
	
	// write data to lcd1602
	void (*writeData)(u8 data);
	
	Ds18b20Class collection;
	
	// display value
	void (*display)(const char *class_name, s32 temp);
}LCD1602Class;

typedef struct UsartClass {
	const char* class_name;
	
	void (*usartConfiguration)(u32 baud);
	
	Ds18b20Class collection;
	
	// display value
	void (*display)(const char *class_name, s32 temp);
}UsartClass;

#endif