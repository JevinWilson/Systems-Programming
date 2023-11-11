#include "linked_list.h"

LinkedList* llist_create(size_t element_size)
{
    //create memory for linked list
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    if (list == NULL)
    {
        return NULL;
    }

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
    //can't append to an empty list
    if (list == NULL)
    {
        return;
    }

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
    //can't insert in an empty list
    if (list == NULL)
    {
        return;
    }

    //check if added is larger than index
    if (index > list -> size)
    {
        fprintf(stderr, "Can't add larger then the list");
        return;
    }

    //if index is equal to size call append
    if (index == list -> size)
    {
        llist_append(list, data);
        return;
    }

    //create memory for new list
    LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    if (new_node == NULL)
    {
        return;
    }

    //create memory for new node
    new_node -> data = malloc(list -> element_size);
    if (new_node -> data == NULL)
    {
        return;
    }

    //copy to new created memory 
    memcpy(new_node -> data, data, list -> element_size);

    //set pointer of new node to null
    new_node -> next = NULL;

    //if inserted at beginning update head
    if (index == 0)
    {
        new_node -> next = list -> head;
        list -> head = new_node;
    }
    else
    {
        //search list to find node before said index
        LinkedListNode* current = list -> head;
        for (size_t i = 0; i < index -1; ++i)
        {
            current = current -> next;
        }
        //insert node into list
        new_node -> next = current -> next;
        current -> next = new_node;
    }
    //increase size of list
    list -> size++;
}

void llist_remove(LinkedList* list, size_t index)
{
    //can't remove from a null list
    if (list == NULL)
    {
        printf(stderr, "Can't remove from a NULL list");
        return;
    }

    //update head if removed
    if (index ==0)
    {
        LinkedListNode* temp = list -> head;
        list -> head = list -> head -> next;

        //free mem allocated for data
        free(temp -> data);
        //free mem allocated for node
        free(temp);
    }

    else
    {
        //search list to find node befor said index
        LinkedListNode* current = list -> head;
        for (size_t i = 0; i < index - 1; ++i)
        {
            //remove node from list
            LinkedListNode* temp = current -> next; 
            current -> next = temp -> next;

            //free memory
            free(temp -> data);
            free(temp);
        }
        //decrease size of list
        list -> size--;
    }
}

void llist_iterate(const LinkedList* list, int (*func)(const LinkedListNode*))
{
    //cant iterate over a null list
    if (list == NULL)
    {
        return;
    }

    //iterate over each node
    LinkedListNode* current = list -> head;
    while (current != NULL)
    {
        //add user supplied function to current node
        int result = func(current);
        if (result == 0)
        {
            //if 0 stop immediatly
            break;
        }
        //move to next node
        current = current -> next;
    }
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

size_t llist_total_size(const LinkedList* list)
{
    if (list == NULL)
    {
        return 0;
    }
    size_t total_size = 0;

    //size of list structure
    total_size += sizeof(LinkedList);

    //size of each node x number of nodes
    total_size += list -> size * sizeof(LinkedListNode);

    //size of data stored in each node x number of nodes
    LinkedListNode* current = list -> head;

    while (current != NULL)
    {
        total_size += list -> element_size;
        current = current -> next;
    }
    return total_size;
}