#include "lab_util.h"

float rand_float(float min_value, float max_value, int precision)
{
    //generate rand int
    int rand_integer = rand(); 
    //Scale the random integer to a float within the desired range
    float scaled_value = ((float)rand_integer / RAND_MAX) * (max_value - min_value) + min_value; 
    float multiplier = 1.0;

    // Round the scaled value to the desired precision
    for (int i = 0; i < precision; i++) 
    {
        multiplier *= 10.0;
    }
    return roundf(scaled_value * multiplier) / multiplier;
}

void get_stats(const float* arr, int size, float* avg, float* min, float* max)
{
    if (size <= 0)
    {
        *avg = 0.0;
        *min = 0.0;
        *max = 0.0;
        return;
    }
    
    float sum = 0.0;
    *min = FLT_MAX;
    *max = -FLT_MAX;

    for (int i = 0; i < size; i++)
    {
        float current_value = arr[i];
        sum += current_value;
        if (current_value < *min)
        {
            *min = current_value;
        }
        if (current_value > *max)
        {
            *max = current_value;
        }
    }
    *avg = sum / size;
}