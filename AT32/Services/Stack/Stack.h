#ifndef STACK_H_
#define STACK_H_

#define MAX_SIZE 5

typedef uint32 StackEnery ;

typedef struct stacknode
{

struct stacknode * Next;
StackEnery entry;

}StackNode;

typedef struct stack
{
    StackNode * top;
    uint32 Size;
}Stack;

typedef enum
{
    E_NOT_OK,
    E_OK,
}Status;


Status Stack_Creation(Stack* My_Stack);
Status Stack_Push(Stack* My_Stack,StackEnery Variable);
Status Stack_Pop(Stack* My_Stack,StackEnery* Variable);
Status Stack_Display(Stack* My_Stack);
Status Clear_Stack(Stack* My_Stack);
Status Stack_Size(Stack* My_Stack,StackEnery* Variable);





#endif