#include "Event_Based/inc/Event_Based.h"

Queue My_Queue;
Queue_Entry Data=0;

void ExtEventBased(void)
{
	if(!Queue_Full(&My_Queue))
	{
		Queue_Append(&My_Queue,EXT_EVENT);
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
	if(Loc_Counter==120) //500 ms
	{
		if(!Queue_Full(&My_Queue))
		{
		Queue_Append(&My_Queue,TIMER_EVENT);
		}
		else
		{
			// do nothing

		}
		Loc_Counter=0;
	}

}

void EB_voidInit(void)
{
	GIE_Enable();
	PORT_voidInit();
	//timer0 will fire the interrupt every 500 ms
	TIMER0_voiSetCompareMatchValue(255);
	Timer0_Timer0CTCCallBackFunc(&TimerEventBased);
	TIMER0_voidInit();
	//ext will fire interrupt on change
	EXTI_uint8Int0SetCallBack(&ExtEventBased);
	EXTI_voidInt0Init();
	SSD1306_Init();
	Queue_Creation(&My_Queue);


}
void EB_VoidRunnable(void)
{
	// TraverseQueue(&My_Queue,queue_display);
	 SSD1306_DisplayNumber(My_Queue.Queue_Size,0, 0);

	if(Queue_empty==Queue_Empty(&My_Queue))
	{
		 SSD1306_DisplayChar('c',100,100);

	}
	else
	{
		Queue_Server(&My_Queue,&Data);
			switch(Data)
			{
				case EXT_EVENT :
				{
					 SSD1306_DisplayChar('a',100,100);
					 break;
				}
				case TIMER_EVENT :
				{
					 SSD1306_DisplayChar('b',100,100);
					 break;
				}
				default:
					break;
			}


	}


}



