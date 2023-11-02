// Goal -- make what appears to be a dynamic list of
// floats and a menu to add/remove/list all elements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu()
{
    printf("1. List all values\n");
    printf("2. Append a value\n");
    printf("3. Insert a value\n");
    printf("4. Remove a value\n");
    printf("5. Clear the list\n");
    printf("9. Quit\n");
}

int main()
{
    float* L = NULL;        // This will be an array
                            // of floats (after we add our
                            // first item)
    unsigned int L_size = 0;// Number of things CURRENTLY in L
    unsigned int L_capacity = 0;    // Space we have in the
                            //  array (each time we "grow", grow
                            //  by 5 elements)
    char user_input[3];     // space for a character, a newline, and null-char

    int done = 0;

    while (!done)
    {
        show_menu();
        // Get the response from the user
        printf(">> ");
        fgets(user_input, 3, stdin);

        user_input[1] = '\0';
        switch (user_input[0])
        {
        case '1':
            // List
            printf("LIST\n");
            for (unsigned int i = 0; i < L_size; i++)
                printf("%d\t%f\n", i, L[i]);
            break;
        case '2':
            printf("APPEND\n");
            printf("Enter a value to append: ");
            float temp;
            scanf("%f", &temp);
            // Append
            // Three cases:
            if (L == NULL)
            {
                //   1. we have an empty list (L is NULL
                //     and L_capacity is 0)
                // List is unallocated -- initialize it
                //    to hold space for 5 things
                L = (float*)malloc(sizeof(float) * 5);
                L_capacity = 5;
                L[L_size++] = temp;  // This uses L_size as the
                            // index (0) and THEN increments it
            }
            else if (L_size < L_capacity)
            {
                //   2. we have an array with excess capacity
                L[L_size++] = temp; // L_size holds the current
                        // size (before adding) but it's also
                        // the next available spot (see why?)
            }
            else
            {
                //   3. we have a full array and must grow
                // GROW:
                printf("<GROW>\n");
                // ... make a bigger list
                float * temp_list = malloc(sizeof(float) * (L_capacity + 5));
                // ... copy over all items from current list to new
                memcpy(temp_list, L, sizeof(float) * L_capacity);
                // ... we're now done with the current list, so
                //    free it
                free(L);
                // ... make the bigger array THE array
                L = temp_list;
                L_capacity += 5;
                // (note: temp_list the VARIABLE goes away
                //   after we exit this block, but the address
                //   it held is now being held by L, so we're good)
                // ... Add the new element to the new bigger list
                L[L_size++] = temp;
            }

            break;
        case '3':
            // Insert
            printf("INSERT\n");
            // TODO:
            //1. Ask the user for a float value (just like append)
            //float temp; //may not be needed
            printf("Enter value: ");
            if (scanf("%f", &temp) != 1)
            {
                printf("Invalid input: ");
            }
            else      
                //2. Ask the user for a position (assume it will be between 0
                //     and L_size-1 -- you can, but don't have to check for this)
            {
                int insertIndex;
                printf("Enter the index you want to enter at: ", L_size);
                if (scanf("%d", &insertIndex) != 1)
                {
                    printf("Invalid input: ");
                }
                else
            
            //3. GROW, if needed (just as in append)
                {
                    if (L_size == L_capacity)
                    {
                        L_capacity += 5;
                        float *newL = malloc(sizeof(float) * L_capacity);
                        for(int i = 0; i < L_size; i++)
                        {
                            newL[i] = L[i];
                        }
                        free(L);
                        L = newL;
                    }
                
            //4. Shift elements after the insertion spot to make
            //     room for the new element.  For example, if
            //   L were currently holding [0.1, 0.2, 0.3, 0.4, 0.5]
            //     and the user entered 9.9 at index 2, you'd
            //  - grow (since we're at capacity)
            //  - move items at index 2...4 "up" one spot
            //  - put the 9.9 at index 2, producing this:
            //    [0.1, 0.2, 9.9, 0.3, 0.4, 0.5, -, -, -, -]
                    for (int i = L_size; i > insertIndex; i--)
                    {
                        L[i] = L[i - 1];
                    }
                    L[insertIndex] = temp;
                    L_size++;
                }
            }    
            break;
        case '4':
            // Remove
            printf("REMOVE\n");
            //TODO
            //1. Ask the user for an index (you can assume this will be 0...L_size-1)
            int removeIndex;
            printf("Enter the index to remove: ", L_size - 1);
            if (scanf("%d", &removeIndex) != 1 || removeIndex < 0 || removeIndex >= L_size)
            {
                printf("Enter a valid index\n");
            }

            //2. Remove that item from the list by shifting everything over one
            //   place.
            else
            {
                for (int i = removeIndex; i < L_size - 1; i++)
                {
                    L[i] = L[i + 1];
                }
                
            
            //3. Decrement L_size
            //For example, if L is
            // [0.1, 0.2, 9.9, 0.3, 0.4, 0.5, -, -, -, -]
            //and the user enters 1, the list would now look like
            // [0.1, 9.9, 0.3, 0.4, 0.5, 0.5, -, -, -, -]
            //(note how I have 0.5 twice at the end -- you can set
            //it to 0.0 or something else, but there's no need since
            //the user won't SEE that value when they print everything!)
                L_size--;
            }
            break;
        case '5':
            // Clear
            // TODO: clear the list by setting it back to its initial state
            //    Don't forget something important before you do...
            printf("CLEAR\n");
            if (L)
            {
                free(L);
                L = NULL;
                L_size = 0;
                L_capacity = 0;
            }
            break;
        case '9':
            // Quit
            printf("QUIT\n");
            done = 1;
            break;
        default:
            printf("Unknown menu command '%c'\n", user_input[0]);
            break;
        }
    }


    // Free the actual list, if we have one
    if (L)          // is L not NULL
        free(L);


    return 0;
}