#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    //size of the list
    size_t element_size;
    //point to the first node of the list
    struct LinkedListNode* head;
    //number of elements in the list
    size_t size;
} LinkedList;

typedef struct LinkedListNode
{
    //point to whats stored in the node
    void* data;
    //move to the next node
    struct LinkedListNode* next;
} LinkedListNode;

LinkedList* llist_create(size_t element_size);

