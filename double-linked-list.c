#include "double-linked-list.h"

#include <stdlib.h>

DoubleLinkedList* DoubleLinkedList_Create()
{
	DoubleLinkedList* list = malloc(sizeof(DoubleLinkedList));

	if (!list)
	{
		return 0;
	}

	list->head = 0;
	list->tail = 0;

	return list;
}

void DoubleLinkedList_Delete(DoubleLinkedList* list)
{
	if (!list || !list->head)
	{
		return;
	}

	DoubleLinkedListNode* next;

	do
	{
		next = list->head->next;
		free(list->head);
		list->head = next;
	} while (list->head);

	list->tail = 0;
}

void DoubleLinkedList_Foreach(DoubleLinkedList* list, void (*callback)(void* value))
{
	DoubleLinkedListNode* current = list->head;

	while (current)
	{
		callback(current->value);
		current = current->next;
	}
}

DoubleLinkedListNode* DoubleLinkedList_Add(DoubleLinkedList* list, void* value)
{
	DoubleLinkedListNode* node = malloc(sizeof(DoubleLinkedListNode));

	if (!node)
	{
		return 0;
	}

	node->next = 0;
	node->value = value;

	if (!list->tail)
	{
		list->head = list->tail = node;
		node->prev = 0;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = list->tail->next;

		if (!list->head->next)
		{
			list->head->next = list->tail;
		}
	}

	return node;
}

void* DoubleLinkedList_Remove(DoubleLinkedList* list)
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

	DoubleLinkedListNode* current = list->head;

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

DoubleLinkedListNode* DoubleLinkedList_InsertAt(DoubleLinkedListNode* target, void* value)
{
	DoubleLinkedListNode* node = malloc(sizeof(DoubleLinkedListNode));

	if (!node)
	{
		return 0;
	}

	node->next = target->next;
	node->prev = target;
	node->value = value;

	if (target->next)
	{
		target->next->prev = node;
	}

	target->next = node;
	return node;
}

int DoubleLinkedList_Count(DoubleLinkedList* list)
{
	int count = 0;
	DoubleLinkedListNode* current = list->head;

	while (current)
	{
		++count;
		current = current->next;
	}

	return count;
}
