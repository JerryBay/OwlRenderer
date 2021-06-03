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

template<int n> struct vec {
    vec() = default;
    double & operator[](const int i)       { assert(i>=0 && i<n); return data[i]; }
    double   operator[](const int i) const { assert(i>=0 && i<n); return data[i]; }
    double norm2() const { return (*this)*(*this) ; }
    double norm()  const { return std::sqrt(norm2()); }
    double data[n] = {0};
};

template<int n> vec<n> operator*(const double& rhs, const vec<n> &lhs) {
    vec<n> ret = lhs;
    for (int i=n; i--; ret[i]*=rhs);
    return ret;
}

int main(int argc,const char** argv)
{

	// double nums[4]={1,2,3,4};
	// Vector3 v3(nums);
	// // Vector3 v31(nums+1);
	// // Vector2 v2(nums);
	// // Vector2 v21(nums+1);
	// cout<<v3[3]<<endl;

	Mat<3,3> m=Mat<3,3>::Identity();
	cout<<m+m;
}