
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI/inc/TWI_interface.h"

void EEPROM_Init(void);
void EEPROM_voidSendData(uint16 Copy_u16Address,uint8 Copy_u8Data);


uint8 EEPROM_voidReceiveData(uint16 Copy_u16Address);



#endif /* EEPROM_INTERFACE_H_ */
