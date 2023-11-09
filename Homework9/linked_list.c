#include "linked_list.h"

LinkedList* llist_create(size_t element_size)
{
    //create memory for linked list
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    list -> element_size = element_size;
    //start the list at 0
    list -> head = NULL;
    //start the list empty
    list -> size = 0;

    return list;
}