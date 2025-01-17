#include "TrafficLights/inc/TrafficLightsControl_interface.h"
#include  "Fixed_Point/inc/FixedPoint_interface.h"


int main()
{
	TrafficLightInit();
	fixed16_t Test;

	while(1)
	{

//		Test= Fixed_Sub(11,10.5);
		CLCD_voidGoToXY(0,0);
		CLCD_voidWriteNumber(Test);


		//TrafficLightMainFunction();
	}
}


