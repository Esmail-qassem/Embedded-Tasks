#include "TrafficLights/inc/TrafficLightsControl_interface.h"


int main()
{
	TrafficLightInit();


	while(1)
	{
		TrafficLightMainFunction();
	}
}


