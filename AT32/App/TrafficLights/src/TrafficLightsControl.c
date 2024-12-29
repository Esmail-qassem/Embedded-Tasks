#include "../inc/TrafficLightsControl_interface.h"
#include "../inc/TrafficLightsControl_config.h"
#include "../inc/TrafficLightsControl_private.h"

int global=0;
void A7A (void)
{
	global++;
}

void TrafficLightInit(void)
{
	PORT_voidInit();
    CLCD_voidInit();
    GIE_Enable();
    TIMER1_voidInit();


}
void TrafficLightMainFunction(void)
{

	TIMER1_voidSetChannelACompMatch(31250);
		TIMER1_CTCASetCallBck(&A7A);

		while(1)
		{
			CLCD_voidGoToXY(0,0);
			CLCD_voidWriteNumber(global);
		}


}
