#include <stdio.h>

int g = 42;

void func(int c, float d, int* e)
{
    //printf("the memory address of 'c' is %p", &c);
    //printf("Value of 'c': %d\n", c);
    //printf("the memory address of 'd' is %p", &d);
    //printf("the value of 'd': %f\n", d);
    int f = (int)(d + c);
    //printf("the memory address of 'f' is %p", &f);
    //printf("Value of 'f': %d\n", f);
    *e = f + g;
    //printf("the memory address of 'e' is %p", &e);
    //printf("the value of '*e': %d\n", *e);
    //printf("the memory address of 'g' is %p", &g);
    //printf("Value of 'g': %d\n", g);



    // your memory map should be created at
    // this point (before the return)
    
}

int main(int argc, char**argv)
{
    int a = 10;
    //printf("the memory address of 'a' is %p", &a);
    //printf("Value of 'a': %d\n", a);
    const char* s = "Hello, World!";
    //printf("the memory address of 's' is %p", &s);
    //printf("Value of 's': %s\n", s);
    int *aptr = &a;   //points the memory location 'a'
    float b = 9.6f;
    //printf("the memory address of 'b' is %p", &b);
    //printf("Value of 'b': %f\n", b);

    func(a, b, aptr);
}