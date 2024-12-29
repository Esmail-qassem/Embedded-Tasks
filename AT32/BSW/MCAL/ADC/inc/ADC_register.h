/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:ADC_REGISTER              *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX_Reg         ((volatile ADMUX*)0x27)

#define ADCSRA_Reg        ((volatile ADCSRA *)0x26)

#define ADC              *((volatile uint16*)0x24)
#define ADCL              *((volatile uint8*)0x24)
#define ADCH              *((volatile uint8*)0x25)
#define ADC_SFIOR_Reg         ((volatile  ADC_SFIOR *)0x50)

//#define  ADIF_MACRO 4

#endif /* ADC_REGISTER_H_ */
