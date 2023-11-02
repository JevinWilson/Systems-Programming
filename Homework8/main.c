#include "matrix_math.h"

int main() 
{
    Matrix A = matrix_create(3, 4);
    // Initialize matrix A with values
    float values_A[] = {5, -3, 8, 1, 2, -1, 5, 4, 0, 9, 3, -2};
    matrix_set_values(&A, values_A);

    Matrix B = matrix_create(4, 2);
    // Initialize matrix B with values
    float values_B[] = {8, 7, -3, 2, 6, 3, 0, -5};
    matrix_set_values(&B, values_B);

    Matrix C = matrix_multiply(&A, &B);
    Matrix D = matrix_multiply(&B, &A);

    printf("A =\n");
    matrix_print(&A, stdout);
    printf("\nB =\n"); // Add newline character here
    matrix_print(&B, stdout);
    printf("\nC =\n"); // Add newline character here
    matrix_print(&C, stdout);
    printf("\nD =\n"); // Add newline character here
    matrix_print(&D, stdout);

    //destroys
    matrix_destroy(&A);
    matrix_destroy(&B);
    matrix_destroy(&C);
    matrix_destroy(&D);

    return 0;
}
