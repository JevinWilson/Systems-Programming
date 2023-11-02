//homework3: more c types

//1a) 3.5f + 4.1 = a float 
//1b) 'a' / 2 = a float b/c a is 97 in ascii and its div by 2
//1c) 97u + 3.0f / 0.5 = an int b/c it rounds down to the nearest whole number
//1d) 30u * 'f' = u b/c (30 * 102)
//1e) int x = 20.0 / 3.0: wouldn't output/store anything because it is incompatable with int

//2) if you have float a = 6.5 and unsigned b = 43,
//   if added it'll output an int 49 but if they were both
//   floats then it'll be 49.5

// question 3

//Step 3
#include "utility.h"

int get_integer(const char** prompt)
{
    printf("Input the time traveled: "); //ask for user input
    scanf("%f", &time); //reads user input
}

float get_float(const char* prompt)
{
    printf("input the distance traveled: "); //asks for distance
    scanf("%f", &speed); //reads user input
}