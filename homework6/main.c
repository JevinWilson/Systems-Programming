#include "lab_util.h"

#define MIN_VALUE 1.0
#define MAX_VALUE 10.0

int main()
{
    //generates random int based off the time
    srand(time(NULL));

    //user changeable decimal precision
    int dec_precision;
    printf("Enter decimal precision: ");
    scanf("%d", &dec_precision);


    float random_value = rand_float(MIN_VALUE, MAX_VALUE, 2);
    printf("Random Value: %.*f\n", dec_precision, random_value);
    
    float data[] = {10.0, 1.0};
    int size = sizeof(data) / sizeof(data[0]);
    float average, minimum, maximum;
    get_stats(data, size, &average, &minimum, &maximum);
    printf("Average: %.*f\n", dec_precision, average);
    printf("Minimum: %.*f\n", dec_precision, minimum);
    printf("Maximum: %.*f\n",dec_precision, maximum);
    
    return 0;
}