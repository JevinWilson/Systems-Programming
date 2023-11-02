#include <stdio.h>
#include <stdlib.h>
#define IS_WRITING 0
#define FNAME "data/d01.txt"
int main()
{
#if IS_WRITING
    // To open a file in write mode...
    FILE* fp = fopen(FNAME, "w");

    // Write some stuff
    fprintf(fp, "42 3.7\n");
    fprintf(fp, "19 1.1\n");
#else
    FILE* fp = fopen(FNAME, "r");
    //for (int i = 0; i < 2; i++)
    while (!feof(fp))
    {
        // To read the floats and ints...
        //int ival;
        //float fval;
        // Note: feof doesn't become true until
        // you try to read past the end of the file
        //fscanf(fp, "%d %f", &ival, &fval);
        //if (!feof(fp))
        //    printf("int=%d float=%f\n", ival, fval);

        // To read just a complete string...
        char temp_str[64];
        fgets(temp_str, 63, fp);
        temp_str[strlen(temp_str) - 1] = '\0';
        if (!feof(fp))
            printf("The line was '%s'\n", temp_str);
    }
#endif

    // When done, make sure to do this
    fclose(fp);
    return 0;
}