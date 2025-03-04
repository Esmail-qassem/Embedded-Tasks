
#ifndef SERVICES_QUEUE_INC_QUEUE_H_
#define SERVICES_QUEUE_INC_QUEUE_H_

#include "STD_TYPES.h"


#define Queue_MAX 10
typedef  sint32  Queue_Entry;


typedef struct queue
{
	sint8 Front;
	sint8 Rear;
	uint8 Queue_Size;
	Queue_Entry Array[Queue_MAX];
}Queue;


typedef enum
{
	Queue_empty,
	Queue_full,
	Queue_not_empty,
}Queue_Status;

void Queue_Creation(Queue* P2S_Queue);
uint8 Queue_Size(Queue* P2S_Queue);
void Queue_Clear(Queue* P2S_Queue);
void TraverseQueue(Queue* P2S_Queue, void (*P2F)(Queue_Entry));
void Queue_Append(Queue* P2S_Queue,Queue_Entry Data);
void Queue_Server(Queue* P2S_Queue,Queue_Entry* Data);

Queue_Status Queue_Empty(Queue* P2S_Queue);
Queue_Status Queue_Full(Queue* P2S_Queue);

#endif /* SERVICES_QUEUE_INC_QUEUE_H_ */
