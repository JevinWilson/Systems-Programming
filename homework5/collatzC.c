#include <stdio.h>
#include "collatzH.h"

int collatz_length(long long int number)
{
    int count = 0;
    while (number != 1)
    {
        //even
        if (number % 2 == 0) //if div by 2 and there is a 0 remainder
        {
            number /= 2;
        }
        //odd
        else
        {
            number = 3 * number + 1;
        }
        count++;
    }
    return count;
}

void collatz_print_sequence(long long int number)
{
    printf("(%lld: ", number);
    while (number != 1)
    {
        printf("%lld -> ", number);
        if (number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number = 3 * number + 1;
        }
    }
    printf("1)\n");
}

