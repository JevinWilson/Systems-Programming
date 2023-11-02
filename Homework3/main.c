#include "utility.h"

//Step 2: ask for the input
int main(int argc, char**argv)
{
    int time, speed;  //declares the terms as the same varible

    time = get_float("input time: ");
    speed = get_integer("input speed: ");

    printf("the distance traveled is = %f", speed * time);
}