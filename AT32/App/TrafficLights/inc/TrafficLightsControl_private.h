/*
 * TrafficLightsControl_private.h
 *
 *  Created on: Dec 29, 2024
 *      Author: s_a_a
 */

#ifndef APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_
#define APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_

typedef enum
{
	Green=5,
	Yellow,
	Red,
	Reset
}Traffic_State;

#define GREEN_DURATION  5
#define YELLOW_DURATION 5
#define RED_DURATION    5

static void HandleGreenState(void)
{
	 DIO_SetPinVal(DIO_PORTC, DIO_Pin0, DIO_LOW);
    DIO_SetPinVal(DIO_PORTC, DIO_Pin2, DIO_HIGH);
}
static void HandleRedState(void)
{
	DIO_SetPinVal(DIO_PORTC, DIO_Pin2, DIO_LOW);
	DIO_SetPinVal(DIO_PORTC, DIO_Pin1, DIO_LOW);
	DIO_SetPinVal(DIO_PORTC, DIO_Pin0, DIO_HIGH);
}
static void HandleyellowState(void)
{
	DIO_SetPinVal(DIO_PORTC, DIO_Pin2, DIO_LOW);
	DIO_SetPinVal(DIO_PORTC, DIO_Pin0, DIO_LOW);
    DIO_SetPinVal(DIO_PORTC, DIO_Pin1, DIO_HIGH);
}
#endif /* APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_ */
