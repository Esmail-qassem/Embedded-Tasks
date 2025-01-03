/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:DIO_REGISTER              *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#define PORTA     *((volatile uint8*)0x3B)
#define PINA     *((volatile uint8*)0x39)
#define DDRA     *((volatile uint8*)0x3A)



#define PORTB     *((volatile uint8*)0x38)
#define DDRB     *((volatile uint8*)0x37)
#define PINB     *((volatile uint8*)0x36)



#define PORTC     *((volatile uint8*)0x35)
#define DDRC     *((volatile uint8*)0x34)
#define PINC     *((volatile uint8*)0x33)



#define PORTD     *((volatile uint8*)0x32)
#define DDRD     *((volatile uint8*)0x31)
#define PIND     *((volatile uint8*)0x30)

#endif /* DIO_REGISTER_H_ */
