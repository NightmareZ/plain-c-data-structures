# Plain C Data Structures #

## Single Linked List ##

Create and delete list object:
```C
SingleLinkedList* list = SingleLinkedList_Create();
SingleLinkedList_Delete(list);
```
 
Add and remove element to/from list tail:
```C
SingleLinkedList_Add(list, &a);
SingleLinkedList_Remove(list);
```

Iterate by list:
```C
void callback(void* value)
{
    int integer = *((int*)value);
    printf("%d\r\n", integer);
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    SingleLinkedList* list = SingleLinkedList_Create();
    
    SingleLinkedList_Add(list, &a);
    SingleLinkedList_Add(list, &b);
    SingleLinkedList_Add(list, &c);
    
    SingleLinkedList_Foreach(list, callback);
    
    SingleLinkedList_Delete(list);
}
```

Allocate and free item:
```C
SingleLinkedList_Add(list, (int*)malloc(sizeof(int)));
SingleLinkedList_Foreach(list, free);
```

Insert item:
```C
int a = 1;
int b = 2;
int c = 3;

SingleLinkedList* list = SingleLinkedList_Create();
SingleLinkedListNode* node = SingleLinkedList_Add(list, &a);
SingleLinkedList_Add(list, &b);

SingleLinkedList_InsertAt(node, &c); // result: 1, 3, 2
```

Elements count:
```C
SingleLinkedList_Count(list);
```

## Double Linked List ##

Create and delete list object:
```C
DoubleLinkedList* list = DoubleLinkedList_Create();
DoubleLinkedList_Delete(list);
```

Add and remove element to/from list tail:
```C
DoubleLinkedList_Add(list, &a);
DoubleLinkedList_Remove(list);
```

Iterate by list:
```C
DoubleLinkedList_Foreach(list, callback);
DoubleLinkedList_ForeachReverse(list, callback);
```

Elements count:
```C
DoubleLinkedList_Count(list);
```

## Stack ##

Create and delete stack objects:
```C
DoubleLinkedList* stack = Stack_Create();
Stack_Delete(stack);
```

Push and pop elements:
```C
int a = 1;
int b = 2;

Stack_Push(stack, &a);
Stack_Push(stack, &b);
int c = *((int*)Stack_Pop(stack));
```

Elements count:
```C
Stack_Count(stack);
```
