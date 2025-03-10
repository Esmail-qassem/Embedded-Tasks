#include "../inc/TWI_interface.h"
void TWI_voidMasterInit(void)
{
/*SCL CLOCK*/
TWBR_Reg =255;
TWSR_Reg->TWPSX=PRESCALER_BY_1;
/*ENABLE*/
TWCR_Reg->TWEN=1;
}

void TWI_voidStartCondition(void)
{
	/*TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT)*/
    TWCR_Reg->TWCR_8bit_Reg  = 164;
    // Wait for TWINT to be set (operation complete)
    while (TWCR_Reg->TWINT == 0);
}


void TWI_voidStopCondition(void)
{
	/*TWCR=(1<<TWSTO)|(1<<TWEN)|(1<<TWINT)*/
	TWCR_Reg->TWCR_8bit_Reg=148;
}
void TWI_voidSendData(uint8 Copy_u8Data)
{
	TWDR_Reg=Copy_u8Data;
	/*TWCR=(1<<TWEN)|(1<<TWINT)*/
    TWCR_Reg->TWCR_8bit_Reg  = 132;

while(TWCR_Reg->TWINT==0);
}
uint8 TWI_u8ReceiveData(void)
{
	/*TWCR=(1<<TWEN)|(1<<TWINT)*/
	TWCR_Reg->TWCR_8bit_Reg  = 132;
	while(TWCR_Reg->TWINT==0);
return TWDR_Reg;
}








