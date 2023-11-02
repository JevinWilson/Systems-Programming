#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

float rand_float(float min_value, float max_value, int precision);
void get_stats(const float* arr, int size, float* avg, float* min, float* max);