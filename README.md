# Plain C Data Structures #

## Single Linked List ##

 Create and delete list object:
 ```
 SingleLinkedList* list = SingleLinkedList_Create();
 SingleLinkedList_Delete(list);
 ```
 
Add and remove element to/from list tail:
```
SingleLinkedList_Add(list, &a);
SingleLinkedList_Remove(list);
```

Iterate by list:
```
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
```
SingleLinkedList_Add(list, (int*)malloc(sizeof(int)));
SingleLinkedList_Foreach(list, free);
```
