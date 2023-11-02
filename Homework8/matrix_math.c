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

//put the set value in the matrix
void matrix_set_item(Matrix* m, unsigned int row, unsigned int column, float value) 
{
    if (row < m->rows && column < m->columns) 
    {
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
void matrix_print(Matrix *m, FILE *outfile)
{
    //print output to txt file
    if(outfile == stdout) 
    {
        //if 1 row put in form [1 2 3]
        if(m->rows == 1) 
        {
            printf("[ ");

            // Print the values of the matrix
            for(int j = 0; j < m->columns; j++) 
            {
                printf("%.2f", m->data[0][j]);
            }
            printf(" ]\n");
        } 
        else 
        {
            for(int i = 0; i < m->rows; i++) 
            {
                if (i == 0) 
                {
                    //top left of matrix
                    printf("/");
                } 
                else if (i == m->rows - 1) 
                {
                    //bottom left of matrix
                    printf("\\");
                } 
                else 
                {
                    //middle of matrice bracket
                    printf("|");
                }
                for (int j = 0; j < m->columns; j++) 
                {
                    //prinnt value and format
                    printf("   %0.2f   ", m->data[i][j]);
                }
                if (i == 0) 
                {
                    //top right of matrix
                    printf("\\\n");
                } 
                else if (i == m->rows - 1) 
                {
                    //bottom right of matrix
                    printf("/\n");
                } else 
                {
                    //middle of matrice bracket
                    printf("|\n");
                }
            }
        }
    }
}

Matrix matrix_multiply(Matrix* a, Matrix* b) 
{
    //matrix operation is unable to be done if...
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
