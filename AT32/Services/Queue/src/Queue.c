#include "Queue/inc/Queue.h"


void Queue_Creation(Queue* P2S_Queue)
{
	P2S_Queue->Queue_Size=NULL;
	P2S_Queue->Front=0;
	P2S_Queue->Rear=-1;
}
Queue_Status Queue_Empty(Queue* P2S_Queue)
{
	Queue_Status Local_queue;
	if(P2S_Queue->Queue_Size == 0)
	{
		Local_queue=Queue_empty;
	}
	else
	{
		Local_queue=Queue_not_empty;
	}

	return Local_queue;
}

Queue_Status Queue_Full(Queue* P2S_Queue)
{
	return (P2S_Queue->Queue_Size == Queue_MAX);
}
void Queue_Append(Queue* P2S_Queue,Queue_Entry Data)
{
	/* check the rear index circular queue*/
	P2S_Queue->Rear= ((P2S_Queue->Rear)+1)% Queue_MAX;
	P2S_Queue->Array[P2S_Queue->Rear]=Data;
	P2S_Queue->Queue_Size++;
}
void Queue_Server(Queue* P2S_Queue,Queue_Entry* Data)
{
	*Data=P2S_Queue->Array[P2S_Queue->Front];
	P2S_Queue->Front= ((P2S_Queue->Front) +1) % Queue_MAX ;
	P2S_Queue->Queue_Size--;
}
uint8 Queue_Size(Queue* P2S_Queue)
{
	return P2S_Queue->Queue_Size;
}

void Queue_Clear(Queue* P2S_Queue)
{

	P2S_Queue->Queue_Size=NULL;
	P2S_Queue->Rear=-1;
	P2S_Queue->Front=NULL;
}
void TraverseQueue(Queue* P2S_Queue, void (*P2F)(Queue_Entry))
{
	uint8 Local_Size=0;
	sint8 Pos;
	for(Pos=P2S_Queue->Front;Local_Size<P2S_Queue->Queue_Size;Local_Size++)
	{
		(*P2F)(P2S_Queue->Array[Pos]);
		Pos=(Pos+1)%Queue_MAX;

	}



}
