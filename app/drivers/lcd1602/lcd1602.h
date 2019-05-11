#ifndef __LCD1602_H_
#define __LCD1602_H_

#include <reg51.h>
#include "../../utils/cstddef.h"

void LcdWriteCom(u8 com);	
void LcdWriteData(u8 dat);	
void LcdInit();	

#endif