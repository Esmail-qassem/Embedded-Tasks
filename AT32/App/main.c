#include "TrafficLights/inc/TrafficLightsControl_interface.h"
#include  "Fixed_Point/inc/FixedPoint_interface.h"
#include  "EEPROM/inc/EEPROM_interface.h"
#include  <util/delay.h>

int main()
{
	TrafficLightInit();
	while(1)
	{
		//TrafficLightMainFunction();
	}
}


