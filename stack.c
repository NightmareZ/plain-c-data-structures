#include "stack.h"

Stack* Stack_Create()
{
	Stack* stack = malloc(sizeof(Stack));

	if (!stack)
	{
		return 0;
	}

	stack->list = DoubleLinkedList_Create();

	if (!stack->list) {
		free(stack);
		return 0;
	}

	return stack;
}

void Stack_Delete(Stack* stack)
{
	DoubleLinkedList_Delete(stack->list);
	free(stack);
}

void Stack_Push(Stack* stack, void* value)
{
	DoubleLinkedList_Add(stack->list, value);
}

void* Stack_Pop(Stack* stack)
{
	return DoubleLinkedList_Remove(stack->list);
}

void* Stack_Count(Stack* stack)
{
	return DoubleLinkedList_Count(stack->list);
}