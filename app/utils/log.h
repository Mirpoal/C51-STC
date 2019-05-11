#ifndef __USART_H_
#define __USART_H_

#include <stdio.h>

// if you want get info log,set true
#define ENABLE_DEBUG 1

#if ENABLE_DEBUG
	#define ALOGV(log) printf("Verbose : %s\r\n",log)
	#define ALOGD(log) printf("Debug : %s\r\n",log)
	#define ALOGI(log) printf("Info : %s\r\n",log)
#endif
	#define ALOGW(log) printf("Warning : %s\r\n",log)
	#define ALOGE(log) printf("Error : %s\r\n",log)

#endif
