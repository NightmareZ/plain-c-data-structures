#include "single-linked-list.h"

#include <stdlib.h>

SingleLinkedList* SingleLinkedList_Create()
{
	SingleLinkedList* list = malloc(sizeof(SingleLinkedList));

	if (!list)
	{
		return 0;
	}
	
	list->head = 0;
	list->tail = 0;

	return list;
}

void SingleLinkedList_Delete(SingleLinkedList* list)
{
	if (!list || !list->head)
	{
		return;
	}

	SingleLinkedListNode* next;

	do
	{
		next = list->head->next;
		free(list->head);
		list->head = next;
	} while (list->head);

	list->tail = 0;
}

void SingleLinkedList_Foreach(SingleLinkedList* list, void (*callback)(void* value))
{
	SingleLinkedListNode* current = list->head;

	while (current)
	{
		callback(current->value);
		current = current->next;
	}
}

SingleLinkedListNode* SingleLinkedList_Add(SingleLinkedList* list, void* value)
{
	SingleLinkedListNode* node = malloc(sizeof(SingleLinkedListNode));

	if (!node)
	{
		return 0;
	}

	node->next = 0;
	node->value = value;

	if (!list->tail)
	{
		list->head = list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = list->tail->next;

		if (!list->head->next)
		{
			list->tail;
		}
	}

	return node;
}

void* SingleLinkedList_Remove(SingleLinkedList* list)
{
	if (!list->tail || !list->head)
	{
		return 0;
	}

	void* value;

	if (!list->head->next)
	{
		value = list->head->value;
		free(list->head);
		list->head = 0;
		list->tail = 0;
		return value;
	}

	SingleLinkedListNode* current = list->head;

	while (current->next != list->tail)
	{
		current = current->next;
	}

	value = list->tail->value;
	free(list->tail);
	current->next = 0;
	list->tail = current;
	return value;
}

SingleLinkedListNode* SingleLinkedList_InsertAt(SingleLinkedListNode* target, void* value)
{
	SingleLinkedListNode* node = malloc(sizeof(SingleLinkedListNode));

	if (!node)
	{
		return 0;
	}

	node->next = target->next;
	node->value = value;
	target->next = node;
	return node;
}
