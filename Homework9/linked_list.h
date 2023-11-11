#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void llist_destroy(LinkedList** list);
void llist_append(LinkedList* list, const void* data);
void llist_insert(LinkedList* list, size_t index, const void* data);
void llist_remove(LinkedList* list, size_t index);
void llist_iterate(const LinkedList* list, int (*func)(const LinkedListNode*));
size_t llist_size(const LinkedList* list);
size_t llist_total_size(const LinkedList* list);