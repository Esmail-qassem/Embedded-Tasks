
/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:UART_PROGRAM              *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "../inc/UART_interface.h"
#include "../inc/UART_private.h"
#include "../inc/UART_register.h"

void UART_voidInit(void)
{
	UCSRC= (1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);
/*BAUD RATE*/
UBRRL=51;
/*ENABLE TRANSMITE AND RECEIVE*/
SET_BIT(UCSRB,UCSRB_RXEN);
SET_BIT(UCSRB,UCSRB_TXEN);
}

void UART_voidTransmit(uint8 Copy_u8Data)
{
while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

UDR=Copy_u8Data;
}

uint8 UART_u8Receive(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

return UDR;
}


void UART_voidSendString(uint8* Copy_pvString)
{

	uint8 counter=0;

while(Copy_pvString[counter]!='\0')
{
	UART_voidTransmit(Copy_pvString[counter]);
	counter++;
}

}

void UART_voidSendNumber(sint32 Copy_s32Number)
{
	if(Copy_s32Number<0)
	{
		UART_voidTransmit('-');
		Copy_s32Number= -Copy_s32Number;
	}
	if(Copy_s32Number==0)
	{
		UART_voidTransmit('0');
		return;
	}
uint8 NUM[10];
uint8 Local_u8Counter=0;
while(Copy_s32Number>0)
{
	NUM[Local_u8Counter++]=(Copy_s32Number%10)+'0';
	Copy_s32Number/=10;
}
/*reverse*/
for(uint8 i=Local_u8Counter;i>0;i--)
{
	UART_voidTransmit(NUM[i-1]);
}
}




