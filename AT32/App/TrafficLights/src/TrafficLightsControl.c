#include "TrafficLights/inc/TrafficLightsControl_interface.h"
#include "TrafficLights/inc/TrafficLightsControl_config.h"
#include "TrafficLights/inc/TrafficLightsControl_private.h"
#include "../../../Services/Stack/Stack.h"

// Traffic light control stack
Stack TrafficStack;
int timer_counter = 0;          // Timer counter to track elapsed seconds
StackEntry Local_Variable;     // Current state function
int last_handled_time = -1;    // Tracks the last time the state was handled

/* ISR Function */
void TimerISR(void)
{
    timer_counter++; // Increment timer counter every second
}

/* Traffic Light Initialization */
void TrafficLightInit(void)
{
    /* System initialization */
    PORT_voidInit();
    CLCD_voidInit();
    GIE_Enable();
    TIMER1_voidInit();
    TIMER1_voidSetChannelACompMatch(31250); // Configure Timer1 for 1-second intervals
    TIMER1_CTCASetCallBck(&TimerISR);

    /* Stack initialization */
    Stack_Creation(&TrafficStack);
    Stack_Push(&TrafficStack, HandleGreenState); // Start with the green state
}

/* Traffic Light State Handler */
void Traffic_Handler(void)
{
    if (timer_counter == GREEN_DURATION && last_handled_time != GREEN_DURATION)
    {
        Stack_Push(&TrafficStack, HandleyellowState);
        last_handled_time = GREEN_DURATION; // Mark the transition as handled
    }
    else if (timer_counter == GREEN_DURATION + YELLOW_DURATION && last_handled_time != GREEN_DURATION + YELLOW_DURATION)
    {
        Stack_Push(&TrafficStack, HandleRedState);
        last_handled_time = GREEN_DURATION + YELLOW_DURATION; // Mark the transition as handled
    }
    else if (timer_counter == GREEN_DURATION + YELLOW_DURATION + RED_DURATION && last_handled_time != GREEN_DURATION + YELLOW_DURATION + RED_DURATION)
    {
        Stack_Pop(&TrafficStack, &Local_Variable); // Remove red state
        Stack_Pop(&TrafficStack, &Local_Variable); // Remove yellow state
        timer_counter = 0; // Reset timer
        last_handled_time = -1; // Reset last handled time
        CLCD_voidSendCommand(1); // Clear display
    }
}

/* Main Traffic Light Control Function */
void TrafficLightMainFunction(void)
{
    Local_Variable = TrafficStack.top->entry; // Get the current state function
    Local_Variable(); // Execute the state function

    Traffic_Handler(); // Handle state transitions

    /* Display timer and stack size */
    CLCD_voidGoToXY(0, 0);
    CLCD_voidWriteNumber(timer_counter);
    CLCD_voidGoToXY(1, 0);
    CLCD_voidWriteNumber(TrafficStack.Size);
}
