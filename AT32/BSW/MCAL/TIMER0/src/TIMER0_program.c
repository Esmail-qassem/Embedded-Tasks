/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/TIMER0_interface.h"
#include "../inc/TIMER0_private.h"
#include "../inc/TIMER0_register.h"
#include "../inc/TIMER0_config.h"

void TIMER0_DutyCycle(uint8 Copy_uint8Duty)
{
	uint16 Local_VCalue=0;
	Local_VCalue=Copy_uint8Duty*256;
	Local_VCalue/=100;
	TIMER0_OCR0_Reg=Local_VCalue;
}


void TIMER0_Delay(uint16 Copy_uint16Delay)
{
	uint16 Counter=0;


	while(Counter<Copy_uint16Delay)
	{
	while(TIMER0_TIFR_Reg->OCF0 == 0);
	TIMER0_TIFR_Reg->OCF0 =1;
	Counter++;


	}

}
void TIMER0_voidInit(void)
{
	/*clock selection*/
	TIMER0_TCCR0_Reg->CS0x= CLCK_SELECTION;

#if TIMER_MODE==NORMAL_MODE
	TIMER0_TCCR0_Reg->WGM00=0b0;
	TIMER0_TCCR0_Reg->WGM01=0b0;
#elif TIMER_MODE==PWM_PHASE_CORRECT_MODE
	TIMER0_TCCR0_Reg->WGM00=ENABLE;
	TIMER0_TCCR0_Reg->WGM01=DISABLE;
	TIMER0_TCCR0_Reg->COM0=CORRECT_PWM_OUTPUT_MODE;


#elif TIMER_MODE==CTC_MODE
	TIMER0_TCCR0_Reg->WGM00=DISABLE;
	TIMER0_TCCR0_Reg->WGM01=ENABLE;
	TIMER0_TCCR0_Reg->COM0=CTC_OUTPUT_MODE;

#elif TIMER_MODE==FAST_PWM_MODE
	TIMER0_TCCR0_Reg->WGM00=ENABLE;
	TIMER0_TCCR0_Reg->WGM01=ENABLE;
	TIMER0_TCCR0_Reg->COM0=FAST_PWM_OUTPUT_MODE;
#endif



#ifdef OVERFLOW_ISR_ENABLE
	TIMER0_TIMSK_Reg->TOIE0=ENABLE;
#endif

#ifdef COMPARE_MATCH_ISR_ENABLE
	TIMER0_TIMSK_Reg->OCIE0=ENABLE;
#endif


}


void TIMER0_voiSetPreLoadValue(uint8 Copy_uint8Value)
{
	TIMER0_TCNT0_Reg=Copy_uint8Value;
}


void TIMER0_voiSetCompareMatchValue(uint8 Copy_uint8Value)
{
	TIMER0_OCR0_Reg=Copy_uint8Value;
}

Status_t Timer0_Timer0OVFCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER_OK;
	if(NULL == Copy_pvFunc )
	{
		Local_ErrorState =TIMER_POINTER_Err;
	}
	else
	{
		Global_PvOverFlow = Copy_pvFunc;
	}

	return Local_ErrorState;
}

Status_t Timer0_Timer0CTCCallBackFunc(void (*Copy_pvFunc)(void))
{
	Status_t Local_ErrorState= TIMER_OK;
	if(NULL == Copy_pvFunc )
		{
			Local_ErrorState =TIMER_POINTER_Err;
		}
		else
		{
			Global_PvCompareMatch=Copy_pvFunc;
		}

	return Local_ErrorState;
}




/*TIMER0 COMPARE MATCH*/
void __vector_10(void){

	Global_PvCompareMatch();
}

/*TIMER0 OVERFLOW*/
void __vector_11(void){

	Global_PvOverFlow();
}

