/*
 * TrafficLightsControl_private.h
 *
 *  Created on: Dec 29, 2024
 *      Author: s_a_a
 */

#ifndef APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_
#define APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_


#define GREEN_DURATION  5
#define YELLOW_DURATION 5
#define RED_DURATION    5

static void HandleGreenState(void)
{
	 DIO_SetPinVal(Traffic_PORT, Traffic_LED_RED, DIO_LOW);
    DIO_SetPinVal(Traffic_PORT, Traffic_LED_GREEN, DIO_HIGH);
}
static void HandleRedState(void)
{
	DIO_SetPinVal(Traffic_PORT, Traffic_LED_GREEN, DIO_LOW);
	DIO_SetPinVal(Traffic_PORT, Traffic_LED_YELLOW, DIO_LOW);
	DIO_SetPinVal(Traffic_PORT, Traffic_LED_RED, DIO_HIGH);
}
static void HandleyellowState(void)
{
	DIO_SetPinVal(Traffic_PORT, Traffic_LED_GREEN, DIO_LOW);
	DIO_SetPinVal(Traffic_PORT, Traffic_LED_RED, DIO_LOW);
    DIO_SetPinVal(Traffic_PORT, Traffic_LED_YELLOW, DIO_HIGH);
}
#endif /* APP_TRAFFICLIGHTS_INC_TRAFFICLIGHTSCONTROL_PRIVATE_H_ */
