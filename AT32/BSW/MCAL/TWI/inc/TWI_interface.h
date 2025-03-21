#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"

typedef union
{
	struct
	{
		uint8 TWIE  :1;  /*Interrupt Enable*/
		uint8       :1;
	    uint8 TWEN  :1;  /*TWI ENABLE BIT*/
	    uint8 TWWC  :1;  /*TWI WRITE COLLISION FLAG*/
	    uint8 TWSTO :1;  /*TWI STOP CODITION BIT*/
	    uint8 TWSTA :1;  /*TWI START CODITION BIT*/
	    uint8 TWEA  :1;  /*TWI Enable Acknowledge Bit*/
	    uint8 TWINT :1;  /*TWI Interrupt Flag*/
	};
	uint8 TWCR_8bit_Reg;


}TWCR;


typedef struct
{
	uint8 TWPSX:2;  /*TWI Prescaler Bits*/
    uint8      :1;
    uint8 TWSX :5;  /*TWI Status bits*/
}TWSR;


typedef struct
{
	uint8 TWGCE:1; /*General Call*/
    uint8 TWAX :7;  /*(Slave) Address Register*/
}TWAR;



enum CLCK_PRE
{
PRESCALER_BY_1 =0b00,
PRESCALER_BY_4 =0b01,
PRESCALER_BY_16 =0b10,
PRESCALER_BY_64 =0b11,

};

enum abilit
{
	Disable,
	ENABLE

};
#define START_ACK                 0x08 /* start has been sent */
#define REP_START_ACK             0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK      0x18 /* Master transmit (slave address + Write request) ACK */
#define SLAVE_ADD_AND_RD_ACK      0x40 /* Master transmit (slave address + Read request) ACK */
#define MSTR_WR_BYTE_ACK          0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK     0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK    0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ     OxA8 /* means that slave address is received with read request*/
#define SLAVE_ADD_RCVD_WR_REQ     0x60 /* means that slave address is received with write request*/
#define SLAVE_DATA_RECEIVED       0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED    OxB8 /* means that the written byte is transmitted */





#define TWBR_Reg            *((volatile uint8*)0x20)
/*CONTROL REGISTER*/
#define TWCR_Reg           ((volatile TWCR*)0X56)
/*STATUS REGISTER*/
#define TWSR_Reg            ((volatile TWSR*)0X21)
/*TWI DATA REGISTER*/
#define TWDR_Reg           *((volatile uint8*)0x23)
/*TWI (Slave) Address Register*/
#define TWAR_Reg           ((volatile TWAR*)0X22)


void TWI_voidMasterInit(void);
void TWI_voidStartCondition(void);
void TWI_voidStopCondition(void);
void TWI_voidSendData(uint8 Copy_u8Data);
uint8 TWI_u8ReceiveData(void);


#endif /* TWI_INTERFACE_H_ */
