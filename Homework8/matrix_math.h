#ifndef matrix_math
#define matrix_math

#include <stdio.h>
#include <stdlib.h>

// Typedef and declare a Matrix struct
typedef struct {
    unsigned int rows;
    unsigned int columns;
    float** data;
} Matrix;

// Declare all the functions from matrix_math.c
Matrix matrix_create(unsigned int rows, unsigned int columns);
void matrix_destroy(Matrix* m);
void matrix_set_item(Matrix* m, unsigned int row, unsigned int column, float value);
float matrix_get_value(Matrix* m, unsigned int row, unsigned int column);
void matrix_set_values(Matrix* m, float* all_values);
void matrix_print(Matrix* m, FILE* outfile);
Matrix matrix_multiply(Matrix* a, Matrix* b);

#endif
