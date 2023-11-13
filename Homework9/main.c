#include "linked_list.h"

//print the floats
int print_float(const LinkedListNode* node)
{
    const float* data = (const float*)node -> data;
    printf("%.1f, ", *data);

    //continue iterating
    return 1;
}

int main()
{
    //create linked list of float
    LinkedList* floatList = llist_create(sizeof(float));

    //append floats
    float data0 = 1.1;
    float data1 = 2.3;
    float data2 = 4.5;
    float data3 = 9.3;

    llist_append(floatList, &data0);
    llist_append(floatList, &data1);
    llist_append(floatList, &data2);
    llist_append(floatList, &data3);

    //use _iterate to print to the list
    printf("(");
    llist_iterate(floatList, print_float);
    printf(")\n");

    //test other llist functions
    size_t listSize = llist_size(floatList);
    size_t totalSize = (size_t)llist_total_size(floatList);

    printf("Size of list: %zu\n", listSize);
    printf("Total size of list: %zu bytes\n", totalSize);

    //destroy 
    llist_destroy(floatList);
    
    return 0;
}