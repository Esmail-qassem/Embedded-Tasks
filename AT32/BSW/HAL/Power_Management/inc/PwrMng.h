#ifndef BSW_HAL_POWER_MANAGEMENT_INC_PWRMNG_H_
#define BSW_HAL_POWER_MANAGEMENT_INC_PWRMNG_H_

#include "STD_TYPES.h"
typedef struct
{
	uint8 : 4; //reserved
	uint8 SMx :3;
	uint8 SE  :1;

}MCUCR_Struct;

typedef enum
{
	IDLE ,
	ADC_NOISE_REDUCTION,
	Power_Down,
	Power_Save,
	Standby=6,
	Extended_Standby
}PwrModes;


#define SlEEP_MODE Power_Down


//#define MCUCR_PwrMg  ((volatile MCUCR_Struct*)0x55)
#define MCUCR_PwrMg  *((volatile uint8*)0x55)

void Sleep_Mode(void);

#endif /* BSW_HAL_POWER_MANAGEMENT_INC_PWRMNG_H_ */
