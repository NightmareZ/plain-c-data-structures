#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include "double-linked-list-node.h"

typedef struct DoubleLinkedList {
    struct DoubleLinkedListNode* head;
    struct DoubleLinkedListNode* tail;
} DoubleLinkedList;

extern DoubleLinkedList* DoubleLinkedList_Create();
extern void DoubleLinkedList_Delete(DoubleLinkedList*);

extern void DoubleLinkedList_Foreach(DoubleLinkedList*, void (*)(void*));

extern DoubleLinkedListNode* DoubleLinkedList_Add(DoubleLinkedList*, void*);
extern void* DoubleLinkedList_Remove(DoubleLinkedList*);

extern DoubleLinkedListNode* DoubleLinkedList_InsertAt(DoubleLinkedListNode*, void*);

extern int DoubleLinkedList_Count(DoubleLinkedList*);

#endif