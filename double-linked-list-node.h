#ifndef DOUBLE_LINKED_LIST_NODE
#define DOUBLE_LINKED_LIST_NODE

typedef struct DoubleLinkedListNode {
    void* value;
    struct DoubleLinkedListNode* next;
    struct DoubleLinkedListNode* prev;
} DoubleLinkedListNode;

#endif