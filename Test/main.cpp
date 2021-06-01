#include <iostream>
#include "../Include/Core.h"
using namespace std;
using namespace Math;


static double SumOfFloat(int count, ...)
{
	va_list ap;
	double sum{ 0.f };
	va_start(ap, count);
 
	for (int i = 0; i < count; ++i) {
		sum += va_arg(ap, double);
	}
 
	va_end(ap);
 
	return sum;
}

int main(int argc,const char** argv)
{
    Vec<3> v(1,2,3,4);
    cout<<v;
    cout<<SumOfFloat(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}