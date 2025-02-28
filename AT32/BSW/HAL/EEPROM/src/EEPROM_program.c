#include "EEPROM/inc/EEPROM_interface.h"


void static Test_Code(void)
{
static int i=1;
EEPROM_voidSendData(0x111,i++);
	//TIMER0_Delay(50);
uint8 x=EEPROM_voidReceiveData(0x111);

}

void EEPROM_Init(void)
{
	TWI_voidMasterInit();
}

void EEPROM_voidSendData(uint16 Copy_u16Address,uint8 Copy_u8Data)
{
	//int static a=0;
	/*1010(A2)(B1)(B0)(W/R)*/
	uint8 SLV_W=0b10100000;

	TWI_voidStartCondition();
//	CLCD_voidGoToXY(0,0);
//	CLCD_voidWriteNumber(++a);

	/*BLOCK SELECTION WITH WRITE*/
	TWI_voidSendData(SLV_W);

	/*BYTE SELECTION IN THE DESIRED BLOCK*/
	TWI_voidSendData((uint8)Copy_u16Address);

	/*SENDING THE DATA*/
	TWI_voidSendData(Copy_u8Data);
	TWI_voidStopCondition();

}

uint8 EEPROM_voidReceiveData(uint16 Copy_u16Address)
{
	uint8 SLV_W=0b10100000;
	uint8 SLV_R=SLV_W+1;
	TWI_voidStartCondition();

	TWI_voidSendData(SLV_W);
	TWI_voidSendData((uint8)Copy_u16Address);

	TWI_voidStartCondition();
	TWI_voidSendData(SLV_R);

	uint8 Data=TWI_u8ReceiveData();

	TWI_voidStopCondition();
	return Data;

}
