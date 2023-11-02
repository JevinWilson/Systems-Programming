#include "Homework7.h"

int main() 
{
    const char *filename = "sample_data.txt";
    int num_records = get_datafile_size(filename);

    if (num_records <= 0) 
    {
        printf("Error: The file is empty or does not exist.\n");
        return 1;
    }

    printf("Number of data-containing lines: %d\n", num_records);

    //create memory for names, ids, and salary
    char **names = (char **)malloc(num_records * sizeof(char *));
    int *ids = (int *)malloc(num_records * sizeof(int));
    float *salaries = (float *)malloc(num_records * sizeof(float));

    if (!names || !ids || !salaries) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_records; i++) 
    {
        names[i] = (char *)malloc(MAX_NAME_LENGTH + 1);
    }

    int opened = read_datafile(filename, names, ids, salaries);

    if (opened) 
    {
        float min_salary, max_salary, average_salary;
        get_stats(salaries, num_records, &min_salary, &max_salary, &average_salary);

        //add 
        printf("%-30s  %10s\n", "Name", "Salary");
        for (int i = 0; i < num_records; i++) 
        {
            char symbol = ' ';
            if (salaries[i] < average_salary) 
            {
                symbol = '<';
            } 
            else if (salaries[i] > average_salary) 
            {
                symbol = '>';
            }
            printf("%c%-30s  %10.2f\n", symbol, names[i], salaries[i]);
        }

        printf("Min Salary: %.2f\n", min_salary);
        printf("Max Salary: %.2f\n", max_salary);
        printf("Average Salary: %.2f\n", average_salary);
    }

    for (int i = 0; i < num_records; i++) 
    {
        free(names[i]);
    }

    free(names);
    free(ids);
    free(salaries);

    return 0;
}