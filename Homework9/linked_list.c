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

void llist_destroy(LinkedList** list)
{
    if (*list == NULL)
    {
        return;
    }

    //free up for each node
    LinkedListNode* current = (*list)->head;
    LinkedListNode* next;

    while (current != NULL)
    {
        next = current -> next;
        //free memory allocated for node
        free(current -> data);
        free(current);

        current = next;
    }

    //free memory for LinkedList
    free(*list);

    //set pointer to null to show list is destroyed
    *list = NULL;
}