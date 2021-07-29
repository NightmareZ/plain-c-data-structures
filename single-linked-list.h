#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include "single-linked-list-node.h"

typedef struct SingleLinkedList {
    struct SingleLinkedListNode* head;
    struct SingleLinkedListNode* tail;
} SingleLinkedList;

extern SingleLinkedList* SingleLinkedList_Create();
extern void SingleLinkedList_Delete(SingleLinkedList*);

extern void SingleLinkedList_Foreach(SingleLinkedList*, void (*)(void*));

extern SingleLinkedListNode* SingleLinkedList_Add(SingleLinkedList*, void*);
extern void* SingleLinkedList_Remove(SingleLinkedList*);

#endif
