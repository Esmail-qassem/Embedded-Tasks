

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UCSRA     *((volatile uint8*)0x2B)
#define UCSRB     *((volatile uint8*)0x2A)

#define UDR           *((volatile uint8*)0X2C)
#define UBRRL           *((volatile uint8*)0X29)

#define UCSRC        *((volatile uint8*)0X29)  /*UBRRH*/


#endif /* UART_REGISTER_H_ */
