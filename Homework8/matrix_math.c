#include "matrix_math.h"

Matrix matrix_create(unsigned int rows, unsigned int columns) 
{
    Matrix m;
    m.rows = rows;
    m.columns = columns;
    //create memory for row
    m.data = (float**)malloc(rows * sizeof(float*));
    for (unsigned int i = 0; i < rows; i++) 
    {
        //create memory for the rows's column
        m.data[i] = (float*)malloc(columns * sizeof(float));
        for (unsigned int j = 0; j < columns; j++) 
        {
            //returns elements to 0
            m.data[i][j] = 0.0f;
        }
    }
    return m;
}

void matrix_destroy(Matrix* m) 
{
    for (unsigned int i = 0; i < m->rows; i++) 
    {
        //get rid of memory for each rows's column
        free(m->data[i]);
    }
    free(m->data);
    m->rows = 0;
    m->columns = 0;
    m->data = NULL;
}

void matrix_set_item(Matrix* m, unsigned int row, unsigned int column, float value) 
{
    if (row < m->rows && column < m->columns) 
    {
        //inputs the set value in the row/column
        m->data[row][column] = value;
    }
}

//returns the value
float matrix_get_value(Matrix* m, unsigned int row, unsigned int column) 
{
    if (row < m->rows && column < m->columns) 
    {
        return m->data[row][column];
    }
    //return this to show that it failed
    return -1.0f;
}

void matrix_set_values(Matrix* m, float* all_values) 
{
    unsigned int index = 0;
    for (unsigned int i = 0; i < m->rows; i++) 
    {
        for (unsigned int j = 0; j < m->columns; j++) 
        {
            //sets the value for an array
            matrix_set_item(m, i, j, all_values[index]);
            index++;
        }
    }
}

//print the braces for the matric
void matrix_print(Matrix* m, FILE* outfile) {
    for (unsigned int i = 0; i < m->rows; i++) {
        if (i == 0) {
            fprintf(outfile, "/");
        } else if (i == m->rows - 1) {
            fprintf(outfile, "\\");
        } else {
            fprintf(outfile, "|");
        }

        for (unsigned int j = 0; j < m->columns; j++) {
            fprintf(outfile, "%.6f", matrix_get_value(m, i, j)); // Print with 6 decimal places
            if (j < m->columns - 1) {
                fprintf(outfile, "     "); // Adjust the spacing between elements as needed
            }
        }

        if (i == m->rows - 1) {
            fprintf(outfile, "/");
        } else {
            fprintf(outfile, "|\n");
        }
    }
    fprintf(outfile, "\n");
}

Matrix matrix_multiply(Matrix* a, Matrix* b) 
{
    //matrix operation is unable to be done
    if (a->columns != b->rows) 
    {
        // Matrices are of incorrect shape to be multiplied
        Matrix invalid = {0, 0, NULL};
        return invalid;
    }

    Matrix result = matrix_create(a->rows, b->columns);
    //formula for matrix multiplication
    for (unsigned int i = 0; i < a->rows; i++) 
    {
        for (unsigned int j = 0; j < b->columns; j++) 
        {
            float sum = 0.0f;
            for (unsigned int k = 0; k < a->columns; k++) 
            {
                sum += matrix_get_value(a, i, k) * matrix_get_value(b, k, j);
            }
            matrix_set_item(&result, i, j, sum);
        }
    }

    return result;
}
