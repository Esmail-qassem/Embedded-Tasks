/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/TIMER2_config.h"
#include "../inc/TIMER2_interface.h"
#include "../inc/TIMER2_private.h"
#include "../inc/TIMER2_register.h"

void TIMER2_DutyCycle(uint8 Copy_uint8Duty)
{
	uint16 Local_VCalue=0;
	Local_VCalue=Copy_uint8Duty*256;
	Local_VCalue/=100;
	OCR2_Reg=Local_VCalue;
}


void TIMER2_Delay(uint16 Copy_uint16Delay)
{
	uint16 Counter=0;


	while(Counter<Copy_uint16Delay)
	{
	while(TIFR_Reg->OCF2 == 0);
	TIFR_Reg->OCF2 =1;
	Counter++;


	}

}
void TIMER2_voidInit(void)
{
	TCCR2_Reg->CS2x= CLCK_SELECTION;

#if TIMER_MODE==NORMAL_MODE
TCCR2_Reg->WGM20=0b0;
TCCR2_Reg->WGM21=0b0;
#elif TIMER_MODE==PWM_PHASE_CORRECT_MODE
TCCR2_Reg->WGM20=ENABLE;
TCCR2_Reg->WGM21=DISABLE;
TCCR2_Reg->COM2x=CORRECT_PWM_OUTPUT_MODE;


#elif TIMER_MODE==CTC_MODE
TCCR2_Reg->WGM20=DISABLE;
TCCR2_Reg->WGM21=ENABLE;
TCCR2_Reg->COM2x=CTC_OUTPUT_MODE;

#elif TIMER_MODE==FAST_PWM_MODE
TCCR2_Reg->WGM20=ENABLE;
TCCR2_Reg->WGM21=ENABLE;
TCCR2_Reg->COM2x=FAST_PWM_OUTPUT_MODE;
#endif



#ifdef OVERFLOW_ISR_ENABLE
TIMSK_Reg->TOIE2=ENABLE;
#endif

#ifdef COMPARE_MATCH_ISR_ENABLE
TIMSK_Reg->OCIE2=ENABLE;
#endif


}


void TIMER2_voiSetPreLoadValue(uint8 Copy_uint8Value)
{
	TCNT2_Reg=Copy_uint8Value;
}


void TIMER2_voiSetCompareMatchValue(uint8 Copy_uint8Value)
{
	OCR2_Reg=Copy_uint8Value;
}

Status_t Timer2_Timer2OVFCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER2_OK;
	if(NULL == Copy_pvFunc )
	{
		Local_ErrorState =TIMER2_POINTER_Err;
	}
	else
	{
		Global_PvOverFlow = Copy_pvFunc;
	}

	return Local_ErrorState;
}

Status_t Timer2_Timer2CTCCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER2_OK;
	if(NULL == Copy_pvFunc )
		{
			Local_ErrorState =TIMER2_POINTER_Err;
		}
		else
		{
			Global_PvCompareMatch=Copy_pvFunc;
		}

	return Local_ErrorState;
}




/*TIMER0 COMPARE MATCH*/
void __vector_4(void){

	Global_PvCompareMatch();
}

/*TIMER0 OVERFLOW*/
void __vector_5(void){

	Global_PvOverFlow();
}

