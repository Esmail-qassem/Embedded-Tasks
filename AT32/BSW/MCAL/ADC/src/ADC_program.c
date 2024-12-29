/***********************************************************************/
/***********************************************************************/
/*****************       Aathur:Esmail Qassem          *****************/
/*****************       Layer:MCAL                    *****************/
/*****************       SWC:  ADC                     *****************/
/*****************       version:1.00                  *****************/
/***********************************************************************/
/***********************************************************************/
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"
#include "../inc/ADC_interface.h"
#include "../inc/ADC_register.h"
#include "../inc/ADC_config.h"
#include "../inc/ADC_private.h"

void ADC_voidInit(void) {
	/*PRE-SCALER SELECTION*/
	ADCSRA_Reg->ADPS = DESIRED_PRE_SCALER;

	/*Choosing the voltage reference*/
	ADMUX_Reg->REFS = DESIRED_VOLTAGE_REF;
	/*choose the Resolution*/
	ADMUX_Reg->ADLAR = RIGHT;

#ifdef AUTO_TREGERED

	ADCSRA_Reg->ADATE=ENABLE;

	ADC_SFIOR_Reg->ADTS  =  AUTO_TRIGER_SOURCE;

#endif
	/*ENABLE THE ADC*/
	ADCSRA_Reg->ADEN = ENABLE;

}
ADC_Status_t ADC_uint8StartConversionSynchronus(Channel_t Copy_uint8channel,uint16* copy_uint16PuReading) {
	ADC_Status_t Local_ErrorStatus = ADC_OK;
	uint32 Local_uint32Counter = 0;
	if (NULL == copy_uint16PuReading) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else if ((Copy_uint8channel > ADC_CHANNEL7)|| (Copy_uint8channel < ADC_CHANNEL0)) {
		Local_ErrorStatus = ADC_ChannelErr;
	} else {
		/*Select the Channel*/
		ADMUX_Reg->MUX = Copy_uint8channel;
#ifndef AUTO_TREGERED
		/*Start Conversion*/
		ADCSRA_Reg->ADSC = ENABLE;
#endif
		/*Polling until the conversion is complete OR TIME OUT*/
		while ((ADCSRA_Reg->ADIF) != 1 && Local_uint32Counter < TIME_OUT) {
			Local_uint32Counter++;
		}
		if (Local_uint32Counter == TIME_OUT) {
			Local_ErrorStatus = ADC_TIME_OUTErr;
		} else {
			/*Clear the valg*/
			ADCSRA_Reg->ADIF = ENABLE;

#if     DATA_SIZE == BIT_10_MACRO
			*copy_uint16PuReading=ADC;
#elif  DATA_SIZE == BIT_8_MACRO
			*copy_uint16PuReading = ADC >> 2;
#endif

		}

	}

	return Local_ErrorStatus;
}

ADC_Status_t ADC_uint8StartConversionASynchronus(Channel_t Copy_uint8channel,void (*copy_PvNotifacation)(void), uint16* copy_uint16PuReading) {
	ADC_Status_t Local_ErrorStatus = ADC_OK;
	if (NULL == copy_uint16PuReading) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else if ((Copy_uint8channel > ADC_CHANNEL7)|| (Copy_uint8channel < ADC_CHANNEL0)) {
		Local_ErrorStatus = ADC_ChannelErr;
	} else if (NULL == copy_PvNotifacation) {
		Local_ErrorStatus = ADC_POINTER_Err;
	} else {

		Global_PvNotifacation = copy_PvNotifacation;

		/*Assign Address of Receive Variable in Global Pointer to be used in ISR*/
		Global_uint16PuReading = copy_uint16PuReading;


		/* ADC Conversion Complete Interrupt Enable*/
		ADCSRA_Reg->ADIE = ENABLE;
#ifndef AUTO_TREGERED
		/*ADC Start Conversion*/
		ADCSRA_Reg->ADSC = ENABLE;
#endif
	}
	return Local_ErrorStatus;
}



void __vector_16(void) {
#if     DATA_SIZE == BIT_10_MACRO
	*Global_uint16PuReading=ADC;
#elif  DATA_SIZE == BIT_8_MACRO
	*Global_uint16PuReading = ADC >> 2;
#endif

	/*Execute Notification Function*/
	Global_PvNotifacation();
}

