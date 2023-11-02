#include "Homework7.h"

int get_datafile_size(const char *filename) 
{
    //opens file in "r"ead mode
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        return 0;
    }

    int num_records = 0;
    char line[MAX_NAME_LENGTH]; 

    //continues to read lines till it reaches the end (null)
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        //checks for '#' to determine if the line has data/counts data containing lines~
        if (line[0] != '#' && strchr(line, ':') != NULL) 
        {
            num_records++;
        }
    }

    fclose(file);
    return num_records;
}

int read_datafile(const char *filename, char **names, int *ids, float *salaries) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        return 0;
    }
    //reads line up to the desired length
    char line[MAX_NAME_LENGTH]; 
    int record_index = 0;

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        //checks for data containing line
        if (line[0] != '#' && strchr(line, ':') != NULL) 
        {
            //stores name, id, and salary if found in data line
            if (extract_employee_data(line, names[record_index], &ids[record_index], &salaries[record_index])) 
            {
                record_index++;
            }
        }
    }

    fclose(file);
    return 1;
}

int extract_employee_data(const char *line, char *name, int *id, float *salary) 
{
    char *token;
    //copy line to avoid modifying the data
    char *copy = strdup(line);
    //split data by ":"
    token = strtok(copy, ":");

    if (token) 
    {
        //split copy
        strcpy(name, token);
        token = strtok(NULL, ":");
        if (token) 
        {
            //turn id# to int
            *id = atoi(token);
            token = strtok(NULL, ":");
            if (token) 
            {
                //turn salary to float
                *salary = atof(token);
                free(copy);
                return 1;
            }
        }
    }
    free(copy);
    return 0;
}

void get_stats(float *salaries, int num_records, float *min_salary, float *max_salary, float *average_salary) 
{
    *min_salary = *max_salary = *average_salary = salaries[0];

    for (int i = 1; i < num_records; i++) 
    {
        if (salaries[i] < *min_salary) 
        {
            *min_salary = salaries[i];
        } 
        else if (salaries[i] > *max_salary) 
        {
            *max_salary = salaries[i];
        }
        *average_salary += salaries[i];
    }

    *average_salary /= num_records;
}
