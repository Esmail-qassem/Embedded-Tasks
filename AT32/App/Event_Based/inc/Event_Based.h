#ifndef APP_EVENT_BASED_INC_EVENT_BASED_H_
#define APP_EVENT_BASED_INC_EVENT_BASED_H_
#include "STD_TYPES.h"
#include "Queue/inc/Queue.h"
#include "PORT/inc/PORT_interface.h"
#include "TIMER0/inc/TIMER0_interface.h"
#include "GIE/inc/GIE_interface.h"
#include "LCD_OLED/inc/OLED.h"
#include "DIO/inc/DIO_interface.h"
#include <util/atomic.h>

enum Event
{
	TIMER_EVENT,
	EXT_EVENT,
	EVENT_COUNT
};
void EB_voidInit(void);
void EB_VoidRunnable(void);

#endif
