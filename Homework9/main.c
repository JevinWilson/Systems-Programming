#include "linked_list.h"

//print the floats
int print_float(const LinkedListNode* node)
{
    const float* data = (const float*)node -> data;
    //("%.1f, ", *data), outputs (x, y, z, )
    printf("%.1f", *data);

    //get rid of comma and space at the end
    if (node -> next != NULL)
    {
        printf(", ");
    }

    //continue iterating
    return 1;
}

int main()
{
    //create linked list of float
    LinkedList* floatList = llist_create(sizeof(float));

    //_append
    float data0 = 1.1;
    float data1 = 2.3;
    float data2 = 4.5;
    float data3 = 9.3;

    llist_append(floatList, &data0);
    llist_append(floatList, &data1);
    llist_append(floatList, &data2);
    llist_append(floatList, &data3);

    //use _iterate to print to the list
    printf("Original list: (");
    llist_iterate(floatList, print_float);
    printf(")\n");

    //_insert: inserts at index 2 and moves the rest up 1 index
    float insert = 9.9;
    llist_insert(floatList, 2, &insert);

    //appends when inserting is equal to the size of the list (comment out _append)
    /*
    float data0 = 9.8;
    llist_append(floatList, &data0);

    float insert = 9.9;
    llist_insert(floatList, 1, &insert);
    */

    //_remove: removes said index and adjust the list accordingly
    llist_remove(floatList, 3);
    /*
    //remove 1st index
    llist_remove(floatList, 0)
    //remove last index
    llist_remove(floatList, llist_size(floatList) - 1);
    */



    //test other llist functions
    size_t listSize = llist_size(floatList);
    size_t totalSize = (size_t)llist_total_size(floatList);

    printf("Size of list: %zu\n", listSize);
    printf("Total size of list: %zu bytes\n", totalSize);
    
    printf("New list: (");
    llist_iterate(floatList, print_float);
    printf(")\n");
    //destroy 
    llist_destroy(floatList);
    
    return 0;
}