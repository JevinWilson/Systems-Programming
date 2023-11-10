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

void llist_append(LinkedList* list, const void* data)
{
    //allocate memory
    LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    //allocate memory for new node and copy it to it
    new_node -> data = malloc(list -> element_size);

    //copy to new node
    memcpy(new_node -> data, data, list -> element_size);
    
    //set the last pointer of the new node to null
    new_node -> next = NULL;

    //if list empty, set head to the new node
    if(list -> head == NULL)
    {
        list -> head = new_node;
    }
    else
    {
        //have list find the last node
        LinkedListNode* current = list -> head;
        while (current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = new_node;
    }
    list -> size++;
}

void llist_insert(LinkedList* list, size_t index, const void* data)
{
    //allocate memory for the new node
    LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    //allocate memory for new node
    new_node -> data = malloc(list -> element_size);

    //copy data to new memory
    memcpy(new_node -> data, data, list -> element_size);

    //set pointer of new node to null, its a standalone node
    new_node -> next = NULL;

    //insert at the beggining
    if (index == 0)
    {
        new_node -> next = list -> head;
        list -> head = new_node;
    }
    else
    {
        //search to find node before specified index
        LinkedListNode* current = list -> head;
        for (size_t i = 0; i < index -1; i++)
        {
            current = current -> next;
        }

        //insert new node in to list
        new_node -> next = current -> next;
        current -> next = new_node;
    }
    //increase size of list
    list -> size++;
}

size_t llist_size(const LinkedList* list)
{
    if (list == NULL);
    {
        return 0;
    }
    //return the size of the list if its not 0
    return list -> size;
}

