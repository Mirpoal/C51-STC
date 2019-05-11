#include <reg51.h>
#include "conf.c"
#include "system_def.h"
#include "drivers/lcd1602/lcd1602.h"
#include "drivers/usart/usart.h"
#include "drivers/ds18b20/ds18b20.h"
#include "strategy.h"

void main()
{
	Ds18b20Class ds18b20 = {
		.class_name = "ds18b20",
		.readtemp = Ds18b20ReadTemp,
	};
	
	UsartClass usart = {
		.class_name = "usart",
		.usartConfiguration = UsartConfiguration,
		.collection = ds18b20,
		.display = usartdisplay,
	}
	
	// usart configue, baud set 115200bps
	(*usart.usartConfiguration)(115200);
	
	/*
	LCD1602Class lcd1602 = {
		.class_name = "lcd1602",
		.lcdInit = LcdInit,
		.writeCommand = writeCommand,
		.writeData = writeData,
		.collection = ds18b20,
		.display = lcd1602display,
	};
	
	*/
	
	while(1) {
		//(*lcd1602.display)(lcd1602.class_name, (*lcd1602.collection.readtemp));
		(*usart.display)(usart.class_name, (*usart.collection.readtemp));
		sleepMS(1000);
	}
	
}