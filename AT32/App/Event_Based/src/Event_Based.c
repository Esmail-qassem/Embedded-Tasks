#include "Event_Based/inc/Event_Based.h"

Queue My_Queue;
Queue_Entry Data=0;
uint8 Push_Botton_value=0;
uint8 Push_Botton_Flag=1;
uint8 volatile modified=0; // mutex



void Timer_Handler(void)
{
	SSD1306_DisplayString("tIMER", 0, 0);

}

void EXTI0_Handler(void)
{
	SSD1306_DisplayString("EXTI",10, 0);

}

Queue_Entry Queue_Return;
typedef void(*Ptr2Func)(void);
Ptr2Func Queue_Handlers[EVENT_COUNT]= {
		                                  Timer_Handler,
		                                  EXTI0_Handler
                                      };



void ExtEventBased(void)
{
	if(!Queue_Full(&My_Queue))
	{
		while(modified);
		modified=1;
		Queue_Append(&My_Queue,EXT_EVENT);
		modified=0;
	}
	else
	{
	 // do nothing
	}
}
void TimerEventBased(void)
{
	static uint8 Loc_Counter=0;
	Loc_Counter++;
	if(Loc_Counter==6) //120 >> 1sec   12 >> 100ms
	{
		if(!Queue_Full(&My_Queue))
		{
			DIO_GetPinVal(DIO_PORTD, DIO_Pin7,&Push_Botton_value);
			if(Push_Botton_value==0u && Push_Botton_Flag==1)
			{
				while(modified);
				modified=1;
				Push_Botton_Flag=0;
				Queue_Append(&My_Queue,TIMER_EVENT);
				modified=0;
			}
			else if(Push_Botton_value==1u && Push_Botton_Flag==0)
			{
				Push_Botton_Flag=1;
			}
		}
		else
		{
			// do nothing

		}
		Loc_Counter=0;
	}
	else
	{
		//do nothing
	}

}

void EB_voidInit(void)
{
	GIE_Enable();
	PORT_voidInit();
	TIMER0_voiSetCompareMatchValue(255);//timer0 will fire the interrupt every 500 ms
	Timer0_Timer0CTCCallBackFunc(&TimerEventBased);
	TIMER0_voidInit();
	EXTI_uint8Int0SetCallBack(&ExtEventBased);//ext will fire interrupt on change
	EXTI_voidInt0Init();
	SSD1306_Init();
	Queue_Creation(&My_Queue);


}


void EB_VoidRunnable(void)
{
	 if(Queue_not_empty==Queue_Empty(&My_Queue))
	 {
			while(modified);
			modified=1;
			Queue_Server(&My_Queue,&Queue_Return);
			modified=0;
			Queue_Handlers[Queue_Return]();

	 }
	 else
	 {
		 SSD1306_ClearDisplay();
	 }




}



