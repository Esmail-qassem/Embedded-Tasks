#include "Power_Management/inc/PwrMng.h"

void Sleep_Mode(void)
{
//	MCUCR_PwrMg->SE=1;
//	MCUCR_PwrMg->SE=SlEEP_MODE;

	MCUCR_PwrMg=160;
}

