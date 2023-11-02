#include <stdio.h>

int main(int argc, char**argv)
{
    int length, width;  //declares the terms as the same varible

    printf("input the length of the rectangle: "); //ask for user input
    scanf("%d", &length); //reads the users input

    printf("input the width of the rectangle: "); //ask for the width of the rectangle
    scanf("%d", &width);  //reads the users input

    printf("the area is = %d", length * width); //gives the user the answer based on their input

}