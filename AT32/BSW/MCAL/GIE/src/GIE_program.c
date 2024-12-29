/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:GIE                       *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/GIE_interface.h"
#include "../inc/GIE_register.h"

void GIE_Enable(void)
{
SET_BIT(SREG,SREG_I);

}
void GIE_Disable(void)
{
	CLEAR_BIT(SREG,SREG_I);
}

