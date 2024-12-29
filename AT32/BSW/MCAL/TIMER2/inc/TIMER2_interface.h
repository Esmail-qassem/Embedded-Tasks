/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC: TIMER2                   *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

typedef enum
{
	TIMER2_OK,
	TIMER2_POINTER_Err,
}Status_t;

void TIMER2_voidInit(void);

/*Over flow value or preLoad value*/
/*2^n*(1-0.y)   in which n: the resolution */
void TIMER2_voiSetPreLoadValue(uint8 Copy_uint8Value);
void TIMER2_voiSetCompareMatchValue(uint8 Copy_uint8Value);

void TIMER2_Delay(uint16 Copy_uint16Delay);
void TIMER2_DutyCycle(uint8 Copy_uint8Duty);


Status_t Timer2_Timer2OVFCallBackFunc(void (*Copy_pvFunc)(void));
Status_t Timer2_Timer2CTCCallBackFunc(void (*Copy_pvFunc)(void));

#endif /* TIMER2_INTERFACE_H_ */
