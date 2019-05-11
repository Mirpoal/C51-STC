/**
*
* this file is the configuration of your system, profile by yourself
*/
#include <reg51.h>

/******************************************************************************/
/***        lcd1602 module setting           ***/
// if your system contain lcd1602 module,enable it
#define LOAD_LCD1602_MODULE 0

// setting the number of transfer, LCD1602_4PINS use for 4 bit, LCD1602_4PINS use for 8 bit
#define LCD1602_4PINS 1
#define LCD1602_8PINS 0

// LCD1602 DATA Pin Define
#define LCD1602_DATAPINS P0

#ifdefine LCD1602_DATAPINS
	// if you enable lcd1602 module, next code is compiled
	#define LCD1602_E P2^7
	#define LCD1602_RW P2^5
	#define LCD1602_RSP 2^6
#endif

/***        end of lcd1602 module setting    ***/


/******************************************************************************/
/***        Ds18b20 module setting           ***/
// if your system contain lcd1602 module,enable it
#define LOAD_DS18B20_MODULE 1

// define the Data Pin of Ds18b20 module
#define DSPORT P3^7

/***        end of Ds18b20 module setting    ***/


/******************************************************************************/
/***        GPIO control module setting           ***/
#define NORMAL_TEM_CONT_PIN P1^5
#define HIGH_TEM_CONT_PIN P1^6
#define LOW_TEM_CONT_PIN P1^7

#define SPARKER_PIN P1^3

/***        end of GPIO control module setting    ***/


/******************************************************************************/
// system cls frequent, 11MHZ : 11.0596  ,  12MHZ  : 12
#define 11MHZ 0
#define 12MHZ 1
