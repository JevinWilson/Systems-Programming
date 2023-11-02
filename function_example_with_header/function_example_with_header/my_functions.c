#include <math.h>

// This is the DEFINITION of the function
float distance(float first_x, float first_y, float second_x, float second_y)
{
	// Making a LOCAL variable (only exists in this function)
	//   (first_x, etc.) are LOCAL variables as well as parameters
	float a = first_x - second_x;
	float b = first_y - second_y;
	float c = sqrtf(powf(a, 2) + powf(b, 2));
	return c;
}