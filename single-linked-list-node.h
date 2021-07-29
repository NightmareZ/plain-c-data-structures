#ifndef SINGLE_LINKED_LIST_NODE
#define SINGLE_LINKED_LIST_NODE

typedef struct SingleLinkedListNode {
    void* value;
    struct SingleLinkedListNode* next;
} SingleLinkedListNode;

#endif
