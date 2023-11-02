#ifndef readFile
#define readFile
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int get_datafile_size(const char *filename);
int read_datafile(const char *filename, char **names, int *ids, float *salaries);
int extract_employee_data(const char *line, char *name, int *id, float *salary);
void get_stats(float *salaries, int num_records, float *min_salary, float *max_salary, float *average_salary);

#endif