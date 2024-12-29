/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:EXTERNAL INTERRUPT        *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define INT0  1
#define INT1  2
#define INT2  3


#define EXTI_LOW_LEVEL   0
#define EXTI_ANY_CHANGE  1
#define EXTI_FALLING     2
#define EXTI_RISING      3




void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);


uint8 EXTI_uint8IntSetSenseControl(uint8 Copy_uint8IntNumber,uint8 Copy_uint8Sense);

uint8 EXTI_uint8IntEnable(uint8 Copy_uint8IntNumber);

uint8 EXTI_uint8IntDisable(uint8 Copy_uint8IntNumber);

uint8 EXTI_uint8Int0SetCallBack(void (*Copy_pvInt0Func)(void));
uint8 EXTI_uint8Int1SetCallBack(void (*Copy_pvInt1Func)(void));
uint8 EXTI_uint8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif /* EXTI_INTERFACE_H_ */
