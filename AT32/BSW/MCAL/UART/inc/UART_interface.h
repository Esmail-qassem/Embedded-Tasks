
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);

void UART_voidTransmit(uint8 Copy_u8Data);

uint8 UART_u8Receive(void);
void UART_voidSendString(uint8* Copy_pvString);
void UART_voidSendNumber(sint32 Copy_s32Number);

#endif /* UART_INTERFACE_H_ */
