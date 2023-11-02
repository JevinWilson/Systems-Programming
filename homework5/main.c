#include <stdio.h>
#include "collatzH.h"
#include <time.h>

int main()
{
    long long int longest_sequence = 0;
    int maximum_length = 0;

    //time start
    clock_t start_time = clock();

    //set the range
    for (long long int i = 1; i <= 1000; i++)
    {
        //find the longest sequence
        int length = collatz_length(i);
        if (length > maximum_length)
        {
            maximum_length = length;
            longest_sequence = i;
        }
    }
    //time end
    clock_t end_time = clock();
    double time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Longest sequence: %lld\n", longest_sequence);
    collatz_print_sequence(longest_sequence);
    
    printf("Time elapsed: %2f seconds\n", time_elapsed);

    return 0;
}

//longest sequence: 670617279
//time elapsed: 460.91 seconds