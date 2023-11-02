#include "lab6_util.h"
#include <stdlib.h>
#include <math.h>       // for NAN

float rand_float_p(float min_value, float max_value, float precision)
{
    if (min_value > max_value)
    {
        float temp = min_value;
        min_value = max_value;
        max_value = temp;
    }
    float range = (max_value - min_value) / precision;
    int num = rand() % (int)range;
    return num * precision + min_value;
}



float rand_float(float min_value, float max_value)
{
    return rand_float_p(min_value, max_value, 0.001f);
}




void get_stats(const float* flist, unsigned int flist_size, float* min_value, float* max_value, float* avg_value)
{
    if (flist_size == 0)
    {
        // We can't really come up with a good min/max/avg value!
        *min_value = *max_value = *avg_value = NAN;
    }
    else
    {
        // we *could* set our initial min and max value at some really large / small value, but a better
        // practice (imo) is to set it to the first value so we know we're not incorrectly picking
        // a starting min/max value that doesn't appear in the list.
        *min_value = *max_value = flist[0];
        float total = flist[0];
        for (unsigned int i = 1; i < flist_size; i++)
        {
            if (flist[i] < *min_value)
                *min_value = flist[i];
            if (flist[i] > *max_value)
                *max_value = flist[i];
            total += flist[i];
        }

        *avg_value = total / flist_size;
    }
}
