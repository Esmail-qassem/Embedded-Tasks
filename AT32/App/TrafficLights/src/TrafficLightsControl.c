#include "../inc/TrafficLightsControl_interface.h"
#include "../inc/TrafficLightsControl_config.h"
#include "../inc/TrafficLightsControl_private.h"
#include "../../../Services/Stack/Stack.h"

Stack TrafficStack;
int static timer_counter=0;
StackEnery Local_Variable=Green;

void test(void) {
	timer_counter++;
	if(timer_counter==1)
		Stack_Pop(&TrafficStack,&Local_Variable);

	switch(Local_Variable)
	{
	case Green :
	{
		if(timer_counter>=GREEN_DURATION)
		{
			HandleyellowState();
			timer_counter=0;
		}
		break;

	}
	case Yellow:
	{
		if(timer_counter>=YELLOW_DURATION)
		{
			HandleRedState();
			timer_counter=0;
		}
		break;

	}
	case Red :
	{	if(timer_counter>=RED_DURATION)
			{
	            Stack_Push(&TrafficStack,Red);
	            Stack_Push(&TrafficStack,Yellow);
	            Stack_Push(&TrafficStack,Green);
				timer_counter=0;
				HandleGreenState();
	}
	break;

	}
	}



}

void TrafficLightInit(void)
{
	PORT_voidInit();
    CLCD_voidInit();
    GIE_Enable();
    TIMER1_voidInit();
	TIMER1_voidSetChannelACompMatch(31250);
	TIMER1_CTCASetCallBck(&test);
	/*stack initialization*/
    Stack_Creation(&TrafficStack);
    Stack_Push(&TrafficStack,Red);
    Stack_Push(&TrafficStack,Yellow);
    Stack_Push(&TrafficStack,Green);

    HandleGreenState();

}

void TrafficLightMainFunction(void)
{
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Traffic light");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Timer: ");
	CLCD_voidWriteNumber(timer_counter);
    if (TrafficStack.top != NULL) {
        CLCD_voidGoToXY(1, 8);
        CLCD_voidSendString(" Size: ");
        CLCD_voidWriteNumber(TrafficStack.Size);
    }

}
