#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lab6_util.h"

// You weren't required to make a function for this part.  I wanted
// to show you that you don't HAVE to make functions in another file
// (I've been having you do this because it's often a good idea from
//  an organizational standpoint)
void output_ascii_stats(const char* input_str)
{
    int counts[256];
    memset(counts, 0, sizeof(int) * 256);       // this is faster than this...
    // for (int i = 0; i < 256; i++)
    //    counts[i] = 0;
    // ...and less typing than putting 256 initializers on line 13 like this
    // int counts[256] = {0, 0, 0, 0, 0, 0};    // 256 of these!

    // Get the counts
    for (int i = 0; i < strlen(input_str); i++)
        counts[(int)input_str[i]]++;            // clever, huh?!? The int-cast isn't
                                                // technically necessary, but removes a warning

    // Output data for the non-zero entries
    printf("Char\tCode\tCount\n====\t====\t=====\n");
    for (int i = 0; i < 256; i++)
    {
        if (counts[i])                          // counts[i] != 0 is redundant!
            printf("'%c'\t%d\t%d\n", i, i, counts[i]);
    }
}

#define TESTING 1
#define MAX_STR_SIZE 400
#define MIN_VAL 1.5f
#define MAX_VAL 9.3f

int main()
{
    // Seed the random number generator (optional)
    srand(time(NULL));

    // Part1: the float stats
    float my_list[100];                                 // Note how I used 100 several places.  If you mis-type
                                                        //  one of these, we'd likely have problems.  Note how I
                                                        //  did it better in the second part of this lab

    printf("@@@@@@@@@@\n@ PART 1 @\n@@@@@@@@@@\n");
    printf("#\tValue\n=\t=====\n");
    for (int i = 0; i < 100; i++)
    {
        my_list[i] = rand_float(MIN_VAL, MAX_VAL);
        printf("%d\t%f\n", i, my_list[i]);
    }

    float my_list_min, my_list_max, my_list_avg;        // normally not initializing is bad, but
                                                        // since the function "fills" these in, not a problem
    get_stats(my_list, 100, &my_list_min, &my_list_max, &my_list_avg);
    printf("STATS\n=====\n");
    printf("\tMinimum: %f\n\tMaximum: %f\n\tAverage: %f\n\n", my_list_min, my_list_max, my_list_avg);



    printf("@@@@@@@@@@\n@ PART 2 @\n@@@@@@@@@@\n");
#if TESTING
    const char* s = "This is a really really long string I entered";
#else
    char s[MAX_STR_SIZE];
    printf("Enter a really long string (spaces are OK): ");
    fgets(s, MAX_STR_SIZE, stdin);
#endif // TESTING

    printf("The long string was %s\n", s);

    output_ascii_stats(s);

    printf("Hello world!\n");
    return 0;
}
