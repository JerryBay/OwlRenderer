#include <iostream>
#include "../Source/Core.h"
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

template<typename... Type>
void print(Type... args)
{
    (...,(std::cout << args << std::endl));
}

int main(int argc,const char** argv)
{
	print(1,2,3,4,5);
}