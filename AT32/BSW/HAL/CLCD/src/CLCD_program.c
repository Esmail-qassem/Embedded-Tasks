/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:HAL                     *****************/
/*****************       SWC:CLCD_PROGRAM              *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/CLCD_interface.h"
#include "../../../MCAL/DIO/inc/DIO_INTERFACE.h"

void delay_ms(uint16 milliseconds) {
    // Assuming 4 cycles per loop iteration for an 8 MHz clock
    const uint16 cycles_per_ms = 100; // Calculated for 1 ms delay
    uint32 total_iterations = milliseconds * cycles_per_ms;

    // Loop for the calculated number of iterations
    for (volatile uint32 i = 0; i < total_iterations; i++) {
        // Empty loop to create the delay
    }
}


void CLCD_voidSendCommand(uint8 copy_uint8Command)
{
	/*Setting RS pin to low*/
DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_LOW);
/*Setting RW pin low for write*/
DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

/*Set command data pins*/
DIO_SetPortVal(CLCD_DATA_PORT,copy_uint8Command);

/*Send Enable pulse*/
DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
delay_ms(2);
DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait more that 30 ms*/
	delay_ms(40);

	/*Function set ,2 lines AND 5*8 size*/
	CLCD_voidSendCommand(0b00111000);
	/*Display on/off control:diplay enable,disable cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*display clear*/
	CLCD_voidSendCommand(0b1);



}


void CLCD_voidSendData(uint8 copy_uint8Data)
{

	/*Setting RS pin to HIGH*/
	DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_HIGH);
	/*Setting RW pin low for write*/
	DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set data pins*/
	DIO_SetPortVal(CLCD_DATA_PORT,copy_uint8Data);

	/*Send Enable pulse*/
	DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_HIGH);
	delay_ms(2);
	DIO_SetPinVal(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_LOW);


}

void CLCD_voidSendString(const uint8* Copy_uint8String)
{
uint8 Local_uint8Counter=0;
while(Copy_uint8String[Local_uint8Counter]!='\0')
{
    CLCD_voidSendData(Copy_uint8String[Local_uint8Counter]);
    Local_uint8Counter++;
}

}


void CLCD_voidGoToXY(uint8 Copy_uint8Xposition,uint8 Copy_uint8Yposition)
{
  uint8 Local_uint8Address;

  if(Copy_uint8Xposition==0)
  {
	  Local_uint8Address=Copy_uint8Yposition;
  }
  else if(Copy_uint8Xposition==1)

  {
	  Local_uint8Address=Copy_uint8Yposition+0x40;
  }

  CLCD_voidSendCommand(Local_uint8Address|(1<<7));
}


void CLCD_voidWriteNumber(float copy_f32Number)
{
    // Handle negative numbers
    if (copy_f32Number < 0)
    {
        CLCD_voidSendData('-');
        copy_f32Number = -copy_f32Number;
    }

    // Separate the integer and fractional parts
    sint32 integerPart = (sint32)copy_f32Number; // Extract the integer part
    float fractionalPart = copy_f32Number - integerPart; // Extract the fractional part

    // Handle the integer part (reusing existing logic)
    if (integerPart == 0)
    {
        CLCD_voidSendData('0');
    }
    else
    {
        uint8 NUM[10];
        uint8 Local_uint8Counter = 0;

        while (integerPart > 0)
        {
            NUM[Local_uint8Counter++] = (integerPart % 10) + '0';
            integerPart /= 10;
        }

        // Reverse and display the integer part
        for (uint8 i = Local_uint8Counter; i > 0; i--)
        {
            CLCD_voidSendData(NUM[i - 1]);
        }
    }

    // Handle the fractional part
    CLCD_voidSendData('.'); // Display the decimal point

    fractionalPart *= 1000; // Scale to display three decimal places
    sint32 fractionalPartAsInt = (sint32)(fractionalPart + 0.5); // Round the fractional part

    if (fractionalPartAsInt == 0)
    {
        // Display trailing zeros if the fractional part is zero
        CLCD_voidSendData('0');
        CLCD_voidSendData('0');
        CLCD_voidSendData('0');
    }
    else
    {
        uint8 FRACT[10];
        uint8 Local_uint8FracCounter = 0;

        while (fractionalPartAsInt > 0)
        {
            FRACT[Local_uint8FracCounter++] = (fractionalPartAsInt % 10) + '0';
            fractionalPartAsInt /= 10;
        }

        // Reverse and display the fractional part
        for (uint8 i = Local_uint8FracCounter; i > 0; i--)
        {
            CLCD_voidSendData(FRACT[i - 1]);
        }
    }
}

void CLCD_voidWriteSpecialChar(uint8* copy_puint8Pattern,uint8 copy_uint8PatternNumber,uint8 copy_uint8Xposition,uint8 copy_uint8Yposition)
{
	uint8 Local_uint8CGRAM_Address=0;
	/*Set the CGRAM address*/
Local_uint8CGRAM_Address=copy_uint8PatternNumber*8;
CLCD_voidSendCommand(Local_uint8CGRAM_Address|(1<<6));

for(uint8 i=0;i<8;i++)
{
	CLCD_voidSendData(copy_puint8Pattern[i]);
}
/*go back to DDRAM to display the Arr*/
 CLCD_voidGoToXY(copy_uint8Xposition,copy_uint8Yposition);

CLCD_voidSendData(copy_uint8PatternNumber);

}


