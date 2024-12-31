#include <stdlib.h>
#include "stdio.h"
#include "../../BSW/LIB/STD_TYPES.h"
#include "Stack.h"

uint8 static Stack_Full(Stack* My_Stack)
{
    return 0;
}
uint8 static Stack_Empty(Stack* My_Stack)
{
    return (My_Stack->top==NULL);
}

Status Stack_Creation(Stack* My_Stack)
{
    Status Local=E_NOT_OK;

    if(NULL==My_Stack)
    {
        //do nothing
    }
    else
    {
        My_Stack->Size=0;
        My_Stack->top=NULL;
         Local=E_OK;

    }
return Local;
}
Status Stack_Push(Stack* My_Stack,StackEntry Variable)
{
    Status Local=E_NOT_OK;
    StackNode * Local_Pointer=(StackNode*)malloc(sizeof(StackNode));

    if(NULL==My_Stack|| Stack_Full(My_Stack))
    {
        //do nothing
    }
    else
    {

        Local_Pointer->entry=Variable;
        Local_Pointer->Next=My_Stack->top;
        My_Stack->top=Local_Pointer;
        My_Stack->Size++;
        Local=E_OK;
    }
return Local;

}
Status Stack_Pop(Stack* My_Stack,StackEntry* Variable)
{
    StackNode* Local_Pointer= NULL;
    Status Local=E_NOT_OK;

    if(NULL==My_Stack || NULL == Variable|| Stack_Empty(My_Stack))
    {
        //do nothing
    }
    else
    {

        *Variable=My_Stack->top->entry;
        Local_Pointer= My_Stack->top;
        My_Stack->top=My_Stack->top->Next;
        free(Local_Pointer);
        My_Stack->Size--;
        Local=E_OK;
    }
return Local;
}

Status Stack_Display(Stack* My_Stack) {
    Status Local = E_NOT_OK;
    StackNode* temp = NULL;
    if (NULL == My_Stack) {
        // Do nothing
    } else {
        temp = My_Stack->top;
        while (temp != NULL) {
            printf("Element address: %p, value: %d\n", (void*)temp->Next, temp->entry);
            temp = temp->Next;
        }
        Local = E_OK;
    }
    return Local;
}
Status Clear_Stack(Stack* My_Stack)
{
    Status Local = E_NOT_OK;
    StackNode* Local_pointer = NULL;

   Local_pointer=My_Stack->top;
    if (NULL == My_Stack)
    {
        // Do nothing
    }
    else
    {
        while(Local_pointer)
        {
           Local_pointer= Local_pointer->Next;
            free(My_Stack->top);
            My_Stack->top=Local_pointer;
        }
        My_Stack->Size=0;
        Local = E_OK;
    }
    return Local;
}
Status Stack_Size(Stack* My_Stack,StackEntry* Variable)
{
     Status Local = E_NOT_OK;

    if (NULL == My_Stack)
    {
        // Do nothing
    }
    else
    {
        *Variable  =My_Stack->Size;
         Local = E_OK;
    }
    return Local;
}
