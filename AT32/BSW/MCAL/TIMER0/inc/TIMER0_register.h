/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  TIMER0                  *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_


#define TIMER0_TCNT0_Reg  *((volatile uint8*)0x52)


#define TIMER0_OCR0_Reg   *((volatile uint8*)0x5C)


#define TIMER0_TCCR0_Reg   ((volatile TCCR0 *)0x53)

#define TIMER0_TIMSK_Reg   ((volatile Timer0_TIMSK *)0x59)

#define TIMER0_TIFR_Reg   ((volatile Timer0_TIFR *)0x58)

#define TIMER0_SFIOR_Reg   ((volatile Timer0_SFIOR *)0x50)

#endif /* TIMER0_REGISTER_H_ */
