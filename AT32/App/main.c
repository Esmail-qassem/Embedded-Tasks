#include "TrafficLights/inc/TrafficLightsControl_interface.h"
#include  "Fixed_Point/inc/FixedPoint_interface.h"


int main()
{
	TrafficLightInit();
	float Test;

	while(1)
	{

		Test= Fixed_ToFloat(137625);

		CLCD_voidGoToXY(0,0);
		CLCD_voidWriteNumber(Test);

		//TrafficLightMainFunction();
	}
}


