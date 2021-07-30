#ifndef STACK
#define STACK

#include "double-linked-list.h"

typedef struct Stack {
    struct DoubleLinkedList* list;
} Stack;

extern Stack* Stack_Create();
extern void Stack_Delete(Stack*);

extern void Stack_Push(Stack*, void*);
extern void* Stack_Pop(Stack*);

extern void* Stack_Count(Stack*);

#endif