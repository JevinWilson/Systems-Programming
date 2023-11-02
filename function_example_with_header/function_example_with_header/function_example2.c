#include "my_functions.h"


int main(int argc, char** argv)
{
	// Point 1
	float x1 = 0.8f;
	float y1 = 1.1f;
	
	// Point 2
	float x2 = 1.6f;
	float y2 = 0.9f;
	
	float hypotenuse = distance(x1, y1, x2, y2);
	printf("The hypotenuse = %f\n", hypotenuse);
	
	// This is an error because the variable c is undefined here (in this
	//    SCOPE)
	//printf("c = %f\n", c);
	
	// Another SCOPE rule with if statements
	//if (x1 < 1.5f)
	//{
	//	int nope = 42;		// This variable only exists in the SCOPE of this
						//  if block (not outside)
	//}
	//printf("nope = %d\n", nope);
	
	return 0;
}