/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

typedef enum
{
	TIMER_OK,
	TIMER_POINTER_Err,
}Status_t;

void TIMER0_voidInit(void);

/*Over flow value or preLoad value*/
/*2^n*(1-0.y)   in which n: the resolution */
void TIMER0_voiSetPreLoadValue(uint8 Copy_uint8Value);
void TIMER0_voiSetCompareMatchValue(uint8 Copy_uint8Value);

void TIMER0_Delay(uint16 Copy_uint16Delay);
void TIMER0_DutyCycle(uint8 Copy_uint8Duty);


Status_t Timer0_Timer0OVFCallBackFunc(void (*Copy_pvFunc)(void));
Status_t Timer0_Timer0CTCCallBackFunc(void (*Copy_pvFunc)(void));

#endif /* TIMER0_INTERFACE_H_ */
