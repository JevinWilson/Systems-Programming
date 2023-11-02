#ifndef LAB6_UTIL_H_INCLUDED
#define LAB6_UTIL_H_INCLUDED

// Note: C doesn't have default parameters.  In C++ (and many other languages we can do this):
// float rand_float(float min_value, float max_value, float precision = 0.001);
// and then the user can pass a 3rd argument if they wish (but if they don't, 0.001
// will be used)
// The work-around is to define two functions, one with the parameter required
// and another that calls the first, passing the default value.  In languages
// that support "function overloading" (like C++), you could name these functions
// the same as long as they have different parameters.  In C, though, we can't do that.

/**
 * this function returns a random float between the given min and max values, to some
 * level of precision.  If min and max values are reversed, they are silently swapped.
 *
 * @param min_value: the minimum value
 * @param max_value: the maximum value
 * @param precision: should be a decimal number (0.1 if you want tenth's place in your
 *                                                floats, 0.01 for hundredths, etc.)
 */
float rand_float_p(float min_value, float max_value, float precision);

/**
 * this function returns a random float between the given min and max values, with
 * thousands' place precision (1.432 for example).  If min and max values are
 * reversed they are silently swapped
 */
float rand_float(float min_value, float max_value);

/**
 * this function computes are returns (by pointer) the minimum and maximum and average value
 * of the floats in the given list.  If flist_size is 0, NaN is "returned" for all values.
 * @param flist: should be a pointer to an array of floats of size flist_size
 * @param flist_size: the number of elements in flist
 * @param min_value: will be modified to hold the smallest value in flist (or NaN if flist_size is 0)
 * @param max_value: will be modified to hold the largest value in flist (or NaN if flist_size is 0)
 * @param avg_value: will be modified to hold the average (mean) of all values in flist (or NaN if flist_size is 0)
*/
void get_stats(const float* flist, unsigned int flist_size, float* min_value, float* max_value, float* avg_value);


#endif // LAB6_UTIL_H_INCLUDED
