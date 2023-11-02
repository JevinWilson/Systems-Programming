#include <stdio.h>

int main(int argc, char**argv)
{
    int x = 42;
    unsigned short y = 73;
    char c = 'R';
    char d = 15;
    char e;
    char f = 027;
    
    unsigned char g = 0xF3;   //hex 128
    char h = 0xF3;

    x = 1734;
    e = 'R';

    //
    int length, width;


    printf("y = %d\n", y);
    printf("2y = %d\n", y * 2);
    printf("c (c as an interger) = %d\n", c);
    printf("c (as a character) = %c\n", c);
    printf("x (as a character) = %c\n", x);
    printf("f (as an integer) = %d\n", f);
    printf("g (as an integer) = %d\n", g);
    printf("h (as an integer) = %d\n", h);

    printf("input the length of a rectangle: ");
    scanf("%d", &length);
    printf("input the length of a width: ");
    scanf("%d", &width);
    printf("the area is = %d", length * width);
    
    

    return 0;
}