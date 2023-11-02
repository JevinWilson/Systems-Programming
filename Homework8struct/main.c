#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6_util.h"

#define MAX_NAME_SIZE 100

int char_counts(const char* s, char c)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
            count++;
    }
    return count;
}

int extract_employee_data(const char* line, char* ename, int* eid, float* esalary)
{
    if (char_counts(line, ':') != 2)
        return 0;
    if (strlen(line) > 0 && line[0] == '#')
        return 0;

    char delim[2] = ":";
    char* token;

    // The first token should be the name
    token = strtok((char*)line, delim);
    if (token == NULL)
        return 0;
    strcpy(ename, token);

    // The second token should be the id
    token = strtok(NULL, delim);
    if (token == NULL)
        return 0;
    sscanf(token, "%d", eid);

    // The third (and final) token should be the salary
    token = strtok(NULL, delim);
    if (token == NULL)
        return 0;
    sscanf(token, "%f", esalary);

    return 1;
}

int get_datafile_size(const char* fname)
{
    FILE* fp = fopen(fname, "r");
    char one_line[MAX_NAME_SIZE + 64];
    int num_records = 0;

    // Read through the file, counting the number of valid entries
    while (!feof(fp))
    {
        fgets(one_line, MAX_NAME_SIZE + 63, fp);
        if (!feof(fp) && strlen(one_line) > 0 && one_line[0] != '#' && char_counts(one_line, ':') == 2)
            num_records++;
    }

    // Close the file
    fclose(fp);

    return num_records;
}

void read_datafile(const char* fname, char* enames, int * eids, float * esalaries)
{
    char one_line[MAX_NAME_SIZE + 64];

    FILE *fp = fopen(fname, "r");

    // Read through the array, this time, actually putting things into our arrays
    int num_lines = 0;
    while (!feof(fp))
    {
        // Get the line
        fgets(one_line, MAX_NAME_SIZE + 63, fp);
        if (!feof(fp))
        {
            int result = extract_employee_data(one_line, &enames[num_lines * MAX_NAME_SIZE], &eids[num_lines], &esalaries[num_lines]);
            if (result)
            {
                // I used this for testing
                //printf("Read line '%s' %d %f\n", &enames[num_lines * MAX_NAME_SIZE], eids[num_lines], esalaries[num_lines]);
                num_lines++;
            }
        }
    }

    fclose(fp);

}

int main()
{
    //make array to hold the employess
    struct Employee* employees = NULL;

    // Make the arrays that will hold our employee database
    char* employee_names = NULL;
    int* employee_ids = NULL;
    float* employee_salaries = NULL;

    // Read in the arrays
    const char* data_file_name = "sample_data.txt";         // This could have a path if it were stored somewhere else
                                                            // ex. "data/sample_data.txt".  The paths are relative to the
                                                            // working directory is the location of the cbp in code::blocks
    int num_records = get_datafile_size(data_file_name);
    printf("Disovered %d records in %s\n", num_records, data_file_name);

    // Allocate our arrays
    employee_names = (char*)malloc(sizeof(char) * MAX_NAME_SIZE * num_records);
    employee_ids = (int*)malloc(sizeof(int) * num_records);
    employee_salaries = (float*)malloc(sizeof(float) * num_records);

    // Actually read in from the data file
    read_datafile(data_file_name, employee_names, employee_ids, employee_salaries);

    // Use get_stats to get the stat information about salaries
    float min_salary, max_salary, avg_salary;
    get_stats(employee_salaries, num_records, &min_salary, &max_salary, &avg_salary);
    printf("Employee stats\n\tMin Salary: %f\n\tMax Salary: %f\n\tAvg Salary: %f\n", min_salary, max_salary, avg_salary);


    // Print out all values, with the special markings
    printf("XX                          Name ID     Salary\n");
    printf("== ============================= ====== ======\n");
    for (int i = 0; i < num_records; i++)
    {
        // Print the marking
        if (employee_salaries[i] == max_salary)
            printf(">>");
        else if (employee_salaries[i] == min_salary)
            printf("<<");
        else if (employee_salaries[i] > avg_salary)
            printf(" >");
        else if (employee_salaries[i] < avg_salary)
            printf(" <");
        else
            printf("  ");

        // Print the name.  Note the little trick here -- I'm using sprintf to build up format string!
        // Remember that %% just outputs a %
        char fmt_str[64];
        sprintf(fmt_str, "%%-%ds %%d $%%0.02f\n", MAX_NAME_SIZE);      // ex. "%-30s %d %f\n"
        printf(fmt_str, &employee_names[i * MAX_NAME_SIZE], employee_ids[i], employee_salaries[i]);

        int choice = 0;
        while (choice != 9)
        {
            //display the menu
            printf("\nMenu:\n");
            printf("1. List salaries\n");
            printf("2. add employess\n");
            printf("3. Modify a salary\n");
            printf("4. Delete a salary\n");
            printf("9. Quit\n");
            printf("Press a number: ");

            //get users choice
            scanf("%d, &choice");

            //functions for choice
        }
    }


    // Super-important: now that we're done, free up all dynamically allocated memory
    free(employee_names);
    free(employee_ids);
    free(employee_salaries);

    // Not necessary since we're at the end of this program, but this prevents accessing a dangling pointer
    employee_names = NULL;
    employee_ids = NULL;
    employee_salaries = NULL;
    return 0;
}
